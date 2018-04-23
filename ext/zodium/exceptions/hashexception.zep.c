
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
 * Class HashException.
 *
 * Generic exception for hashing errors on the extension.
 */
ZEPHIR_INIT_CLASS(Zodium_Exceptions_HashException) {

	ZEPHIR_REGISTER_CLASS_EX(Zodium\\Exceptions, HashException, zodium, exceptions_hashexception, zodium_exceptions_zodiumexception_ce, NULL, 0);

	return SUCCESS;

}

