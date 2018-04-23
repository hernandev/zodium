
extern zend_class_entry *zodium_secretbox_encryptedpayload_ce;

ZEPHIR_INIT_CLASS(Zodium_SecretBox_EncryptedPayload);

PHP_METHOD(Zodium_SecretBox_EncryptedPayload, __construct);
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, getCiphertext);
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, getNonce);
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, isScalar);
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, encode);
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, decode);
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, __debugInfo);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_secretbox_encryptedpayload___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, ciphertext)
	ZEND_ARG_INFO(0, nonce)
	ZEND_ARG_INFO(0, scalar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_secretbox_encryptedpayload_getciphertext, 0, 0, 0)
	ZEND_ARG_INFO(0, encoded)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_secretbox_encryptedpayload_getnonce, 0, 0, 0)
	ZEND_ARG_INFO(0, encoded)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_secretbox_encryptedpayload_decode, 0, 0, 1)
	ZEND_ARG_INFO(0, encodedPayload)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zodium_secretbox_encryptedpayload_method_entry) {
	PHP_ME(Zodium_SecretBox_EncryptedPayload, __construct, arginfo_zodium_secretbox_encryptedpayload___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zodium_SecretBox_EncryptedPayload, getCiphertext, arginfo_zodium_secretbox_encryptedpayload_getciphertext, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_SecretBox_EncryptedPayload, getNonce, arginfo_zodium_secretbox_encryptedpayload_getnonce, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_SecretBox_EncryptedPayload, isScalar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_SecretBox_EncryptedPayload, encode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_SecretBox_EncryptedPayload, decode, arginfo_zodium_secretbox_encryptedpayload_decode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_SecretBox_EncryptedPayload, __debugInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
