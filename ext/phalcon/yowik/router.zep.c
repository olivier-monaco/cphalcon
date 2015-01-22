
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"
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
 * Phalcon\Mvc\Router
 *
 * <p>Phalcon\Mvc\Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request</p>
 *
 *<code>
 *
 *	$router = new Router();
 *
 *	$router->add(
 *		"/documentation/{chapter}/{name}.{type:[a-z]+}",
 *		array(
 *			"controller" => "documentation",
 *			"action"     => "show"
 *		)
 *	);
 *
 *	$router->handle();
 *
 *	echo $router->getControllerName();
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Yowik_Router) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Yowik, Router, phalcon, yowik_router, phalcon_mvc_router_ce, phalcon_yowik_router_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Router constructor
 *
 * @param boolean defaultRoutes
 */
PHP_METHOD(Phalcon_Yowik_Router, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1, *_3;
	zval *defaultRoutes_param = NULL, *routes, *_0 = NULL, *_2 = NULL, *_4;
	zend_bool defaultRoutes;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);

	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
		defaultRoutes = zephir_get_boolval(defaultRoutes_param);
	}


	ZEPHIR_INIT_VAR(routes);
	array_init(routes);
	if (defaultRoutes == 1) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_yowik_router_route_ce);
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 2);
		add_assoc_long_ex(_1, SS("controller"), 1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "#^/([a-zA-Z0-9\\_\\-]+)[/]{0,1}$#", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2, _1);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_append(&routes, _0, PH_SEPARATE, "phalcon/yowik/router.zep", 72);
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, phalcon_yowik_router_route_ce);
		ZEPHIR_INIT_VAR(_3);
		array_init_size(_3, 4);
		add_assoc_long_ex(_3, SS("controller"), 1);
		add_assoc_long_ex(_3, SS("action"), 2);
		add_assoc_long_ex(_3, SS("params"), 3);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "#^/([a-zA-Z0-9\\_\\-]+)/([a-zA-Z0-9\\.\\_]+)(/.*)*$#", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _4, _3);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		zephir_array_append(&routes, _2, PH_SEPARATE, "phalcon/yowik/router.zep", 78);
	}
	ZEPHIR_INIT_NVAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_params"), _0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_defaultParams"), _2 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_routes"), routes TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles routing information received from the rewrite engine
 *
 *<code>
 * //Read the info from the rewrite engine
 * $router->handle();
 *
 * //Manually passing an URL
 * $router->handle('/posts/edit/1');
 *</code>
 *
 * @param string uri
 */
