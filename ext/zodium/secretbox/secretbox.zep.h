
extern zend_class_entry *zodium_secretbox_secretbox_ce;

ZEPHIR_INIT_CLASS(Zodium_SecretBox_SecretBox);

PHP_METHOD(Zodium_SecretBox_SecretBox, __construct);
PHP_METHOD(Zodium_SecretBox_SecretBox, encrypt);
PHP_METHOD(Zodium_SecretBox_SecretBox, decrypt);
PHP_METHOD(Zodium_SecretBox_SecretBox, generateSecretKey);
PHP_METHOD(Zodium_SecretBox_SecretBox, generateNonce);
PHP_METHOD(Zodium_SecretBox_SecretBox, getKeyBytes);
PHP_METHOD(Zodium_SecretBox_SecretBox, getNonceBytes);
PHP_METHOD(Zodium_SecretBox_SecretBox, getMacBytes);
PHP_METHOD(Zodium_SecretBox_SecretBox, __debugInfo);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_secretbox_secretbox___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, secretKeyHex)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_secretbox_secretbox_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_secretbox_secretbox_decrypt, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, encryptedPayload, Zodium\\SecretBox\\EncryptedPayload, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_secretbox_secretbox_generatesecretkey, 0, 0, 0)
	ZEND_ARG_INFO(0, encode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_secretbox_secretbox_generatenonce, 0, 0, 0)
	ZEND_ARG_INFO(0, encode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zodium_secretbox_secretbox_method_entry) {
	PHP_ME(Zodium_SecretBox_SecretBox, __construct, arginfo_zodium_secretbox_secretbox___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zodium_SecretBox_SecretBox, encrypt, arginfo_zodium_secretbox_secretbox_encrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_SecretBox_SecretBox, decrypt, arginfo_zodium_secretbox_secretbox_decrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_SecretBox_SecretBox, generateSecretKey, arginfo_zodium_secretbox_secretbox_generatesecretkey, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_SecretBox_SecretBox, generateNonce, arginfo_zodium_secretbox_secretbox_generatenonce, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Zodium_SecretBox_SecretBox, getKeyBytes, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_SecretBox_SecretBox, getNonceBytes, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_SecretBox_SecretBox, getMacBytes, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_SecretBox_SecretBox, __debugInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
