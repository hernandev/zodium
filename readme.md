# Zodium

**Zodium** is an object-oriented wrapper for the `libsodium` bindings of PHP.

The name **Z**odium is due the fact of this extension being developed with [Zephir](https://zephir-lang.com/).

The original [sodium](https://github.com/jedisct1/libsodium-php) extension is still required, Zodium does not
bind the C library, this extension is a wrapper for the already existing, non-OOP extension.

#### Usage:

The library aims to be really easy to use.

##### Hashing:

```php
<?php
// alias the GenericHash class.
use Zodium\Hash\GenericHash;

// start a key-less hasher instance.
$hasher = new GenericHash();

// hash a value without a hashing key.
$hash = $hasher->hash('foo');
// string(64) "93a0e84a8cdd416626...

// generate a hashing key.
$key = GenericHash::generateKey();
// string(64) "62009feb496f0...

// start a new hasher with the hashing key.
$hasher = new GenericHasher($key);

$hash = $hasher->hash('foo');
// string(64) "714ee3a37cf69bb3aee17...

// start a custom length hash output instance.
$hasher = new GenericHash($key, 64);
$hash = $hasher->hash('foo');
// string(128) "d94315288e268d813e...

// multi-part signature..
$hasher->add("part1");
$hasher->add("part2");

// get the final hash from the parts included.
$hash = $hasher->hash();
```

##### AEAD:

```php
<?php
// aliases.
use Zodium\AEAD\Cipher;

// start a AEAD cipher instance on the ChaCha20-Poly1305 construction.
$cipher = new Cipher('CHACHA20POLY1305');

// get a private secret key.
$cipher->setSecretKey(Cipher::generateSecretKey());

// encrypt the secret data with some associated public data.
$encryptedPayload = $cipher->encrypt('message', 'associated-data');

// decrypt the original message from the payload.
$original = $cipher->decrypt($encryptedPayload);
```

##### SecretBox:

```php
<?php

// aliases.
use Zodium\SecretBox\SecretBox;
use Zodium\SecretBox\EncryptedPayload;

// generate a secret key for use with the SecretBox.
$key = SecretBox::generateSecretKey();

// start a SecretBox instance.
$box = new SecretBox($key);

// encrypt some data, and receive a EncryptPayload instance as return.
$payload = $box->encrypt('some-data-as-string');

// encode the payload for transmission or storage:
$payloadString = $payload->encode();

// reverse the payload from string into instance.
$payload = EncryptedPayload::decode($payloadString);

// decrypt.
$originalData = $box->decrypt($payload);

// extras:
// you can encrypt any serializable value on PHP.
$payload = $box->encrypt(new Datetime());
// the value will be unserialized back on the original type!.
$dateTimeInstance = $box->decrypt($payload);

```

#### Roadmap:

Current features to be included are:

- Constant-time helpers and safe evaluation of sensitive values.
- Public-key Encryption.
- Stand-alone message authentication.
- Bind Zephir optimizers to calls on the libsodium directly.
- Documentation
- .phpt tests.
