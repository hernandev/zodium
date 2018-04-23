namespace Zodium\AEAD;

use Exception;
use Zodium\Helpers\Helpers;

/**
 * Class AEAD.
 *
 * Generic AEAD cipher implementation.
 */
class Cipher
{
    /**
     * @var string Current cipher name.
     */
    protected cipher;

    /**
     * @var int Private key length.
     */
    protected keyLength;

    /**
     * @bar int Public nonce length.
     */
    protected nonceLength;

    /**
     * @var int Encrypted MAC length.
     */
    protected macLength;

    /**
     * @var array Available AEAD ciphers.
     */
    protected ciphers = [
        "AES256GCM",
        "CHACHA20POLY1305",
        "CHACHA20POLY1305_IETF",
        "XCHACHA20POLY1305_IETF"
    ];

    /**
     * @var null|string Hexadecimal encoded secret key for encryption / decryption.
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
    protected function escapeSymbol(string name) -> string
    {
        // the pattern is Hexadecimal encoded to prevent Zephir syntax errors.
        return preg_replace(Helpers::fromHex("2f5b5e412d5a612d7a302d395c2d5c5f5d2f"), "", name);
    }

    /**
     * Wraps all constant lookup for the AEAD ciphers on libsodium.
     */
    protected function getSodiumConstant(string sodiumConstant) -> var | null
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
    protected function callSodiumEncrypt(string nonceHex, string message, string ad = null) -> var | bool
    {
        // declare variables.
        var escapedCipherName, nonce, key, functionName, ciphertext;

        // decode the nonce and the encryption key from Hexadecimal.
        let nonce = Helpers::fromHex(nonceHex);
        let key = Helpers::fromHex(this->secretKey);

        // escape the cipher name to avoid errors.
        let escapedCipherName = mb_strtolower(this->escapeSymbol(this->cipher));

        // determine the name of the function to be called.
        let functionName = "sodium_crypto_aead_".escapedCipherName."_encrypt";

        // call the function, passing the parameters.
        let ciphertext = {functionName}(message, ad, nonce, key);

        // encode the cipherText and return to the parent function.
        return Helpers::toHex(ciphertext);
    }

    /**
     * Decryt an encrypt message / payload back to plain text.
     */
    protected function callSodiumDecrypt(string ciphertextHex, string nonceHex, string ad = null) -> var | bool
    {
        // declare variables.
        var escapedCipherName, ciphertext, nonce, key, functionName;

        // decode the parameters from Hexadecimal.
        let ciphertext = Helpers::fromHex(ciphertextHex);
        let nonce = Helpers::fromHex(nonceHex);
        let key = Helpers::fromHex(this->secretKey);

        // escape the cipher name to avoid errors.
        let escapedCipherName = mb_strtolower(this->escapeSymbol(this->cipher));

        // find the function name.
        let functionName = "sodium_crypto_aead_".escapedCipherName."_decrypt";

        // call the function, using the decoded parameters.
        return {functionName}(ciphertext, ad, nonce, key);
    }

    /**
     * Encrypt a given message.
     */
    public function encrypt(string message, string ad = null) -> array
    {
        // declare variables.
        var nonceHex, ciphertext;

        // generate a Hexadecimal encoded nonce to be used for encryption.
        let nonceHex = this->generateNonce();

        // encrypt the message and store it's value on the cipher text.
        let ciphertext = this->callSodiumEncrypt(nonceHex, message, ad);

        // return an array, with all values required to decrypt the cipher text
        // all values except the key of course.
        return ["ciphertext": ciphertext, "nonce": nonceHex, "ad": ad];
    }

    /**
     * Decrypt a message.
     */
    public function decrypt(string ciphertextHex, string nonceHex, string ad) -> var | bool
    {
        // call the decryption proxy function.
        return this->callSodiumDecrypt(ciphertextHex, nonceHex, ad);
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
    public function setSecretKey(string keyHex) -> <Cipher>
    {
        // declare variables.
        var key;

        // decode the secret key from base 64.
        let key = Helpers::fromHex(keyHex);

        // check the key length.
        if (mb_strlen(key, "8bit") != this->keyLength) {
            throw new Exception("Invalid key size, keys must be ".this->keyLength." long.");
        }

        // set the Hexadecimal encoded key on instance.
        let this->secretKey = keyHex;

        // return the cipher instance for fluent setters.
        return this;
    }

    /**
     * Returns the current secret key (hex) on the cipher instance.
     */
    public function getSecretKey() -> string
    {
        return this->secretKey;
    }
}