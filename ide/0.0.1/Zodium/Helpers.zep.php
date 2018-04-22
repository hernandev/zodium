<?php

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
     *
     * @param string $value
     * @return string
     */
    public static function toBase64($value) {}

    /**
     * Decode a given value from Base64.
     *
     * @param string $encoded
     * @return string
     */
    public static function fromBase64($encoded) {}

    /**
     * Encode a raw value into Hexadecimal.
     *
     * @param string $value
     * @return string
     */
    public static function toHex($value) {}

    /**
     * Decode a given value from Hexadecimal.
     *
     * @param string $encoded
     * @return string
     */
    public static function fromHex($encoded) {}

    /**
     * Generate a given number of random data.
     *
     * @param int $length
     * @return string
     */
    public static function randomBytes($length) {}

}
