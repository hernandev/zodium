<?php

namespace Zodium\AEAD;

/**
 * Class AEAD.
 *
 * Generic AEAD cipher implementation.
 */
class Cipher
{
    /**
     * Current cipher name.
     */
    protected $cipher;

    /**
     * Private key length.
     */
    protected $keyLength;

    /**
     * Public nonce length.
     */
    protected $nonceLength;

    /**
     * Encrypted MAC length.
     */
    protected $macLength;

    /**
     * Available AEAD ciphers.
     */
    protected $ciphers = array("AES256GCM", "CHACHA20POLY1305", "CHACHA20POLY1305_IETF", "XCHACHA20POLY1305_IETF");

    /**
     * @var null|string Base64 encoded secret key for encryption / decryption.
     */
    protected $secretKey;


    /**
     * Cipher constructor.
     *
     * @param string $cipherName
     */
    public function __construct($cipherName) {}

    /**
     * Scape a string to avoid injection, if at-all possible.
     *
     * @param string $name
     */
    protected function escapeSymbol($name) {}

    /**
     * Wraps all constant lookup for the AEAD ciphers on libsodium.
     *
     * @param string $sodiumConstant
     */
    protected function getSodiumConstant($sodiumConstant) {}

    /**
     * Proxy for the sodium encryption function.
     *
     * @param string $nonce64
     * @param string $message
     * @param string $ad
     * @return string
     */
    protected function callSodiumEncrypt($nonce64, $message, $ad = null) {}

    /**
     * Decryt an encrypt message / payload back to plain text.
     *
     * @param string $cipherText64
     * @param string $nonce64
     * @param string $ad
     */
    protected function callSodiumDecrypt($cipherText64, $nonce64, $ad = null) {}

    /**
     * Encrypt a given message.
     *
     * @param string $message
     * @param string $ad
     * @return array
     */
    public function encrypt($message, $ad = null) {}

    /**
     * Decript a message.
     *
     * @param string $cipherText64
     * @param string $nonce64
     * @param string $ad
     */
    public function decrypt($cipherText64, $nonce64, $ad) {}

    /**
     * Returns a list of the available Ciphers.
     *
     * @return array
     */
    public function getCiphers() {}

    /**
     * Returns the current cipher
     *
     * @return string
     */
    public function getCipher() {}

    /**
     * Returns the size in bytes, a key must have for the current cipher.
     *
     * @return int
     */
    public function getKeyLength() {}

    /**
     * Returns the size in bytes, a nonce must have for the current cipher.
     *
     * @return int
     */
    public function getNonceLength() {}

    /**
     * Returns the size in bytes, a MAC must have for the current cipher.
     *
     * @return int
     */
    public function getMacLength() {}

    /**
     * Generates a new secret key for encryption.
     * The key length will match the requirements of the current cipher.
     *
     * @return string
     */
    public function generateSecretKey() {}

    /**
     * Generate a random nonce to be used when encrypting.
     *
     * @return string
     */
    protected function generateNonce() {}

    /**
     * Secret key setter.
     *
     * @param string $encodedKey
     * @return Cipher
     */
    public function setSecretKey($encodedKey) {}

    /**
     * Returns the current secret key on the cipher instance.
     *
     * @return string
     */
    public function getSecretKey() {}

}
