
extern zend_class_entry *zodium_helpers_ce;

ZEPHIR_INIT_CLASS(Zodium_Helpers);

PHP_METHOD(Zodium_Helpers, toBase64);
PHP_METHOD(Zodium_Helpers, fromBase64);
PHP_METHOD(Zodium_Helpers, toHex);
PHP_METHOD(Zodium_Helpers, fromHex);
PHP_METHOD(Zodium_Helpers, randomBytes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_helpers_tobase64, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_helpers_frombase64, 0, 0, 1)
	ZEND_ARG_INFO(0, encoded)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_helpers_tohex, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_helpers_fromhex, 0, 0, 1)
	ZEND_ARG_INFO(0, encoded)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_helpers_randombytes, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, encode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zodium_helpers_method_entry) {
	PHP_ME(Zodium_Helpers, toBase64, arginfo_zodium_helpers_tobase64, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_Helpers, fromBase64, arginfo_zodium_helpers_frombase64, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_Helpers, toHex, arginfo_zodium_helpers_tohex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_Helpers, fromHex, arginfo_zodium_helpers_fromhex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_Helpers, randomBytes, arginfo_zodium_helpers_randombytes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
