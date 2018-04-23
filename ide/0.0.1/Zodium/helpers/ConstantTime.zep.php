<?php

namespace Zodium\Helpers;

/**
 * Class ConstantTime.
 *
 * Wrapper for all constant-type helpers of libsodium.
 */
class ConstantTime
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
     * @param string $value
     * @return string
     */
    public static function increment($value) {}

}
