
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * Class SecretBox.
 *
 * OOP wrapper for libsodium SecretBox.
 */
ZEPHIR_INIT_CLASS(Zodium_SecretBox_SecretBox) {

	ZEPHIR_REGISTER_CLASS(Zodium\\SecretBox, SecretBox, zodium, secretbox_secretbox, zodium_secretbox_secretbox_method_entry, 0);

	/**
	 * @var null|string Hexadecimal encoded secret key for encryption / decryption.
	 */
	zend_declare_property_null(zodium_secretbox_secretbox_ce, SL("secretKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Cipher constructor.
 */
PHP_METHOD(Zodium_SecretBox_SecretBox, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *secretKeyHex_param = NULL, _0, _2, _3, _4, _5, _6$$3, _7$$3, _8$$3;
	zval secretKeyHex;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&secretKeyHex);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &secretKeyHex_param);

	zephir_get_strval(&secretKeyHex, secretKeyHex_param);


	ZEPHIR_CALL_CE_STATIC(&_0, zodium_helpers_helpers_ce, "fromhex", &_1, 0, &secretKeyHex);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("secretKey"), &_0);
	zephir_read_property(&_2, this_ptr, SL("secretKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "8bit");
	ZEPHIR_CALL_FUNCTION(&_4, "mb_strlen", NULL, 5, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_STATIC(&_5, "getkeybytes", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(&_4, &_5)) {
		ZEPHIR_INIT_VAR(&_6$$3);
		object_init_ex(&_6$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_CALL_STATIC(&_7$$3, "getkeybytes", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$3);
		ZEPHIR_CONCAT_SVS(&_8$$3, "Invalid secret key, it must be ", &_7$$3, " bytes.");
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "__construct", NULL, 6, &_8$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$3, "zodium/SecretBox/SecretBox.zep", 29 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Encrypt a given message.
 *
 * @return null|EncryptedPayload
 */
PHP_METHOD(Zodium_SecretBox_SecretBox, encrypt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, nonce, ciphertext, prepared, scalar, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&nonce);
	ZVAL_UNDEF(&ciphertext);
	ZVAL_UNDEF(&prepared);
	ZVAL_UNDEF(&scalar);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(&scalar);
	ZVAL_BOOL(&scalar, zephir_is_scalar(message));
	if (zephir_is_scalar(message)) {
		ZEPHIR_CPY_WRT(&prepared, message);
	} else {
		ZEPHIR_CALL_FUNCTION(&prepared, "serialize", NULL, 17, message);
		zephir_check_call_status();
	}
	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(&nonce, this_ptr, "generatenonce", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("secretKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&ciphertext, "sodium_crypto_secretbox", NULL, 18, &prepared, &nonce, &_0);
	zephir_check_call_status();
	object_init_ex(return_value, zodium_secretbox_encryptedpayload_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 16, &ciphertext, &nonce, &scalar);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrypt a message.
 *
 * @return null|mixed
 */
PHP_METHOD(Zodium_SecretBox_SecretBox, decrypt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *encryptedPayload, encryptedPayload_sub, ciphertext, nonce, prepared, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encryptedPayload_sub);
	ZVAL_UNDEF(&ciphertext);
	ZVAL_UNDEF(&nonce);
	ZVAL_UNDEF(&prepared);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encryptedPayload);



	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(&ciphertext, encryptedPayload, "getciphertext", NULL, 0, &_0);
	zephir_check_call_status();
	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(&nonce, encryptedPayload, "getnonce", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("secretKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&prepared, "sodium_crypto_secretbox_open", NULL, 19, &ciphertext, &nonce, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, encryptedPayload, "isscalar", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CPY_WRT(&_1, &prepared);
	} else {
		ZEPHIR_CALL_FUNCTION(&_1, "unserialize", NULL, 20, &prepared);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_1);

}

/**
 * Generates a new secret key for encryption with the SecretBox.
 *
 * @return string
 */
PHP_METHOD(Zodium_SecretBox_SecretBox, generateSecretKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *encode_param = NULL, _1, _2;
	zend_bool encode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &encode_param);

	if (!encode_param) {
		encode = 1;
	} else {
		encode = zephir_get_boolval(encode_param);
	}


	ZEPHIR_CALL_STATIC(&_1, "getkeybytes", NULL, 0);
	zephir_check_call_status();
	if (encode) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_RETURN_CALL_CE_STATIC(zodium_helpers_helpers_ce, "randombytes", &_0, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate a random nonce to be used when encrypting.
 *
 * @return string
 */
PHP_METHOD(Zodium_SecretBox_SecretBox, generateNonce) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *encode_param = NULL, _1, _2;
	zend_bool encode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &encode_param);

	if (!encode_param) {
		encode = 1;
	} else {
		encode = zephir_get_boolval(encode_param);
	}


	ZEPHIR_CALL_STATIC(&_1, "getnoncebytes", NULL, 0);
	zephir_check_call_status();
	if (encode) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_RETURN_CALL_CE_STATIC(zodium_helpers_helpers_ce, "randombytes", &_0, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the size in bytes, a key must have for the current cipher.
 *
 * @return int
 */
PHP_METHOD(Zodium_SecretBox_SecretBox, getKeyBytes) {

	zval *this_ptr = getThis();


	RETURN_LONG(32);

}

/**
 * Returns the size in bytes, a nonce must have for the current cipher.
 *
 * @retun int
 */
PHP_METHOD(Zodium_SecretBox_SecretBox, getNonceBytes) {

	zval *this_ptr = getThis();


	RETURN_LONG(24);

}

/**
 * Returns the size in bytes, a MAC must have for the current cipher.
 *
 * @return int
 */
PHP_METHOD(Zodium_SecretBox_SecretBox, getMacBytes) {

	zval *this_ptr = getThis();


	RETURN_LONG(16);

}

/**
 * Hide the internal values.
 *
 * @return array
 */
PHP_METHOD(Zodium_SecretBox_SecretBox, __debugInfo) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("secretKey"), SL("*******"));
	return;

}

