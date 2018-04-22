
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Zodium_Util) {

	ZEPHIR_REGISTER_CLASS(Zodium, Util, zodium, util, zodium_util_method_entry, 0);

	return SUCCESS;

}

/**
 * Encode a raw value into Base64.
 */
PHP_METHOD(Zodium_Util, toBase64) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, _0;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	ZVAL_LONG(&_0, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("sodium_bin2base64", NULL, 7, &value, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decode a given value from Base64.
 */
PHP_METHOD(Zodium_Util, fromBase64) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *encoded_param = NULL, _0;
	zval encoded;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encoded);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encoded_param);

	zephir_get_strval(&encoded, encoded_param);


	ZVAL_LONG(&_0, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("sodium_base642bin", NULL, 8, &encoded, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Encode a raw value into Hexadecimal.
 */
PHP_METHOD(Zodium_Util, toHex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	ZEPHIR_RETURN_CALL_FUNCTION("sodium_bin2hex", NULL, 9, &value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decode a given value from Hexadecimal.
 */
PHP_METHOD(Zodium_Util, fromHex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *encoded_param = NULL;
	zval encoded;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encoded);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encoded_param);

	if (UNEXPECTED(Z_TYPE_P(encoded_param) != IS_STRING && Z_TYPE_P(encoded_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoded' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(encoded_param) == IS_STRING)) {
		zephir_get_strval(&encoded, encoded_param);
	} else {
		ZEPHIR_INIT_VAR(&encoded);
		ZVAL_EMPTY_STRING(&encoded);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("sodium_hex2bin", NULL, 10, &encoded);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate a given number of random data.
 */
PHP_METHOD(Zodium_Util, randomBytes) {

	zval *length_param = NULL, _0, _1;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &length_param);

	length = zephir_get_intval(length_param);


	ZVAL_LONG(&_0, length);
	ZEPHIR_CALL_FUNCTION(&_1, "random_bytes", NULL, 11, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_STATIC("tobase64", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

