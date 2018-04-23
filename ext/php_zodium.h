
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_ZODIUM_H
#define PHP_ZODIUM_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_ZODIUM_NAME        "zodium"
#define PHP_ZODIUM_VERSION     "0.0.1"
#define PHP_ZODIUM_EXTNAME     "zodium"
#define PHP_ZODIUM_AUTHOR      "Diego Hernandes <diego@hernandev.com>"
#define PHP_ZODIUM_ZEPVERSION  "0.9.11-534bd284df"
#define PHP_ZODIUM_DESCRIPTION "OOP Wrapper for the PHP 7.2+ Sodium Extension (libsodium)"



ZEND_BEGIN_MODULE_GLOBALS(zodium)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(zodium)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(zodium)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(zodium, v)
#else
	#define ZEPHIR_GLOBAL(v) (zodium_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_zodium_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(zodium_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(zodium_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def zodium_globals
#define zend_zephir_globals_def zend_zodium_globals

extern zend_module_entry zodium_module_entry;
#define phpext_zodium_ptr &zodium_module_entry

#endif
