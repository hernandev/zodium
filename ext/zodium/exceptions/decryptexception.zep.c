
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
 * Class DecryptException.
 *
 * Generic exception for decrypt errors on the extension.
 */
ZEPHIR_INIT_CLASS(Zodium_Exceptions_DecryptException) {

	ZEPHIR_REGISTER_CLASS_EX(Zodium\\Exceptions, DecryptException, zodium, exceptions_decryptexception, zodium_exceptions_zodiumexception_ce, NULL, 0);

	return SUCCESS;

}

