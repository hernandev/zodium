
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Class EncryptedPayload.
 *
 * Carries a SecretBox encrypted payload data.
 */
ZEPHIR_INIT_CLASS(Zodium_SecretBox_EncryptedPayload) {

	ZEPHIR_REGISTER_CLASS(Zodium\\SecretBox, EncryptedPayload, zodium, secretbox_encryptedpayload, zodium_secretbox_encryptedpayload_method_entry, 0);

	/**
	 * @var string The ciphertext.
	 */
	zend_declare_property_null(zodium_secretbox_encryptedpayload_ce, SL("ciphertext"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string The nonce used for encryption.
	 */
	zend_declare_property_null(zodium_secretbox_encryptedpayload_ce, SL("nonce"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool Scalar indicator.
	 */
	zend_declare_property_bool(zodium_secretbox_encryptedpayload_ce, SL("scalar"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Cipher constructor.
 */
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, __construct) {

	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool scalar;
	zval *ciphertext_param = NULL, *nonce_param = NULL, *scalar_param = NULL, __$true, __$false, _0, _1, _2, _3;
	zval ciphertext, nonce;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ciphertext);
	ZVAL_UNDEF(&nonce);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &ciphertext_param, &nonce_param, &scalar_param);

	zephir_get_strval(&ciphertext, ciphertext_param);
	zephir_get_strval(&nonce, nonce_param);
	if (!scalar_param) {
		scalar = 1;
	} else {
		scalar = zephir_get_boolval(scalar_param);
	}


	zephir_update_property_zval(this_ptr, SL("ciphertext"), &ciphertext);
	zephir_update_property_zval(this_ptr, SL("nonce"), &nonce);
	if (scalar) {
		zephir_update_property_zval(this_ptr, SL("scalar"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("scalar"), &__$false);
	}
	zephir_read_property(&_0, this_ptr, SL("nonce"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "8bit");
	ZEPHIR_CALL_FUNCTION(&_2, "mb_strlen", NULL, 5, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_3, zodium_secretbox_secretbox_ce, "getnoncebytes", &_4, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_2, &_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "The payload nonce is invalid", "zodium/SecretBox/EncryptedPayload.zep", 43);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the payload ciphertext.
 *
 * @return string
 */
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, getCiphertext) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *encoded_param = NULL, _0, _2;
	zend_bool encoded;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &encoded_param);

	if (!encoded_param) {
		encoded = 1;
	} else {
		encoded = zephir_get_boolval(encoded_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (encoded) {
		zephir_read_property(&_2, this_ptr, SL("ciphertext"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&_0, zodium_helpers_helpers_ce, "tohex", &_1, 0, &_2);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_0, this_ptr, SL("ciphertext"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Return the payload nonce.
 *
 * @return string
 */
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, getNonce) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *encoded_param = NULL, _0, _2;
	zend_bool encoded;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &encoded_param);

	if (!encoded_param) {
		encoded = 1;
	} else {
		encoded = zephir_get_boolval(encoded_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (encoded) {
		zephir_read_property(&_2, this_ptr, SL("nonce"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&_0, zodium_helpers_helpers_ce, "tohex", &_1, 0, &_2);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_0, this_ptr, SL("nonce"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Returns true or false, if the value is scalar or not.
 *
 * @return bool
 */
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, isScalar) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "scalar");

}

/**
 * Encode a given payload for storage or transmission.
 *
 * @return string
 */
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, encode) {

	zval payloadData, encoded, _0, _1, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payloadData);
	ZVAL_UNDEF(&encoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&payloadData);
	zephir_create_array(&payloadData, 3, 0 TSRMLS_CC);
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getciphertext", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&payloadData, SL("ciphertext"), &_0, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getnonce", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&payloadData, SL("nonce"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("scalar"), PH_NOISY_CC);
	zephir_array_update_string(&payloadData, SL("scalar"), &_2, PH_COPY | PH_SEPARATE);

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&encoded);
		zephir_json_encode(&encoded, &payloadData, 0 );

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		ZEPHIR_INIT_VAR(&_4);
		if (zephir_instance_of_ev(&_3, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_4, &_3);
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zodium_exceptions_dataexception_ce, "Error while encoding Payload.", "zodium/SecretBox/EncryptedPayload.zep", 98);
			return;
		}
	}
	RETURN_CCTOR(&encoded);

}

/**
 * Decode a given payload int oa EncruptedPayload instance.
 *
 * @throws DataException
 *
 * @return EncryptedPayload
 */
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, decode) {

	zval _2;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *encodedPayload_param = NULL, __$true, data, item, _0, _1, _3, *_4, _11, _12, _13, _5$$6, _6$$6, _8$$5, _10$$5;
	zval encodedPayload;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encodedPayload);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encodedPayload_param);

	zephir_get_strval(&encodedPayload, encodedPayload_param);



	/* try_start_1: */

		ZEPHIR_INIT_VAR(&data);
		zephir_json_decode(&data, &encodedPayload, zephir_get_intval(&__$true) );

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_0);
		ZVAL_OBJ(&_0, EG(exception));
		Z_ADDREF_P(&_0);
		ZEPHIR_INIT_VAR(&_1);
		if (zephir_instance_of_ev(&_0, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_1, &_0);
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zodium_exceptions_dataexception_ce, "Error decoding the encrypted payload.", "zodium/SecretBox/EncryptedPayload.zep", 122);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "ciphertext");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "nonce");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "scalar");
	zephir_array_fast_append(&_2, &_3);
	zephir_is_iterable(&_2, 0, "zodium/SecretBox/EncryptedPayload.zep", 138);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _4)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _4);
		if (!(zephir_array_key_exists(&data, &item TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(&_5$$6);
			object_init_ex(&_5$$6, zodium_exceptions_dataexception_ce);
			ZEPHIR_INIT_LNVAR(_6$$6);
			ZEPHIR_CONCAT_SVS(&_6$$6, "Payload is missing the ", &item, " key.");
			ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", &_7, 11, &_6$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$6, "zodium/SecretBox/EncryptedPayload.zep", 130 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_LNVAR(_8$$5);
		if (!ZEPHIR_IS_STRING_IDENTICAL(&item, "scalar")) {
			zephir_array_fetch(&_10$$5, &data, &item, PH_NOISY | PH_READONLY, "zodium/SecretBox/EncryptedPayload.zep", 134 TSRMLS_CC);
			ZEPHIR_CALL_CE_STATIC(&_8$$5, zodium_helpers_helpers_ce, "fromhex", &_9, 0, &_10$$5);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&_8$$5);
			zephir_array_fetch(&_8$$5, &data, &item, PH_NOISY, "zodium/SecretBox/EncryptedPayload.zep", 134 TSRMLS_CC);
		}
		zephir_array_update_zval(&data, &item, &_8$$5, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	object_init_ex(return_value, zodium_secretbox_encryptedpayload_ce);
	zephir_array_fetch_string(&_11, &data, SL("ciphertext"), PH_NOISY | PH_READONLY, "zodium/SecretBox/EncryptedPayload.zep", 138 TSRMLS_CC);
	zephir_array_fetch_string(&_12, &data, SL("nonce"), PH_NOISY | PH_READONLY, "zodium/SecretBox/EncryptedPayload.zep", 138 TSRMLS_CC);
	zephir_array_fetch_string(&_13, &data, SL("scalar"), PH_NOISY | PH_READONLY, "zodium/SecretBox/EncryptedPayload.zep", 138 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 20, &_11, &_12, &_13);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Hide the internal values.
 *
 * @return array
 */
PHP_METHOD(Zodium_SecretBox_EncryptedPayload, __debugInfo) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("ciphertext"), SL("*******"));
	add_assoc_stringl_ex(return_value, SL("nonce"), SL("*******"));
	return;

}

