<?php

namespace Zodium\SecretBox;

/**
 * Class SecretBox.
 *
 * OOP wrapper for libsodium SecretBox.
 */
class SecretBox
{
    /**
     * @var null|string Hexadecimal encoded secret key for encryption / decryption.
     */
    protected $secretKey;


    /**
     * Cipher constructor.
     *
     * @param string $secretKeyHex
     */
    public function __construct($secretKeyHex) {}

    /**
     * Encrypt a given message.
     *
     * @param mixed $message
     * @return null|\Zodium\SecretBox\EncryptedPayload
     */
    public function encrypt($message) {}

    /**
     * Decrypt a message.
     *
     * @param \Zodium\SecretBox\EncryptedPayload $encryptedPayload
     * @return mixed|bool
     */
    public function decrypt(\Zodium\SecretBox\EncryptedPayload $encryptedPayload) {}

    /**
     * Generates a new secret key for encryption with the SecretBox.
     *
     * @param bool $encode
     * @return string
     */
    public static function generateSecretKey($encode = true) {}

    /**
     * Generate a random nonce to be used when encrypting.
     *
     * @param bool $encode
     * @return string
     */
    protected static function generateNonce($encode = true) {}

    /**
     * Returns the size in bytes, a key must have for the current cipher.
     *
     * @return int
     */
    public static function getKeyBytes() {}

    /**
     * Returns the size in bytes, a nonce must have for the current cipher.
     *
     * @retun int
     * @return int
     */
    public static function getNonceBytes() {}

    /**
     * Returns the size in bytes, a MAC must have for the current cipher.
     *
     * @return int
     */
    public static function getMacBytes() {}

    /**
     * Hide the internal values.
     *
     * @return array
     */
    public function __debugInfo() {}

}
