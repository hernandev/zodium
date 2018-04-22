
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * Class AEAD.
 *
 * Generic AEAD cipher implementation.
 */
ZEPHIR_INIT_CLASS(Zodium_AEAD_Cipher) {

	ZEPHIR_REGISTER_CLASS(Zodium\\AEAD, Cipher, zodium, aead_cipher, zodium_aead_cipher_method_entry, 0);

	/**
	 * Current cipher name.
	 */
	zend_declare_property_null(zodium_aead_cipher_ce, SL("cipher"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Private key length.
	 */
	zend_declare_property_null(zodium_aead_cipher_ce, SL("keyLength"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Public nonce length.
	 */
	zend_declare_property_null(zodium_aead_cipher_ce, SL("nonceLength"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Encrypted MAC length.
	 */
	zend_declare_property_null(zodium_aead_cipher_ce, SL("macLength"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Available AEAD ciphers.
	 */
	zend_declare_property_null(zodium_aead_cipher_ce, SL("ciphers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var null|string Hexadecimal encoded secret key for encryption / decryption.
	 */
	zend_declare_property_null(zodium_aead_cipher_ce, SL("secretKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zodium_aead_cipher_ce->create_object = zephir_init_properties_Zodium_AEAD_Cipher;
	return SUCCESS;

}

/**
 * Cipher constructor.
 */
PHP_METHOD(Zodium_AEAD_Cipher, __construct) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cipherName_param = NULL, _0, _1, _2, _4, _5;
	zval cipherName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipherName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipherName_param);

	zephir_get_strval(&cipherName, cipherName_param);


	zephir_read_property(&_0, this_ptr, SL("ciphers"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_fast_in_array(&cipherName, &_0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Invalid cipher name.", "zodium/AEAD/Cipher.zep", 55);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("cipher"), &cipherName);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "KEYBYTES");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getsodiumconstant", &_3, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("keyLength"), &_1);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "NPUBBYTES");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getsodiumconstant", &_3, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("nonceLength"), &_4);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ABYTES");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getsodiumconstant", &_3, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("macLength"), &_5);
	ZEPHIR_MM_RESTORE();

}

/**
 * Scape a string to avoid injection, if at-all possible.
 */
PHP_METHOD(Zodium_AEAD_Cipher, escapeSymbol) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *name_param = NULL, _0, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "2f5b5e412d5a612d7a302d395c2d5c5f5d2f");
	ZEPHIR_CALL_CE_STATIC(&_0, zodium_helpers_ce, "fromhex", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 1, &_0, &_2, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Wraps all constant lookup for the AEAD ciphers on libsodium.
 */
PHP_METHOD(Zodium_AEAD_Cipher, getSodiumConstant) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sodiumConstant_param = NULL, escapedCipher, escapedConstant, _0, _2, _3;
	zval sodiumConstant;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sodiumConstant);
	ZVAL_UNDEF(&escapedCipher);
	ZVAL_UNDEF(&escapedConstant);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sodiumConstant_param);

	zephir_get_strval(&sodiumConstant, sodiumConstant_param);


	zephir_read_property(&_0, this_ptr, SL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&escapedCipher, this_ptr, "escapesymbol", &_1, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&escapedConstant, this_ptr, "escapesymbol", &_1, 0, &sodiumConstant);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVSV(&_2, "SODIUM_CRYPTO_AEAD_", &escapedCipher, "_", &escapedConstant);
	ZEPHIR_CALL_FUNCTION(&_3, "mb_strtoupper", NULL, 2, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("constant", NULL, 3, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Proxy for the sodium encryption function.
 */
PHP_METHOD(Zodium_AEAD_Cipher, callSodiumEncrypt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL;
	zval *nonceHex_param = NULL, *message_param = NULL, *ad_param = NULL, escapedCipherName, nonce, key, functionName, ciphertext, _1, _2, _3;
	zval nonceHex, message, ad;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nonceHex);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&ad);
	ZVAL_UNDEF(&escapedCipherName);
	ZVAL_UNDEF(&nonce);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&functionName);
	ZVAL_UNDEF(&ciphertext);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &nonceHex_param, &message_param, &ad_param);

	zephir_get_strval(&nonceHex, nonceHex_param);
	zephir_get_strval(&message, message_param);
	if (!ad_param) {
		ZEPHIR_INIT_VAR(&ad);
		ZVAL_STRING(&ad, "");
	} else {
		zephir_get_strval(&ad, ad_param);
	}


	ZEPHIR_CALL_CE_STATIC(&nonce, zodium_helpers_ce, "fromhex", &_0, 0, &nonceHex);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("secretKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&key, zodium_helpers_ce, "fromhex", &_0, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "escapesymbol", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&escapedCipherName, "mb_strtolower", NULL, 4, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&functionName);
	ZEPHIR_CONCAT_SVS(&functionName, "sodium_crypto_aead_", &escapedCipherName, "_encrypt");
	ZEPHIR_CALL_ZVAL_FUNCTION(&ciphertext, &functionName, NULL, 0, &message, &ad, &nonce, &key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_CE_STATIC(zodium_helpers_ce, "tohex", &_4, 0, &ciphertext);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decryt an encrypt message / payload back to plain text.
 */
PHP_METHOD(Zodium_AEAD_Cipher, callSodiumDecrypt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *ciphertextHex_param = NULL, *nonceHex_param = NULL, *ad_param = NULL, escapedCipherName, ciphertext, nonce, key, functionName, _1, _2, _3;
	zval ciphertextHex, nonceHex, ad;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ciphertextHex);
	ZVAL_UNDEF(&nonceHex);
	ZVAL_UNDEF(&ad);
	ZVAL_UNDEF(&escapedCipherName);
	ZVAL_UNDEF(&ciphertext);
	ZVAL_UNDEF(&nonce);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&functionName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &ciphertextHex_param, &nonceHex_param, &ad_param);

	zephir_get_strval(&ciphertextHex, ciphertextHex_param);
	zephir_get_strval(&nonceHex, nonceHex_param);
	if (!ad_param) {
		ZEPHIR_INIT_VAR(&ad);
		ZVAL_STRING(&ad, "");
	} else {
		zephir_get_strval(&ad, ad_param);
	}


	ZEPHIR_CALL_CE_STATIC(&ciphertext, zodium_helpers_ce, "fromhex", &_0, 0, &ciphertextHex);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&nonce, zodium_helpers_ce, "fromhex", &_0, 0, &nonceHex);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("secretKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&key, zodium_helpers_ce, "fromhex", &_0, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "escapesymbol", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&escapedCipherName, "mb_strtolower", NULL, 4, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&functionName);
	ZEPHIR_CONCAT_SVS(&functionName, "sodium_crypto_aead_", &escapedCipherName, "_decrypt");
	ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&functionName, NULL, 0, &ciphertext, &ad, &nonce, &key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Encrypt a given message.
 */
PHP_METHOD(Zodium_AEAD_Cipher, encrypt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *ad_param = NULL, nonceHex, ciphertext;
	zval message, ad;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&ad);
	ZVAL_UNDEF(&nonceHex);
	ZVAL_UNDEF(&ciphertext);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &ad_param);

	zephir_get_strval(&message, message_param);
	if (!ad_param) {
		ZEPHIR_INIT_VAR(&ad);
		ZVAL_STRING(&ad, "");
	} else {
		zephir_get_strval(&ad, ad_param);
	}


	ZEPHIR_CALL_METHOD(&nonceHex, this_ptr, "generatenonce", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&ciphertext, this_ptr, "callsodiumencrypt", NULL, 0, &nonceHex, &message, &ad);
	zephir_check_call_status();
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("ciphertext"), &ciphertext, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("nonce"), &nonceHex, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("ad"), &ad, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Decript a message.
 */
PHP_METHOD(Zodium_AEAD_Cipher, decrypt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ciphertextHex_param = NULL, *nonceHex_param = NULL, *ad_param = NULL;
	zval ciphertextHex, nonceHex, ad;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ciphertextHex);
	ZVAL_UNDEF(&nonceHex);
	ZVAL_UNDEF(&ad);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &ciphertextHex_param, &nonceHex_param, &ad_param);

	zephir_get_strval(&ciphertextHex, ciphertextHex_param);
	zephir_get_strval(&nonceHex, nonceHex_param);
	zephir_get_strval(&ad, ad_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callsodiumdecrypt", NULL, 0, &ciphertextHex, &nonceHex, &ad);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a list of the available Ciphers.
 */
PHP_METHOD(Zodium_AEAD_Cipher, getCiphers) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "ciphers");

}

/**
 * Returns the current cipher
 */
PHP_METHOD(Zodium_AEAD_Cipher, getCipher) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cipher");

}

/**
 * Returns the size in bytes, a key must have for the current cipher.
 */
PHP_METHOD(Zodium_AEAD_Cipher, getKeyLength) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "keyLength");

}

/**
 * Returns the size in bytes, a nonce must have for the current cipher.
 */
PHP_METHOD(Zodium_AEAD_Cipher, getNonceLength) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "nonceLength");

}

