namespace Zodium\Helpers;

use Exception;
use Zodium\Helpers;
use Zodium\Exceptions\DataException;

/**
 * Class Helpers.
 *
 * Wrapper for all constant-type helpers of libsodium.
 */
class Helpers
{
    /**
     * Constant-type string comparison.
     *
     * @return bool
     */
    public static function compare(string a, string b) -> bool
    {
        // if equals zero, return true, otherwise false.
        return sodium_compare(a, b) === 0;
    }

    /**
     * Constant type memory comparison.abstract
     *
     * @return bool
     */
    public static function compareMemory(a, b) -> bool
    {
        return sodium_memcmp(a, b) === 0;
    }

    /**
     * Increments a big number value. Constant-type safe.
     *
     * @return string
     */
    public static function increment(string valueHex) -> string
    {
        // local copy the value to avoid reference change.
        var value;

        // assign the decoded value.
        let value = static::fromHex(valueHex);

        // increment the value.
        sodium_increment(value);

        // return the incremented value.
        return static::toHex(value);
    }

    /**
     * Encode a value into Base64.
     *
     * @return string
     */
    public static function toBase64(string value) -> string
    {
        return sodium_bin2base64(value, SODIUM_BASE64_VARIANT_ORIGINAL);
    }

    /**
     * Decode a value from Base64.
     *
     * @return string
     */
    public static function fromBase64(string encoded) -> string
    {
        return sodium_base642bin(encoded, SODIUM_BASE64_VARIANT_ORIGINAL);
    }

    /**
     * Encode a value into Hexadecimal.
     *
     * @return string
     */
    public static function toHex(string value) -> string
    {
        return sodium_bin2hex(value);
    }

    /**
     * Decode a value from Hexadecimal.
     *
     * @return string
     */
    public static function fromHex(string! encoded) -> string
    {
        return sodium_hex2bin(encoded);
    }

    /**
     * Generate random data with a given length.
     *
     * @return string
     */
    public static function randomBytes(int length, bool encode = true) -> string
    {
        // declare variables.
        var randomData;

        // generate random data.
        let randomData = random_bytes(length);

        // return the value, raw if the encode flat as passed as false.
        return encode ? static::toHex(randomData) : randomData;
    }
}