PHP_METHOD(Phalcon_Yowik_Router, handle) {

	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL;
	HashTable *_6;
	HashPosition _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool routeFound;
	zval *uri = NULL, *realUri = NULL, *request = NULL, *parts = NULL, *params = NULL, *matches = NULL, *notFoundPaths, *vnamespace, *module, *controller, *action, *paramsStr, *strParams = NULL, *route = NULL, *dependencyInjector = NULL, *handledUri = NULL, *_0, _1 = zval_used_for_init, *_2, *_3 = NULL, *_4 = NULL, **_7, *_8, *_9, *_11, *_12, *_13, *_14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_true(uri))) {
		ZEPHIR_CALL_METHOD(&realUri, this_ptr, "getrewriteuri", NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(realUri, uri);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_removeExtraSlashes"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		if (!ZEPHIR_IS_STRING(realUri, "/")) {
			ZEPHIR_INIT_VAR(handledUri);
			ZEPHIR_SINIT_VAR(_1);
			ZVAL_STRING(&_1, "/", 0);
			zephir_fast_trim(handledUri, realUri, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(handledUri, realUri);
		}
	} else {
		ZEPHIR_CPY_WRT(handledUri, realUri);
	}
	ZEPHIR_INIT_VAR(request);
	ZVAL_NULL(request);
	routeFound = 0;
	ZEPHIR_INIT_VAR(parts);
	array_init(parts);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	zephir_update_property_this(this_ptr, SL("_wasMatched"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_matchedRoute"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _2);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'request' service", "phalcon/yowik/router.zep", 142);
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, dependencyInjector, "getshared", NULL, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(request, _3);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_2, &_6, &_5, 0, 1, "phalcon/yowik/router.zep", 163);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_backwards_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(route, _7);
		ZEPHIR_CALL_METHOD(&matches, route, "handle", NULL, request, handledUri, this_ptr);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(matches)) {
			zephir_array_fetch_string(&_8, matches, SL("matches"), PH_NOISY | PH_READONLY, "phalcon/yowik/router.zep", 152 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_matches"), _8 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(parts);
			zephir_array_fetch_string(&parts, matches, SL("parts"), PH_NOISY, "phalcon/yowik/router.zep", 153 TSRMLS_CC);
			routeFound = 1;
			zephir_update_property_this(this_ptr, SL("_matchedRoute"), route TSRMLS_CC);
			break;
		}
	}
	if (routeFound) {
		zephir_update_property_this(this_ptr, SL("_wasMatched"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_wasMatched"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (!(routeFound)) {
		ZEPHIR_OBS_VAR(notFoundPaths);
		zephir_read_property_this(&notFoundPaths, this_ptr, SL("_notFoundPaths"), PH_NOISY_CC);
		if (Z_TYPE_P(notFoundPaths) != IS_NULL) {
			ZEPHIR_CPY_WRT(parts, notFoundPaths);
			routeFound = 1;
		}
	}
	if (routeFound) {
		ZEPHIR_OBS_VAR(vnamespace);
		if (zephir_array_isset_string_fetch(&vnamespace, parts, SS("namespace"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(vnamespace))) {
				zephir_update_property_this(this_ptr, SL("_namespace"), vnamespace TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("namespace"), PH_SEPARATE);
		} else {
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_namespace"), _9 TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(module);
		if (zephir_array_isset_string_fetch(&module, parts, SS("module"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(module))) {
				zephir_update_property_this(this_ptr, SL("_module"), module TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("module"), PH_SEPARATE);
		} else {
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_module"), _9 TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(controller);
		if (zephir_array_isset_string_fetch(&controller, parts, SS("controller"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(controller))) {
				zephir_update_property_this(this_ptr, SL("_controller"), controller TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("controller"), PH_SEPARATE);
		} else {
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultController"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_controller"), _9 TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(action);
		if (zephir_array_isset_string_fetch(&action, parts, SS("action"), 0 TSRMLS_CC)) {
			if (!(zephir_is_numeric(action))) {
				zephir_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("action"), PH_SEPARATE);
		} else {
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
			zephir_update_property_this(this_ptr, SL("_action"), _9 TSRMLS_CC);
		}
		ZEPHIR_OBS_VAR(paramsStr);
		if (zephir_array_isset_string_fetch(&paramsStr, parts, SS("params"), 0 TSRMLS_CC)) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 1);
			ZEPHIR_CALL_FUNCTION(&strParams, "substr", &_10, paramsStr, &_1);
			zephir_check_call_status();
			if (zephir_is_true(strParams)) {
				ZEPHIR_INIT_NVAR(params);
				zephir_fast_explode_str(params, SL("/"), strParams, LONG_MAX TSRMLS_CC);
			}
			zephir_array_unset_string(&parts, SS("params"), PH_SEPARATE);
		}
		if (zephir_fast_count_int(params TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_4);
			zephir_fast_array_merge(_4, &(params), &(parts) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_params"), _4 TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_params"), parts TSRMLS_CC);
		}
	} else {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultNamespace"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_namespace"), _9 TSRMLS_CC);
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_module"), _11 TSRMLS_CC);
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultController"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_controller"), _12 TSRMLS_CC);
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_action"), _13 TSRMLS_CC);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultParams"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_params"), _14 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a route to the router without any HTTP constraint
 *
 *<code>
 * $router->add('/about', 'About::index');
 *</code>
 *
 * @param string pattern
 * @param string/array paths
 * @param string httpMethods
 * @return Phalcon\Mvc\Router\Route
 */
PHP_METHOD(Phalcon_Yowik_Router, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *httpMethods = NULL, *route;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!httpMethods) {
		httpMethods = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(route);
	object_init_ex(route, phalcon_yowik_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, route, "__construct", NULL, pattern, paths, httpMethods);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_routes"), route TSRMLS_CC);
	RETURN_CCTOR(route);

}

PHP_METHOD(Phalcon_Yowik_Router, addRoute) {

	zval *route;

	zephir_fetch_params(0, 1, 0, &route);



	zephir_update_property_array_append(this_ptr, SL("_routes"), route TSRMLS_CC);

}

