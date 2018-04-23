namespace Zodium\SecretBox;

use Exception;
use Zodium\Helpers\Helpers;
use Zodium\SecretBox\EncryptedPayload;

/**
 * Class SecretBox.
 *
 * OOP wrapper for libsodium SecretBox.
 */
class SecretBox
{
    /**
     * @var null|string Hexadecimal encoded secret key for encryption / decryption.
     */
    protected secretKey;

    /**
     * Cipher constructor.
     */
    public function __construct(string secretKeyHex)
    {
        // assign the secret key, decoded.
        let this->secretKey = Helpers::fromHex(secretKeyHex);

        // check the key length.
        if (mb_strlen(this->secretKey, "8bit") != static::getKeyBytes()) {
            throw new Exception("Invalid secret key, it must be ".static::getKeyBytes()." bytes.");
        }
    }

    /**
     * Encrypt a given message.
     *
     * @return null|EncryptedPayload
     */
    public function encrypt(message) -> <EncryptedPayload> | null
    {
        // declare variables.
        var nonce, ciphertext, prepared, scalar;

        // detect if is a scalar value.
        let scalar = is_scalar(message);

        // serialize when not scalar.
        let prepared = is_scalar(message) ? message : serialize(message);

        // generate a Hexadecimal encoded nonce to be used for encryption.
        let nonce = this->generateNonce(false);

        // encrypt the message and store it's value on the cipher text.
        let ciphertext = sodium_crypto_secretbox(prepared, nonce, this->secretKey);

        // return a new encrypted payload instance.
        return new EncryptedPayload(ciphertext, nonce, scalar);
    }

    /**
     * Decrypt a message.
     *
     * @return null|mixed
     */
    public function decrypt(<EncryptedPayload> encryptedPayload) -> var | bool
    {
        // declare variables.
        var ciphertext, nonce, prepared;

        // decode the hex ciphertext.
        let ciphertext = encryptedPayload->getCiphertext(false);
        // decode the nonce.
        let nonce = encryptedPayload->getNonce(false);

        // decrypt and obtain the deserialzied value.
        let prepared = sodium_crypto_secretbox_open(ciphertext, nonce, this->secretKey);

        // unserialize and return.
        return encryptedPayload->isScalar() ? prepared : unserialize(prepared);
    }

    /**
     * Generates a new secret key for encryption with the SecretBox.
     *
     * @return string
     */
    public static function generateSecretKey(bool encode = true) -> string
    {
        return Helpers::randomBytes(static::getKeyBytes(), encode);
    }

    /**
     * Generate a random nonce to be used when encrypting.
     *
     * @return string
     */
    protected static function generateNonce(bool encode = true) -> string
    {
        return Helpers::randomBytes(static::getNonceBytes(), encode);
    }

    /**
     * Returns the size in bytes, a key must have for the current cipher.
     *
     * @return int
     */
    public static function getKeyBytes() -> int
    {
        return SODIUM_CRYPTO_SECRETBOX_KEYBYTES;
    }

    /**
     * Returns the size in bytes, a nonce must have for the current cipher.
     *
     * @retun int
     */
    public static function getNonceBytes() -> int
    {
        return SODIUM_CRYPTO_SECRETBOX_NONCEBYTES;
    }

    /**
     * Returns the size in bytes, a MAC must have for the current cipher.
     *
     * @return int
     */
    public static function getMacBytes() -> int
    {
        return SODIUM_CRYPTO_SECRETBOX_MACBYTES;
    }

    /**
     * Hide the internal values.
     *
     * @return array
     */
    public function __debugInfo() -> array
    {
        return [
            "secretKey": "*******"
        ];
    }
}