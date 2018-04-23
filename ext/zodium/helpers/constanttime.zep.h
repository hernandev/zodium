
extern zend_class_entry *zodium_helpers_constanttime_ce;

ZEPHIR_INIT_CLASS(Zodium_Helpers_ConstantTime);

PHP_METHOD(Zodium_Helpers_ConstantTime, compare);
PHP_METHOD(Zodium_Helpers_ConstantTime, compareMemory);
PHP_METHOD(Zodium_Helpers_ConstantTime, increment);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_helpers_constanttime_compare, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_helpers_constanttime_comparememory, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zodium_helpers_constanttime_increment, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zodium_helpers_constanttime_method_entry) {
	PHP_ME(Zodium_Helpers_ConstantTime, compare, arginfo_zodium_helpers_constanttime_compare, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_Helpers_ConstantTime, compareMemory, arginfo_zodium_helpers_constanttime_comparememory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zodium_Helpers_ConstantTime, increment, arginfo_zodium_helpers_constanttime_increment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