/**
 * Returns the size in bytes, a MAC must have for the current cipher.
 */
PHP_METHOD(Zodium_AEAD_Cipher, getMacLength) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "macLength");

}

/**
 * Generates a new secret key for encryption.
 * The key length will match the requirements of the current cipher.
 */
PHP_METHOD(Zodium_AEAD_Cipher, generateSecretKey) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_1, this_ptr, SL("keyLength"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_CE_STATIC(zodium_helpers_ce, "randombytes", &_0, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate a random nonce to be used when encrypting.
 */
PHP_METHOD(Zodium_AEAD_Cipher, generateNonce) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_1, this_ptr, SL("nonceLength"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_CE_STATIC(zodium_helpers_ce, "randombytes", &_0, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Secret key setter.
 */
PHP_METHOD(Zodium_AEAD_Cipher, setSecretKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *keyHex_param = NULL, key, _1, _2, _3, _4$$3, _5$$3, _6$$3;
	zval keyHex;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyHex);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyHex_param);

	zephir_get_strval(&keyHex, keyHex_param);


	ZEPHIR_CALL_CE_STATIC(&key, zodium_helpers_ce, "fromhex", &_0, 0, &keyHex);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "8bit");
	ZEPHIR_CALL_FUNCTION(&_2, "mb_strlen", NULL, 5, &key, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("keyLength"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_EQUAL(&_2, &_3)) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, zend_exception_get_default(TSRMLS_C));
		zephir_read_property(&_5$$3, this_ptr, SL("keyLength"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SVS(&_6$$3, "Invalid key size, keys must be ", &_5$$3, " long.");
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 6, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "zodium/AEAD/Cipher.zep", 240 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("secretKey"), &keyHex);
	RETURN_THIS();

}

/**
 * Returns the current secret key (hex) on the cipher instance.
 */
PHP_METHOD(Zodium_AEAD_Cipher, getSecretKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "secretKey");

}

zend_object *zephir_init_properties_Zodium_AEAD_Cipher(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("ciphers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 4, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "AES256GCM");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "CHACHA20POLY1305");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "CHACHA20POLY1305_IETF");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "XCHACHA20POLY1305_IETF");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			zephir_update_property_zval(this_ptr, SL("ciphers"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

