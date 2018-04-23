
extern zend_class_entry *zodium_hash_generichash_ce;

ZEPHIR_INIT_CLASS(Zodium_Hash_GenericHash);

PHP_METHOD(Zodium_Hash_GenericHash, __construct);
PHP_METHOD(Zodium_Hash_GenericHash, start);
PHP_METHOD(Zodium_Hash_GenericHash, add);
PHP_METHOD(Zodium_Hash_GenericHash, hash);
PHP_METHOD(Zodium_Hash_GenericHash, checkHashLength);
PHP_METHOD(Zodium_Hash_GenericHash, checkHashKey);
PHP_METHOD(Zodium_Hash_GenericHash, generateKey);
PHP_METHOD(Zodium_Hash_GenericHash, __debugInfo);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_hash_generichash___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, hashKeyHex)
	ZEND_ARG_INFO(0, hashLength)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_hash_generichash_add, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_hash_generichash_hash, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zodium_hash_generichash_method_entry) {
	PHP_ME(Zodium_Hash_GenericHash, __construct, arginfo_zodium_hash_generichash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zodium_Hash_GenericHash, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_Hash_GenericHash, add, arginfo_zodium_hash_generichash_add, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_Hash_GenericHash, hash, arginfo_zodium_hash_generichash_hash, ZEND_ACC_PUBLIC)
	PHP_ME(Zodium_Hash_GenericHash, checkHashLength, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zodium_Hash_GenericHash, checkHashKey, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zodium_Hash_GenericHash, generateKey, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_Hash_GenericHash, __debugInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
