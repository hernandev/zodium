
extern zend_class_entry *zodium_aead_cipher_ce;

ZEPHIR_INIT_CLASS(Zodium_AEAD_Cipher);

PHP_METHOD(Zodium_AEAD_Cipher, __construct);
PHP_METHOD(Zodium_AEAD_Cipher, escapeSymbol);
PHP_METHOD(Zodium_AEAD_Cipher, getSodiumConstant);
PHP_METHOD(Zodium_AEAD_Cipher, callSodiumEncrypt);
PHP_METHOD(Zodium_AEAD_Cipher, callSodiumDecrypt);
PHP_METHOD(Zodium_AEAD_Cipher, encrypt);
PHP_METHOD(Zodium_AEAD_Cipher, decrypt);
PHP_METHOD(Zodium_AEAD_Cipher, getCiphers);
PHP_METHOD(Zodium_AEAD_Cipher, getCipher);
PHP_METHOD(Zodium_AEAD_Cipher, getKeyLength);
PHP_METHOD(Zodium_AEAD_Cipher, getNonceLength);
PHP_METHOD(Zodium_AEAD_Cipher, getMacLength);
PHP_METHOD(Zodium_AEAD_Cipher, generateSecretKey);
PHP_METHOD(Zodium_AEAD_Cipher, generateNonce);
PHP_METHOD(Zodium_AEAD_Cipher, setSecretKey);
PHP_METHOD(Zodium_AEAD_Cipher, getSecretKey);
zend_object *zephir_init_properties_Zodium_AEAD_Cipher(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_aead_cipher___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, cipherName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_aead_cipher_escapesymbol, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_aead_cipher_getsodiumconstant, 0, 0, 1)
	ZEND_ARG_INFO(0, sodiumConstant)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_aead_cipher_callsodiumencrypt, 0, 0, 2)
	ZEND_ARG_INFO(0, nonceHex)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, ad)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_aead_cipher_callsodiumdecrypt, 0, 0, 2)
	ZEND_ARG_INFO(0, ciphertextHex)
	ZEND_ARG_INFO(0, nonceHex)
	ZEND_ARG_INFO(0, ad)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_aead_cipher_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, ad)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_aead_cipher_decrypt, 0, 0, 3)
	ZEND_ARG_INFO(0, ciphertextHex)
	ZEND_ARG_INFO(0, nonceHex)
	ZEND_ARG_INFO(0, ad)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_aead_cipher_setsecretkey, 0, 0, 1)
	ZEND_ARG_INFO(0, keyHex)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zodium_aead_cipher_method_entry) {
	PHP_ME(Zodium_AEAD_Cipher, __construct, arginfo_zodium_aead_cipher___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zodium_AEAD_Cipher, escapeSymbol, arginfo_zodium_aead_cipher_escapesymbol, ZEND_ACC_PROTECTED)
	PHP_ME(Zodium_AEAD_Cipher, getSodiumConstant, arginfo_zodium_aead_cipher_getsodiumconstant, ZEND_ACC_PROTECTED)
	PHP_ME(Zodium_AEAD_Cipher, callSodiumEncrypt, arginfo_zodium_aead_cipher_callsodiumencrypt, ZEND_ACC_PROTECTED)
	PHP_ME(Zodium_AEAD_Cipher, callSodiumDecrypt, arginfo_zodium_aead_cipher_callsodiumdecrypt, ZEND_ACC_PROTECTED)
	PHP_ME(Zodium_AEAD_Cipher, encrypt, arginfo_zodium_aead_cipher_encrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_AEAD_Cipher, decrypt, arginfo_zodium_aead_cipher_decrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_AEAD_Cipher, getCiphers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_AEAD_Cipher, getCipher, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_AEAD_Cipher, getKeyLength, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_AEAD_Cipher, getNonceLength, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_AEAD_Cipher, getMacLength, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_AEAD_Cipher, generateSecretKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_AEAD_Cipher, generateNonce, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zodium_AEAD_Cipher, setSecretKey, arginfo_zodium_aead_cipher_setsecretkey, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_AEAD_Cipher, getSecretKey, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
