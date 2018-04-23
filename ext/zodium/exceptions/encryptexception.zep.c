
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


/**
 * Class EncryptException.
 *
 * Generic exception for encrypt errors on the extension.
 */
ZEPHIR_INIT_CLASS(Zodium_Exceptions_EncryptException) {

	ZEPHIR_REGISTER_CLASS_EX(Zodium\\Exceptions, EncryptException, zodium, exceptions_encryptexception, zodium_exceptions_zodiumexception_ce, NULL, 0);

	return SUCCESS;

}

