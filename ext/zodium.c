
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "zodium.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *zodium_exceptions_zodiumexception_ce;
zend_class_entry *zodium_aead_cipher_ce;
zend_class_entry *zodium_exceptions_dataexception_ce;
zend_class_entry *zodium_exceptions_decryptexception_ce;
zend_class_entry *zodium_exceptions_encryptexception_ce;
zend_class_entry *zodium_helpers_helpers_ce;
zend_class_entry *zodium_secretbox_encryptedpayload_ce;
zend_class_entry *zodium_secretbox_secretbox_ce;

ZEND_DECLARE_MODULE_GLOBALS(zodium)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(zodium)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Zodium_Exceptions_ZodiumException);
	ZEPHIR_INIT(Zodium_AEAD_Cipher);
	ZEPHIR_INIT(Zodium_Exceptions_DataException);
	ZEPHIR_INIT(Zodium_Exceptions_DecryptException);
	ZEPHIR_INIT(Zodium_Exceptions_EncryptException);
	ZEPHIR_INIT(Zodium_Helpers_Helpers);
	ZEPHIR_INIT(Zodium_SecretBox_EncryptedPayload);
	ZEPHIR_INIT(Zodium_SecretBox_SecretBox);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(zodium)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_zodium_globals *zodium_globals TSRMLS_DC)
{
	zodium_globals->initialized = 0;

	/* Memory options */
	zodium_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zodium_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	zodium_globals->cache_enabled = 1;

	/* Recursive Lock */
	zodium_globals->recursive_lock = 0;

	/* Static cache */
	memset(zodium_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_zodium_globals *zodium_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(zodium)
{

	zend_zodium_globals *zodium_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	zodium_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zodium_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(zodium_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(zodium)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(zodium)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_ZODIUM_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_ZODIUM_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_ZODIUM_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_ZODIUM_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_ZODIUM_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(zodium)
{
	php_zephir_init_globals(zodium_globals TSRMLS_CC);
	php_zephir_init_module_globals(zodium_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(zodium)
{

}


zend_function_entry php_zodium_functions[] = {
ZEND_FE_END

};

zend_module_entry zodium_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_ZODIUM_EXTNAME,
	php_zodium_functions,
	PHP_MINIT(zodium),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(zodium),
#else
	NULL,
#endif
	PHP_RINIT(zodium),
	PHP_RSHUTDOWN(zodium),
	PHP_MINFO(zodium),
	PHP_ZODIUM_VERSION,
	ZEND_MODULE_GLOBALS(zodium),
	PHP_GINIT(zodium),
	PHP_GSHUTDOWN(zodium),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_ZODIUM
ZEND_GET_MODULE(zodium)
#endif
