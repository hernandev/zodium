namespace Zodium\AEAD;

use Exception;
use Zodium\Helpers;

/**
 * Class AEAD.
 *
 * Generic AEAD cipher implementation.
 */
class Cipher
{
    /**
     * Current cipher name.
     */
    protected cipher;

    /**
     * Private key length.
     */
    protected keyLength;

    /**
     * Public nonce length.
     */
    protected nonceLength;

    /**
     * Encrypted MAC length.
     */
    protected macLength;

    /**
     * Available AEAD ciphers.
     */
    protected ciphers = [
        "AES256GCM",
        "CHACHA20POLY1305",
        "CHACHA20POLY1305_IETF",
        "XCHACHA20POLY1305_IETF"
    ];

    /**
     * @var null|string Base64 encoded secret key for encryption / decryption.
     */
    protected secretKey;

    /**
     * Cipher constructor.
     */
    public function __construct(string cipherName)
    {
        // check if the requested cipher is valid.
        if(!in_array(cipherName, this->ciphers)) {
            throw new Exception("Invalid cipher name.");
        }

        // assign the cipher name.
        let this->cipher = cipherName;

        // declare the current cipher key length in bytes.
        let this->keyLength = this->getSodiumConstant("KEYBYTES");
        // declare the current cipher public nonce length in bytes.
        let this->nonceLength = this->getSodiumConstant("NPUBBYTES");
        // declare the current cipher mac length in bytes.
        let this->macLength = this->getSodiumConstant("ABYTES");
    }

    /**
     * Scape a string to avoid injection, if at-all possible.
     */
    protected function escapeSymbol(string name)
    {
        // the Base64 decode is temporary, my IDE is not happing with the pattern.
        return preg_replace(Helpers::fromBase64("L1teQS1aYS16MC05XC1cX10v"), "", name);
    }

    /**
     * Wraps all constant lookup for the AEAD ciphers on libsodium.
     */
    protected function getSodiumConstant(string sodiumConstant)
    {
        // declare variables.
        var escapedCipher, escapedConstant;

        // escape values to avoid errors.
        let escapedCipher = this->escapeSymbol(this->cipher);
        let escapedConstant = this->escapeSymbol(sodiumConstant);

        // get the constant value.
        return constant(mb_strtoupper("SODIUM_CRYPTO_AEAD_".escapedCipher."_".escapedConstant));
    }

    /**
     * Proxy for the sodium encryption function.
     */
    protected function callSodiumEncrypt(string nonce64, string message, string ad = null) -> string
    {
        // declare variables.
        var escapedCipherName, nonce, key, functionName, cipherText;

        // decode the nonce and the encryption key from Base64.
        let nonce = Helpers::fromBase64(nonce64);
        let key = Helpers::fromBase64(this->secretKey);

        // escape the cipher name to avoid errors.
        let escapedCipherName = mb_strtolower(this->escapeSymbol(this->cipher));

        // determine the name of the function to be called.
        let functionName = "sodium_crypto_aead_".escapedCipherName."_encrypt";

        // call the function, passing the parameters.
        let cipherText = {functionName}(message, ad, nonce, key);

        // encode the cipherText and return to the parent function.
        return Helpers::toBase64(cipherText);
    }

    /**
     * Decryt an encrypt message / payload back to plain text.
     */
    protected function callSodiumDecrypt(string cipherText64, string nonce64, string ad = null)
    {
        // declare variables.
        var escapedCipherName, cipherText, nonce, key, functionName;

        // decode the parameters from Base64.
        let cipherText = Helpers::fromBase64(cipherText64);
        let nonce = Helpers::fromBase64(nonce64);
        let key = Helpers::fromBase64(this->secretKey);

        // escape the cipher name to avoid errors.
        let escapedCipherName = mb_strtolower(this->escapeSymbol(this->cipher));

        // find the function name.
        let functionName = "sodium_crypto_aead_".escapedCipherName."_decrypt";

        // call the function, using the decoded parameters.
        return {functionName}(cipherText, ad, nonce, key);
    }

    /**
     * Encrypt a given message.
     */
    public function encrypt(string message, string ad = null) -> array
    {
        // declare variables.
        var nonce, cipherText;

        // generate a base64 encoded nonce to be used for encryption.
        let nonce = this->generateNonce();

        // encrypt the message and store it's value on the cipher text.
        let cipherText = this->callSodiumEncrypt(nonce, message, ad);

        // return an array, with all values required to decrypt the cipher text
        // all values except the key of course.
        return ["ct": cipherText, "nonce": nonce, "ad": ad];
    }

    /**
     * Decript a message.
     */
    public function decrypt(string cipherText64, string nonce64, string ad)
    {
        // call the decryption proxy function.
        return this->callSodiumDecrypt(cipherText64, nonce64, ad);
    }

    /**
     * Returns a list of the available Ciphers.
     */
    public function getCiphers() -> array
    {
        return this->ciphers;
    }

    /**
     * Returns the current cipher
     */
    public function getCipher() -> string
    {
        return this->cipher;
    }

    /**
     * Returns the size in bytes, a key must have for the current cipher.
     */
    public function getKeyLength() -> int
    {
        return this->keyLength;
    }

    /**
     * Returns the size in bytes, a nonce must have for the current cipher.
     */
    public function getNonceLength() -> int
    {
        return this->nonceLength;
    }

    /**
     * Returns the size in bytes, a MAC must have for the current cipher.
     */
    public function getMacLength() -> int
    {
        return this->macLength;
    }

    /**
     * Generates a new secret key for encryption.
     * The key length will match the requirements of the current cipher.
     */
    public function generateSecretKey() -> string
    {
        return Helpers::randomBytes(this->keyLength);
    }

    /**
     * Generate a random nonce to be used when encrypting.
     */
    protected function generateNonce() -> string
    {
        return Helpers::randomBytes(this->nonceLength);
    }

    /**
     * Secret key setter.
     */
    public function setSecretKey(string encodedKey) -> <Cipher>
    {
        // declare variables.
        var rawKey;

        // decode the secret key from base 64.
        let rawKey = Helpers::fromBase64(encodedKey);

        // check the key length.
        if (mb_strlen(rawKey, "8bit") != this->keyLength) {
            throw new Exception("Invalid key size, keys must be ".this->keyLength." long.");
        }

        // set the Base64 encoded key on instance.
        let this->secretKey = encodedKey;

        // return the cipher instance for fluent setters.
        return this;
    }

    /**
     * Returns the current secret key on the cipher instance.
     */
    public function getSecretKey() -> string
    {
        return this->secretKey;
    }
}