<?php

namespace Zodium\Hash;

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
    protected $hashLength;

    /**
     * @var string State of a mult-part hash.
     */
    protected $state = null;

    /**
     * @var string A key is not required, but it's supported.
     */
    protected $hashKey;


    /**
     * Constructor.
     *
     * @param string $hashKeyHex
     * @param int $hashLength
     */
    public function __construct($hashKeyHex = null, $hashLength = null) {}

    /**
     * Start the multi-part hashing.
     *
     * @return bool
     */
    public function start() {}

    /**
     * Add a message on a multi-part hashing.
     *
     * @param string $message
     * @return bool
     */
    public function add($message) {}

    /**
     * Generic hash, if no message was provided, it means closing the multi-part.
     *
     * @param mixed $message
     * @return string
     */
    public function hash($message = null) {}

    /**
     * Check if a hash length is valid.
     */
    protected function checkHashLength() {}

    /**
     * Check for a hash key length.
     */
    protected function checkHashKey() {}

    /**
     * Simple hash key generator.
     *
     * @return string
     */
    public static function generateKey() {}

    /**
     * Hide the internal values.
     *
     * @return array
     */
    public function __debugInfo() {}

}
