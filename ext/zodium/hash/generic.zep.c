
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
#include "kernel/fcall.h"
#include "kernel/memory.h"


/**
 * Class Generic.
 *
 * Wrapper for the generichash of libsodium.
 */
ZEPHIR_INIT_CLASS(Zodium_Hash_Generic) {

	ZEPHIR_REGISTER_CLASS(Zodium\\Hash, Generic, zodium, hash_generic, zodium_hash_generic_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Zodium_Hash_Generic, hash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_RETURN_CALL_FUNCTION("sodium_crypto_generichash", NULL, 7, message);
	zephir_check_call_status();
	RETURN_MM();

}

