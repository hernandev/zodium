namespace Zodium;

class Helpers
{
    /**
     * Encode a raw value into Base64.
     */
    public static function toBase64(string value)
    {
        return sodium_bin2base64(value, SODIUM_BASE64_VARIANT_ORIGINAL);
    }

    /**
     * Decode a given value from Base64.
     */
    public static function fromBase64(string encoded)
    {
        return sodium_base642bin(encoded, SODIUM_BASE64_VARIANT_ORIGINAL);
    }

    /**
     * Encode a raw value into Hexadecimal.
     */
    public static function toHex(string value)
    {
        return sodium_bin2hex(value);
    }

    /**
     * Decode a given value from Hexadecimal.
     */
    public static function fromHex(string! encoded)
    {
        return sodium_hex2bin(encoded);
    }

    /**
     * Generate a given number of random data.
     */
    public static function randomBytes(int length)
    {
        return static::toBase64(random_bytes(length));
    }
}