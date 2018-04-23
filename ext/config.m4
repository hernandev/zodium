PHP_ARG_ENABLE(zodium, whether to enable zodium, [ --enable-zodium   Enable Zodium])

if test "$PHP_ZODIUM" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, ZODIUM_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_ZODIUM, 1, [Whether you have Zodium])
	zodium_sources="zodium.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c zodium/exceptions/zodiumexception.zep.c
	zodium/aead/cipher.zep.c
	zodium/exceptions/dataexception.zep.c
	zodium/exceptions/decryptexception.zep.c
	zodium/exceptions/encryptexception.zep.c
	zodium/exceptions/hashexception.zep.c
	zodium/hash/generichash.zep.c
	zodium/helpers/helpers.zep.c
	zodium/secretbox/encryptedpayload.zep.c
	zodium/secretbox/secretbox.zep.c "
	PHP_NEW_EXTENSION(zodium, $zodium_sources, $ext_shared,, )
	PHP_SUBST(ZODIUM_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([zodium], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([zodium], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/zodium], [php_ZODIUM.h])

fi
