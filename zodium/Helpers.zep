namespace Zodium;

/**
 * Class Helpers.
 *
 * Small helpers for Zodium.
 */
class Helpers
{
    /**
     * Encode a raw value into Base64.
     */
    public static function toBase64(string value) -> string
    {
        return sodium_bin2base64(value, SODIUM_BASE64_VARIANT_ORIGINAL);
    }

    /**
     * Decode a given value from Base64.
     */
    public static function fromBase64(string encoded) -> string
    {
        return sodium_base642bin(encoded, SODIUM_BASE64_VARIANT_ORIGINAL);
    }

    /**
     * Encode a raw value into Hexadecimal.
     */
    public static function toHex(string value) -> string
    {
        return sodium_bin2hex(value);
    }

    /**
     * Decode a given value from Hexadecimal.
     */
    public static function fromHex(string! encoded) -> string
    {
        return sodium_hex2bin(encoded);
    }

    /**
     * Generate a given number of random data.
     */
    public static function randomBytes(int length) -> string
    {
        return static::toHex(random_bytes(length));
    }
}