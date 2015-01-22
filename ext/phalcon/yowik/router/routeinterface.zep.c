
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * Phalcon\Mvc\Router\RouteInterface
 *
 * Interface for Phalcon\Mvc\Router\Route
 */
ZEPHIR_INIT_CLASS(Phalcon_Yowik_Router_RouteInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Yowik\\Router, RouteInterface, phalcon, yowik_router_routeinterface, phalcon_yowik_router_routeinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the route's name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Yowik_Router_RouteInterface, getName);

/**
 * Returns the route's id
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Yowik_Router_RouteInterface, getRouteId);

ZEPHIR_DOC_METHOD(Phalcon_Yowik_Router_RouteInterface, handle);

