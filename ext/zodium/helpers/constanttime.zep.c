
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * Class ConstantTime.
 *
 * Wrapper for all constant-type helpers of libsodium.
 */
ZEPHIR_INIT_CLASS(Zodium_Helpers_ConstantTime) {

	ZEPHIR_REGISTER_CLASS(Zodium\\Helpers, ConstantTime, zodium, helpers_constanttime, zodium_helpers_constanttime_method_entry, 0);

	return SUCCESS;

}

/**
 * Constant-type string comparison.
 *
 * @return bool
 */
PHP_METHOD(Zodium_Helpers_ConstantTime, compare) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *b_param = NULL, _0;
	zval a, b;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&b);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a_param, &b_param);

	zephir_get_strval(&a, a_param);
	zephir_get_strval(&b, b_param);


	ZEPHIR_CALL_FUNCTION(&_0, "sodium_compare", NULL, 12, &a, &b);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 0));

}

/**
 * Constant type memory comparison.abstract
 *
 * @return bool.
 */
PHP_METHOD(Zodium_Helpers_ConstantTime, compareMemory) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *a, a_sub, *b, b_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&a_sub);
	ZVAL_UNDEF(&b_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a, &b);



	ZEPHIR_CALL_FUNCTION(&_0, "sodium_memcmp", NULL, 13, a, b);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 0));

}

PHP_METHOD(Zodium_Helpers_ConstantTime, increment) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	ZEPHIR_MAKE_REF(&value);
	ZEPHIR_RETURN_CALL_FUNCTION("sodium_increment", NULL, 14, &value);
	ZEPHIR_UNREF(&value);
	zephir_check_call_status();
	RETURN_MM();

}

