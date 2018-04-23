namespace Zodium\SecretBox;

use Exception;
use Zodium\Helpers\Helpers;
use Zodium\Exceptions\DataException;

/**
 * Class EncryptedPayload.
 *
 * Carries a SecretBox encrypted payload data.
 */
class EncryptedPayload
{
    /**
     * @var string The ciphertext.
     */
    protected ciphertext;

    /**
     * @var string The nonce used for encryption.
     */
    protected nonce;

    /**
     * @var bool Scalar indicator.
     */
    protected scalar = true;

    /**
     * Cipher constructor.
     */
    public function __construct(string ciphertext, string nonce, bool scalar = true)
    {
        // assign the ciphertext.
        let this->ciphertext = ciphertext;
        // assign the nonce.
        let this->nonce = nonce;
        // assign the scalar / non-scalar indicator.
        let this->scalar = scalar;

        // check the key length.
        if (mb_strlen(this->nonce, "8bit") !== SecretBox::getNonceBytes()) {
            throw new Exception("The payload nonce is invalid");
        }
    }

    /**
     * Return the payload ciphertext.
     *
     * @return string
     */
    public function getCiphertext(bool encoded = true) -> string
    {
        return encoded ? Helpers::toHex(this->ciphertext) : this->ciphertext;
    }

    /**
     * Return the payload nonce.
     *
     * @return string
     */
    public function getNonce(bool encoded = true) -> string
    {
        return encoded ? Helpers::toHex(this->nonce) : this->nonce;
    }

    /**
     * Returns true or false, if the value is scalar or not.
     *
     * @return bool
     */
    public function isScalar() -> bool
    {
        return this->scalar;
    }

    /**
     * Encode a given payload for storage or transmission.
     *
     * @return string
     */
    public function encode() -> string
    {
        // declare variables.
        var payloadData, encoded;

        // generate a payload data array.
        let payloadData = [
            "ciphertext": this->getCiphertext(true),
            "nonce": this->getNonce(true),
            "scalar": this->scalar
        ];

        // try encoding as JSON.
        try {
            let encoded = json_encode(payloadData);
        } catch \Exception {
            throw new DataException("Error while encoding Payload.");
        }

        // returns the JSON encoded payload.
        return encoded;
    }

    /**
     * Decode a given payload int oa EncruptedPayload instance.
     *
     * @throws DataException
     *
     * @return EncryptedPayload
     */
    public static function decode(string encodedPayload) -> <EncryptedPayload>
    {
        // declare variables.
        var data, item;

        try {
            // decode the payload JSON into a payload data array.
            let data = json_decode(encodedPayload, true);
        } catch Exception {
            // throw exception if the payload was not decoded correctly.
            throw new DataException("Error decoding the encrypted payload.");
        }

        // verify all keys on the payload actually exists.
        for item in ["ciphertext", "nonce", "scalar"] {
            // check if all keys are in place.
            if (!array_key_exists(item, data)) {
                // throw an exception otherwise.
                throw new DataException("Payload is missing the " . item . " key.");
            }

            // reassign values, decoding from Hexadecimal, except the scalar key.
            let data[item] = item !== "scalar" ? Helpers::fromHex(data[item]) : data[item];
        }

        // return the encrypted payload instance after decoding.
        return new EncryptedPayload(data["ciphertext"], data["nonce"], data["scalar"]);
    }

    /**
     * Hide the internal values.
     *
     * @return array
     */
    public function __debugInfo() -> array
    {
        return [
            "ciphertext": "*******",
            "nonce": "*******"
        ];
    }

}