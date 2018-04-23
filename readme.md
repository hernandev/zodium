# Zodium

**Zodium** is an object-oriented wrapper for the `libsodium` bindings of PHP.

The name **Z**odium is due the fact of this extension being developed with [Zephir](https://zephir-lang.com/).

The original [sodium](https://github.com/jedisct1/libsodium-php) extension is still required, Zodium does not
bind the C library, this extension is a wrapper for the already existing, non-OOP extension.

## Usage.

This library implements most features of `libsodium`.

### SecretBox.

The Secret Box is a libsodium API with provides a simple and reliable way for encrypting and decrypting data using
a shared secret key.

It means the same key is used both to encrypt and decrypt. This key must remain protected at all costs.

There is also the Box implementation, which uses public-key encryption, if that's what you are looking for, go ahead
to the appropriate section.

Here is an example of usage of the SecretBox.

To generate a secret key, you must use:

```php
<?php

// alias the Zodium classes that will be used.
use Zodium\SecretBox\SecretBox;
use Zodium\SecretBox\EncryptedPayload;

// generate a new secret key. It will be hexadecimal encoded.
$key = SecretBox::generateSecretKey();

var_dump($key);
$secretBox = new SecretBox($key);

$someArray = [1, 2, 3];
$someString = 'This is a message.';
$someObject = new \Datetime('2018-02-11T15:03:01.012345Z');

$payload1 = $secretBox->encrypt($someData1);
$payload2 = $secretBox->encrypt($someData2);
$payload3 = $secretBox->encrypt($someData3);

var_dump($payload1);
var_dump($payload2);
var_dump($payload3);
```
