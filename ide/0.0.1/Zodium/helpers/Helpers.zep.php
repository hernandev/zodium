<?php

namespace Zodium\Helpers;

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
     * @param string $a
     * @param string $b
     * @return bool
     */
    public static function compare($a, $b) {}

    /**
     * Constant type memory comparison.abstract
     *
     * @param mixed $a
     * @param mixed $b
     * @return bool
     */
    public static function compareMemory($a, $b) {}

    /**
     * Increments a big number value. Constant-type safe.
     *
     * @param string $valueHex
     * @return string
     */
    public static function increment($valueHex) {}

    /**
     * Encode a value into Base64.
     *
     * @param string $value
     * @return string
     */
    public static function toBase64($value) {}

    /**
     * Decode a value from Base64.
     *
     * @param string $encoded
     * @return string
     */
    public static function fromBase64($encoded) {}

    /**
     * Encode a value into Hexadecimal.
     *
     * @param string $value
     * @return string
     */
    public static function toHex($value) {}

    /**
     * Decode a value from Hexadecimal.
     *
     * @param string $encoded
     * @return string
     */
    public static function fromHex($encoded) {}

    /**
     * Generate random data with a given length.
     *
     * @param int $length
     * @param bool $encode
     * @return string
     */
    public static function randomBytes($length, $encode = true) {}

}
