
extern zend_class_entry *zodium_hash_generic_ce;

ZEPHIR_INIT_CLASS(Zodium_Hash_Generic);

PHP_METHOD(Zodium_Hash_Generic, hash);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_hash_generic_hash, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zodium_hash_generic_method_entry) {
	PHP_ME(Zodium_Hash_Generic, hash, arginfo_zodium_hash_generic_hash, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
