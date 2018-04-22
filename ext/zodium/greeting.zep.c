
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Zodium_Greeting) {

	ZEPHIR_REGISTER_CLASS(Zodium, Greeting, zodium, greeting, zodium_greeting_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Zodium_Greeting, say) {

	zval *something_param = NULL;
	zval something;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&something);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &something_param);

	zephir_get_strval(&something, something_param);


	RETURN_MM_LONG(sodium_bin2base64(&something));

}

