
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
 * Class GenericHash.
 *
 * Wrapper for the generichash of libsodium.
 */
ZEPHIR_INIT_CLASS(Zodium_Hash_GenericHash) {

	ZEPHIR_REGISTER_CLASS(Zodium\\Hash, GenericHash, zodium, hash_generichash, zodium_hash_generichash_method_entry, 0);

	/**
	 * @var int Length of the output hash.
	 */
	zend_declare_property_null(zodium_hash_generichash_ce, SL("hashLength"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string State of a mult-part hash.
	 */
	zend_declare_property_null(zodium_hash_generichash_ce, SL("state"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string A key is not required, but it's supported.
	 */
	zend_declare_property_null(zodium_hash_generichash_ce, SL("hashKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor.
 */
PHP_METHOD(Zodium_Hash_GenericHash, __construct) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long hashLength, ZEPHIR_LAST_CALL_STATUS;
	zval *hashKeyHex_param = NULL, *hashLength_param = NULL, _0$$3, _2$$4, _3$$5;
	zval hashKeyHex;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hashKeyHex);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &hashKeyHex_param, &hashLength_param);

	if (!hashKeyHex_param) {
		ZEPHIR_INIT_VAR(&hashKeyHex);
		ZVAL_STRING(&hashKeyHex, "");
	} else {
		zephir_get_strval(&hashKeyHex, hashKeyHex_param);
	}
	if (!hashLength_param) {
		hashLength = 0;
	} else {
		hashLength = zephir_get_intval(hashLength_param);
	}


	if (!(Z_TYPE_P(&hashKeyHex) == IS_UNDEF) && Z_STRLEN_P(&hashKeyHex)) {
		ZEPHIR_CALL_CE_STATIC(&_0$$3, zodium_helpers_helpers_ce, "fromhex", &_1, 0, &hashKeyHex);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("hashKey"), &_0$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhashkey", NULL, 0);
		zephir_check_call_status();
	}
	if (hashLength) {
		ZEPHIR_INIT_ZVAL_NREF(_2$$4);
		ZVAL_LONG(&_2$$4, hashLength);
		zephir_update_property_zval(this_ptr, SL("hashLength"), &_2$$4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkhashlength", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_3$$5);
		ZVAL_LONG(&_3$$5, 32);
		zephir_update_property_zval(this_ptr, SL("hashLength"), &_3$$5);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Start the multi-part hashing.
 */
PHP_METHOD(Zodium_Hash_GenericHash, start) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("hashKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "sodium_crypto_generichash_init", NULL, 7, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("state"), &_1);
	zephir_read_property(&_2, this_ptr, SL("state"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(Z_TYPE_P(&_2) != IS_NULL);

}

/**
 * Add a message on a multi-part hashing.
 */
PHP_METHOD(Zodium_Hash_GenericHash, add) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0, _1;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	zephir_read_property(&_0, this_ptr, SL("state"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "start", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("state"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&_1);
	ZEPHIR_RETURN_CALL_FUNCTION("sodium_crypto_generichash_update", NULL, 8, &_1, &message);
	ZEPHIR_UNREF(&_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generic hash, if no message was provided, it means closing the multi-part.
 */
PHP_METHOD(Zodium_Hash_GenericHash, hash) {

	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, message_sub, __$null, hash, _0, _1$$3, _2$$3, _3$$4, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &message);

	if (!message) {
		message = &message_sub;
		message = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("state"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, SL("state"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$3, this_ptr, SL("hashLength"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_MAKE_REF(&_1$$3);
		ZEPHIR_CALL_FUNCTION(&hash, "sodium_crypto_generichash_final", NULL, 9, &_1$$3, &_2$$3);
		ZEPHIR_UNREF(&_1$$3);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_3$$4, this_ptr, SL("hashKey"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$4, this_ptr, SL("hashLength"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&hash, "sodium_crypto_generichash", NULL, 10, message, &_3$$4, &_4$$4);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_CE_STATIC(zodium_helpers_helpers_ce, "tohex", &_5, 0, &hash);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a hash length is valid.
 */
PHP_METHOD(Zodium_Hash_GenericHash, checkHashLength) {

	zval _3$$3, _7$$4;
	zval _0, _4, _1$$3, _2$$3, _5$$4, _6$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("hashLength"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_LT_LONG(&_0, 16)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zodium_exceptions_hashexception_ce);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_LONG(&_2$$3, 16);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Hashes must be at least ", &_2$$3);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 11, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "zodium/Hash/GenericHash.zep", 107 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("hashLength"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_4, 64)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, zodium_exceptions_hashexception_ce);
		ZEPHIR_SINIT_VAR(_6$$4);
		ZVAL_LONG(&_6$$4, 64);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_CONCAT_SV(&_7$$4, "Hashes must be at most ", &_6$$4);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 11, &_7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "zodium/Hash/GenericHash.zep", 112 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check for a hash key length.
 */
PHP_METHOD(Zodium_Hash_GenericHash, checkHashKey) {

	zval _4$$3, _7$$4;
	zval length, _0, _1, _2$$3, _3$$3, _5$$4, _6$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("hashKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "8bit");
	ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 5, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(&length, 16)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, zodium_exceptions_hashexception_ce);
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, 16);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SV(&_4$$3, "Hash keys must be at least ", &_3$$3);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 11, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "zodium/Hash/GenericHash.zep", 129 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_GT_LONG(&length, 64)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, zodium_exceptions_hashexception_ce);
		ZEPHIR_SINIT_VAR(_6$$4);
		ZVAL_LONG(&_6$$4, 64);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_CONCAT_SV(&_7$$4, "Hash keys must be at most ", &_6$$4);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 11, &_7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "zodium/Hash/GenericHash.zep", 134 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Simple hash key generator.
 */
PHP_METHOD(Zodium_Hash_GenericHash, generateKey) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 32);
	ZEPHIR_RETURN_CALL_CE_STATIC(zodium_helpers_helpers_ce, "randombytes", &_0, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Hide the internal values.
 *
 * @return array
 */
PHP_METHOD(Zodium_Hash_GenericHash, __debugInfo) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("hashKey"), SL("*******"));
	add_assoc_stringl_ex(return_value, SL("state"), SL("**"));
	return;

}

