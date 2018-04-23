<?php

namespace Zodium\SecretBox;

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
    protected $ciphertext;

    /**
     * @var string The nonce used for encryption.
     */
    protected $nonce;

    /**
     * @var bool Scalar indicator.
     */
    protected $scalar = true;


    /**
     * Cipher constructor.
     *
     * @param string $ciphertext
     * @param string $nonce
     * @param bool $scalar
     */
    public function __construct($ciphertext, $nonce, $scalar = true) {}

    /**
     * Return the payload ciphertext.
     *
     * @param bool $encoded
     * @return string
     */
    public function getCiphertext($encoded = true) {}

    /**
     * Return the payload nonce.
     *
     * @param bool $encoded
     * @return string
     */
    public function getNonce($encoded = true) {}

    /**
     * Returns true or false, if the value is scalar or not.
     *
     * @return bool
     */
    public function isScalar() {}

    /**
     * Encode a given payload for storage or transmission.
     *
     * @return string
     */
    public function encode() {}

    /**
     * Decode a given payload int oa EncruptedPayload instance.
     *
     * @throws DataException
     *
     * @param string $encodedPayload
     * @return EncryptedPayload
     */
    public static function decode($encodedPayload) {}

    /**
     * Hide the internal values.
     *
     * @return array
     */
    public function __debugInfo() {}

}
