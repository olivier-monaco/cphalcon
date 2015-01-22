
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

namespace Phalcon\Yowik;

use Phalcon\DiInterface;
use Phalcon\Yowik\Router\Route;
use Phalcon\Mvc\Router\Exception;
use Phalcon\Http\RequestInterface;

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
class Router extends \Phalcon\Mvc\Router
{
	/**
	 * Phalcon\Mvc\Router constructor
	 *
	 * @param boolean defaultRoutes
	 */
	public function __construct(boolean defaultRoutes = true)
	{
		var routes;

		let routes = [];
		if defaultRoutes === true {

			// Two routes are added by default to match /:controller/:action and
			// /:controller/:action/:params

			let routes[] = new Route("#^/([a-zA-Z0-9\\_\\-]+)[/]{0,1}$#", [
				"controller": 1
			]);

			let routes[] = new Route("#^/([a-zA-Z0-9\\_\\-]+)/([a-zA-Z0-9\\.\\_]+)(/.*)*$#", [
				"controller": 1,
				"action": 2,
				"params": 3
			]);
		}

		let this->_params = [],
			this->_defaultParams = [],
			this->_routes = routes;
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
	public function handle(uri = null)
	{
		var realUri, request, routeFound, parts,
			params, matches, notFoundPaths,
			vnamespace, module,  controller, action, paramsStr, strParams,
			route, dependencyInjector,
			handledUri;

		if !uri {
			/**
			 * If 'uri' isn't passed as parameter it reads _GET['_url']
			 */
			let realUri = this->getRewriteUri();
		} else {
			let realUri = uri;
		}

		/**
		 * Remove extra slashes in the route
		 */
		if this->_removeExtraSlashes {
			if realUri != "/" {
				let handledUri = rtrim(realUri, "/");
			} else {
				let handledUri = realUri;
			}
		} else {
			let handledUri = realUri;
		}

		let request = null,
			routeFound = false,
			parts = [],
			params = [],
			matches = null,
			this->_wasMatched = false,
			this->_matchedRoute = null;

		/**
		 * Retrieve the request service from the container
		 */
		let dependencyInjector = <\Phalcon\DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection container is required to access the 'request' service");
		}
		let request = <RequestInterface> dependencyInjector->getShared("request");

		/**
		 * Routes are traversed in reversed order
		 */
		for route in reverse this->_routes {
			let matches = route->handle(request, handledUri, this);
			if matches !== false {
				let this->_matches = matches["matches"];
				let parts = matches["parts"];
				let routeFound = true;
				let this->_matchedRoute = route;
				break;
			}
		}

		/**
		 * Update the wasMatched property indicating if the route was matched
		 */
		if routeFound {
			let this->_wasMatched = true;
		} else {
			let this->_wasMatched = false;
		}

		/**
		 * The route wasn't found, try to use the not-found paths
		 */
		if !routeFound {
			let notFoundPaths = this->_notFoundPaths;
			if notFoundPaths !== null {
				let parts = notFoundPaths,
					routeFound = true;
			}
		}

		if routeFound {

			/**
			 * Check for a namespace
			 */
			if fetch vnamespace, parts["namespace"] {
				if !is_numeric(vnamespace) {
					let this->_namespace = vnamespace;
				}
				unset parts["namespace"];
			} else {
				let this->_namespace = this->_defaultNamespace;
			}

			/**
			 * Check for a module
			 */
			if fetch module, parts["module"] {
				if !is_numeric(module) {
					let this->_module = module;
				}
				unset parts["module"];
			} else {
				let this->_module = this->_defaultModule;
			}

			/**
			 * Check for a controller
			 */
			if fetch controller, parts["controller"] {
				if !is_numeric(controller) {
					let this->_controller = controller;
				}
				unset parts["controller"];
			} else {
				let this->_controller = this->_defaultController;
			}

			/**
			 * Check for an action
			 */
			if fetch action, parts["action"] {
				if !is_numeric(action) {
					let this->_action = action;
				}
				unset parts["action"];
			} else {
				let this->_action = this->_defaultAction;
			}

			/**
			 * Check for parameters
			 */
			if fetch paramsStr, parts["params"] {
				let strParams = substr(paramsStr, 1);
				if strParams {
					let params = explode("/", strParams);
				}
				unset parts["params"];
			}

			if count(params) {
				let this->_params = array_merge(params, parts);
			} else {
				let this->_params = parts;
			}

		} else {

			/**
			 * Use default values if the route hasn't matched
			 */
			let this->_namespace = this->_defaultNamespace,
				this->_module = this->_defaultModule,
				this->_controller = this->_defaultController,
				this->_action = this->_defaultAction,
				this->_params = this->_defaultParams;
		}
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
	public function add(string! pattern, paths = null, httpMethods = null) -> <Route>
	{
		var route;

		/**
		 * Every route is internally stored as a Phalcon\Mvc\Router\Route
		 */
		let route = new Route(pattern, paths, httpMethods),
			this->_routes[] = route;
		return route;
	}

	public function addRoute(route)
	{
		// TODO check route type
		let this->_routes[] = route;
	}
}
