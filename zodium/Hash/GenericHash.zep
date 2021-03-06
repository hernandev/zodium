namespace Zodium\Hash;

use Exception;
use Zodium\Helpers\Helpers;
use Zodium\Exceptions\HashException;

/**
 * Class GenericHash.
 *
 * Wrapper for the generichash of libsodium.
 */
class GenericHash
{
    /**
     * @var int Length of the output hash.
     */
    protected hashLength;

    /**
     * @var string State of a mult-part hash.
     */
    protected state = null;

    /**
     * @var string A key is not required, but it's supported.
     */
    protected hashKey;

    /**
     * Constructor.
     */
    public function __construct(string hashKeyHex = null, int hashLength = null)
    {
        // if a key was specified, assign and check.
        if (hashKeyHex) {
            let this->hashKey = Helpers::fromHex(hashKeyHex);
            this->checkHashKey();
        }

        // if a hash hashLength provided.
        if (hashLength) {
            // assign.
            let this->hashLength = hashLength;
            // check.
            this->checkHashLength();
        } else {
            // default value otherwise.
            let this->hashLength = SODIUM_CRYPTO_GENERICHASH_BYTES;
        }
    }

    /**
     * Start the multi-part hashing.
     */
    public function start() -> bool
    {
        // init the state.
        let this->state = sodium_crypto_generichash_init(this->hashKey);

        // return true if the stated was initialized.
        return this->state !== null;
    }

    /**
     * Add a message on a multi-part hashing.
     */
    public function add(string message) -> bool
    {
        // when the state was not started.
        if (!this->state) {
            // call it.
            this->start();
        }

        // add the message to the multi-part hash.
        return sodium_crypto_generichash_update(this->state, message);
    }

    /**
     * Generic hash, if no message was provided, it means closing the multi-part.
     */
    public function hash(message = null) -> string
    {
        // declare variables.
        var hash;

        // if there is a current multi-part state on the instance...
        if (this->state !== null) {
            // let the hash be the final call to the multi-part hashing.
            let hash = sodium_crypto_generichash_final(this->state, this->hashLength);
        } else {
            // otherwise just hash a simple message.
            let hash = sodium_crypto_generichash(message, this->hashKey, this->hashLength);
        }

        // finally return the hash, encoded as hex.
        return Helpers::toHex(hash);
    }

    /**
     * Check if a hash length is valid.
     */
    protected function checkHashLength()
    {
        // throw exception case too small.
        if (this->hashLength < SODIUM_CRYPTO_GENERICHASH_BYTES_MIN) {
            throw new HashException("Hashes must be at least " . SODIUM_CRYPTO_GENERICHASH_BYTES_MIN);
        }

        // throw exception case too big.
        if (this->hashLength > SODIUM_CRYPTO_GENERICHASH_BYTES_MAX) {
            throw new HashException("Hashes must be at most " . SODIUM_CRYPTO_GENERICHASH_BYTES_MAX);
        }
    }

    /**
     * Check for a hash key length.
     */
    protected function checkHashKey()
    {
        // declare variables.
        var length;

        // determine it's length.
        let length = mb_strlen(this->hashKey, "8bit");

        // throw an exception case too small.
        if (length < SODIUM_CRYPTO_GENERICHASH_KEYBYTES_MIN) {
            throw new HashException("Hash keys must be at least " . SODIUM_CRYPTO_GENERICHASH_KEYBYTES_MIN);
        }

        // throw an excrption case too big.
        if (length > SODIUM_CRYPTO_GENERICHASH_KEYBYTES_MAX) {
            throw new HashException("Hash keys must be at most " . SODIUM_CRYPTO_GENERICHASH_KEYBYTES_MAX);
        }
    }

    /**
     * Simple hash key generator.
     */
    public static function generateKey() -> string
    {
        return Helpers::randomBytes(SODIUM_CRYPTO_GENERICHASH_BYTES);
    }

    /**
     * Hide the internal values.
     *
     * @return array
     */
    public function __debugInfo() -> array
    {
        return [
            "hashKey": "*******",
            "state": "**"
        ];
    }
}