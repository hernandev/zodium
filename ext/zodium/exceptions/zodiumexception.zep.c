
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
#include "ext/spl/spl_exceptions.h"


/**
 * Class ZodiumException.
 *
 * Generic exception for the extension.
 */
ZEPHIR_INIT_CLASS(Zodium_Exceptions_ZodiumException) {

	ZEPHIR_REGISTER_CLASS_EX(Zodium\\Exceptions, ZodiumException, zodium, exceptions_zodiumexception, spl_ce_RuntimeException, NULL, 0);

	return SUCCESS;

}

