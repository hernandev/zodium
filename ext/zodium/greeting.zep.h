
extern zend_class_entry *zodium_greeting_ce;

ZEPHIR_INIT_CLASS(Zodium_Greeting);

PHP_METHOD(Zodium_Greeting, say);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_greeting_say, 0, 0, 1)
	ZEND_ARG_INFO(0, something)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zodium_greeting_method_entry) {
	PHP_ME(Zodium_Greeting, say, arginfo_zodium_greeting_say, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
