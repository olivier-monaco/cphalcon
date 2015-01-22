
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Router\Route
 *
 * This class represents every route added to the router
 */
ZEPHIR_INIT_CLASS(Phalcon_Yowik_Router_Route) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Yowik\\Router, Route, phalcon, yowik_router_route, phalcon_mvc_router_route_ce, phalcon_yowik_router_route_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Yowik_Router_Route, handle) {

	HashTable *_7;
	HashPosition _6;
	zval *_5 = NULL, *_9 = NULL;
	zephir_nts_static zend_class_entry *_3 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL;
	zval *request, *uri_param = NULL, *router, *methods = NULL, *hostname = NULL, *currentHostName = NULL, *regexHostName = NULL, *matched = NULL, *pattern = NULL, *matches = NULL, *routeFound = NULL, *beforeMatch = NULL, *paths = NULL, *parts = NULL, *converters = NULL, *part = NULL, *position = NULL, *matchPosition = NULL, *converter = NULL, *_0 = NULL, *_2 = NULL, *_4 = NULL, **_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &request, &uri_param, &router);

	if (unlikely(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	}


	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	ZEPHIR_CALL_METHOD(&methods, this_ptr, "gethttpmethods", NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(methods) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&_0, request, "ismethod", NULL, methods);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&hostname, this_ptr, "gethostname", NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(hostname) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&currentHostName, request, "gethttphost", NULL);
		zephir_check_call_status();
		if (Z_TYPE_P(currentHostName) == IS_NULL) {
			RETURN_MM_BOOL(0);
		}
		if (zephir_memnstr_str(hostname, SL("("), "phalcon/yowik/router/route.zep", 72)) {
			if (!(zephir_memnstr_str(hostname, SL("#"), "phalcon/yowik/router/route.zep", 73))) {
				ZEPHIR_INIT_VAR(regexHostName);
				ZEPHIR_CONCAT_SVS(regexHostName, "#^", hostname, "$#");
			} else {
				ZEPHIR_CPY_WRT(regexHostName, hostname);
			}
			ZEPHIR_CALL_FUNCTION(&matched, "preg_match", &_1, regexHostName, currentHostName);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(matched);
			ZVAL_BOOL(matched, ZEPHIR_IS_EQUAL(currentHostName, hostname));
		}
		if (!(zephir_is_true(matched))) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&pattern, this_ptr, "getcompiledpattern", NULL);
	zephir_check_call_status();
	if (zephir_memnstr_str(pattern, SL("^"), "phalcon/yowik/router/route.zep", 93)) {
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(&routeFound, "preg_match", &_1, pattern, uri, matches);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(routeFound);
		ZVAL_BOOL(routeFound, ZEPHIR_IS_EQUAL(pattern, uri));
	}
	if (!(zephir_is_true(routeFound))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&beforeMatch, this_ptr, "getbeforematch", NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(beforeMatch) != IS_NULL) {
		if (!(zephir_is_callable(beforeMatch TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_2);
			if (!_3) {
				_3 = zend_fetch_class(SL("Phalcon\\Yowik\\Router\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			}
			object_init_ex(_2, _3);
			if (zephir_has_constructor(_2 TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_4);
				ZVAL_STRING(_4, "Before-Match callback is not callable in matched route", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _4);
				zephir_check_temp_parameter(_4);
				zephir_check_call_status();
			}
			zephir_throw_exception_debug(_2, "phalcon/yowik/router/route.zep", 113 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(routeFound);
		ZEPHIR_INIT_VAR(_5);
		array_init_size(_5, 4);
		zephir_array_fast_append(_5, uri);
		zephir_array_fast_append(_5, this_ptr);
		zephir_array_fast_append(_5, router);
		ZEPHIR_CALL_USER_FUNC_ARRAY(routeFound, beforeMatch, _5);
		zephir_check_call_status();
		if (!(zephir_is_true(routeFound))) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&paths, this_ptr, "getpaths", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(parts, paths);
	if (Z_TYPE_P(matches) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&converters, this_ptr, "getconverters", NULL);
		zephir_check_call_status();
		zephir_is_iterable(paths, &_7, &_6, 0, 0, "phalcon/yowik/router/route.zep", 171);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HMKEY(part, _7, _6);
			ZEPHIR_GET_HVALUE(position, _8);
			ZEPHIR_OBS_NVAR(matchPosition);
			if (zephir_array_isset_fetch(&matchPosition, matches, position, 0 TSRMLS_CC)) {
				if (Z_TYPE_P(converters) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(converter);
					if (zephir_array_isset_fetch(&converter, converters, part, 0 TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(_2);
						ZEPHIR_INIT_NVAR(_5);
						array_init_size(_5, 2);
						zephir_array_fast_append(_5, matchPosition);
						ZEPHIR_CALL_USER_FUNC_ARRAY(_2, converter, _5);
						zephir_check_call_status();
						zephir_array_update_zval(&parts, part, &_2, PH_COPY | PH_SEPARATE);
						continue;
					}
				}
				zephir_array_update_zval(&parts, part, &matchPosition, PH_COPY | PH_SEPARATE);
			} else {
				if (Z_TYPE_P(converters) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(converter);
					if (zephir_array_isset_fetch(&converter, converters, part, 0 TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(_4);
						ZEPHIR_INIT_NVAR(_9);
						array_init_size(_9, 2);
						zephir_array_fast_append(_9, position);
						ZEPHIR_CALL_USER_FUNC_ARRAY(_4, converter, _9);
						zephir_check_call_status();
						zephir_array_update_zval(&parts, part, &_4, PH_COPY | PH_SEPARATE);
					}
				}
			}
		}
	} else {
		ZEPHIR_INIT_NVAR(matches);
		ZVAL_NULL(matches);
	}
	array_init_size(return_value, 3);
	zephir_array_update_string(&return_value, SL("matches"), &matches, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("parts"), &parts, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

