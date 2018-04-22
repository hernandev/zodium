
extern zend_class_entry *zodium_util_ce;

ZEPHIR_INIT_CLASS(Zodium_Util);

PHP_METHOD(Zodium_Util, toBase64);
PHP_METHOD(Zodium_Util, fromBase64);
PHP_METHOD(Zodium_Util, toHex);
PHP_METHOD(Zodium_Util, fromHex);
PHP_METHOD(Zodium_Util, randomBytes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_util_tobase64, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_util_frombase64, 0, 0, 1)
	ZEND_ARG_INFO(0, encoded)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_util_tohex, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_util_fromhex, 0, 0, 1)
	ZEND_ARG_INFO(0, encoded)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_util_randombytes, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zodium_util_method_entry) {
	PHP_ME(Zodium_Util, toBase64, arginfo_zodium_util_tobase64, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_Util, fromBase64, arginfo_zodium_util_frombase64, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_Util, toHex, arginfo_zodium_util_tohex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_Util, fromHex, arginfo_zodium_util_fromhex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_Util, randomBytes, arginfo_zodium_util_randombytes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
