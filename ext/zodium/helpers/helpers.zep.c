
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Class Helpers.
 *
 * Wrapper for all constant-type helpers of libsodium.
 */
ZEPHIR_INIT_CLASS(Zodium_Helpers_Helpers) {

	ZEPHIR_REGISTER_CLASS(Zodium\\Helpers, Helpers, zodium, helpers_helpers, zodium_helpers_helpers_method_entry, 0);

	return SUCCESS;

}

/**
 * Constant-type string comparison.
 *
 * @return bool
 */
PHP_METHOD(Zodium_Helpers_Helpers, compare) {

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
 * @return bool
 */
PHP_METHOD(Zodium_Helpers_Helpers, compareMemory) {

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

/**
 * Increments a big number value. Constant-type safe.
 *
 * @return string
 */
PHP_METHOD(Zodium_Helpers_Helpers, increment) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *valueHex_param = NULL, value;
	zval valueHex;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&valueHex);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &valueHex_param);

	zephir_get_strval(&valueHex, valueHex_param);


	ZEPHIR_CALL_STATIC(&value, "fromhex", NULL, 0, &valueHex);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&value);
	ZEPHIR_CALL_FUNCTION(NULL, "sodium_increment", NULL, 14, &value);
	ZEPHIR_UNREF(&value);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_STATIC("tohex", NULL, 0, &value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Encode a value into Base64.
 *
 * @return string
 */
PHP_METHOD(Zodium_Helpers_Helpers, toBase64) {

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
	ZEPHIR_RETURN_CALL_FUNCTION("sodium_bin2base64", NULL, 15, &value, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decode a value from Base64.
 *
 * @return string
 */
PHP_METHOD(Zodium_Helpers_Helpers, fromBase64) {

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
	ZEPHIR_RETURN_CALL_FUNCTION("sodium_base642bin", NULL, 16, &encoded, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Encode a value into Hexadecimal.
 *
 * @return string
 */
PHP_METHOD(Zodium_Helpers_Helpers, toHex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	ZEPHIR_RETURN_CALL_FUNCTION("sodium_bin2hex", NULL, 17, &value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decode a value from Hexadecimal.
 *
 * @return string
 */
PHP_METHOD(Zodium_Helpers_Helpers, fromHex) {

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


	ZEPHIR_RETURN_CALL_FUNCTION("sodium_hex2bin", NULL, 18, &encoded);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate random data with a given length.
 *
 * @return string
 */
PHP_METHOD(Zodium_Helpers_Helpers, randomBytes) {

	zend_bool encode;
	zval *length_param = NULL, *encode_param = NULL, randomData, _0, _1;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&randomData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &length_param, &encode_param);

	length = zephir_get_intval(length_param);
	if (!encode_param) {
		encode = 1;
	} else {
		encode = zephir_get_boolval(encode_param);
	}


	ZVAL_LONG(&_0, length);
	ZEPHIR_CALL_FUNCTION(&randomData, "random_bytes", NULL, 19, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (encode) {
		ZEPHIR_CALL_STATIC(&_1, "tohex", NULL, 0, &randomData);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_1, &randomData);
	}
	RETURN_CCTOR(&_1);

}

