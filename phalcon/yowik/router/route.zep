
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

namespace Phalcon\Yowik\Router;

use Phalcon\Yowik\Router\Exception;

/**
 * Phalcon\Mvc\Router\Route
 *
 * This class represents every route added to the router
 */
class Route extends \Phalcon\Mvc\Router\Route
{
	public function handle(request, string! uri, router) -> array | boolean
	{
		var methods, hostname, currentHostName, regexHostName, matched,
			pattern, matches, routeFound, beforeMatch, paths, parts,
			converters, part, position, matchPosition, converter;

		let matches = null;

		/**
		 * Look for HTTP method constraints
		 */
		let methods = this->getHttpMethods();
		if methods !== null {
			/**
			 * Check if the current method is allowed by the route
			 */
			if request->isMethod(methods) === false {
				return false;
			}
		}

		/**
		 * Look for hostname constraints
		 */
		let hostname = this->getHostName();
		if hostname !== null {
			/**
			 * Check if the current hostname is the same as the route
			 */
			let currentHostName = request->getHttpHost();

			/**
			 * No HTTP_HOST, maybe in CLI mode?
			 */
			if typeof currentHostName == "null" {
				return false;
			}

			/**
			 * Check if the hostname restriction is the same as the current in the route
			 */
			if memstr(hostname, "(") {
				if !memstr(hostname, "#") {
					let regexHostName = "#^" . hostname . "$#";
				} else {
					let regexHostName = hostname;
				}
				let matched = preg_match(regexHostName, currentHostName);
			} else {
				let matched = currentHostName == hostname;
			}

			if !matched {
				return false;
			}
		}

		/**
		 * If the route has parentheses use preg_match
		 */
		let pattern = this->getCompiledPattern();

		if memstr(pattern, "^") {
			let routeFound = preg_match(pattern, uri, matches);
		} else {
			let routeFound = pattern == uri;
		}

		if !routeFound {
			return false;
		}

		/**
		 * Check for beforeMatch conditions
		 */
		let beforeMatch = this->getBeforeMatch();
		if beforeMatch !== null {

			/**
			 * Check first if the callback is callable
			 */
			if !is_callable(beforeMatch) {
				throw new Exception("Before-Match callback is not callable in matched route");
			}

			/**
			 * Check first if the callback is callable
			 */
			let routeFound = call_user_func_array(beforeMatch, [uri, this, router]);

			if !routeFound {
				return false;
			}
		}

		/**
		 * Start from the default paths
		 */
		let paths = this->getPaths(), parts = paths;

		/**
		 * Check if the matches has variables
		 */
		if typeof matches == "array" {

			/**
			 * Get the route converters if any
			 */
			let converters = this->getConverters();

			for part, position in paths {

				if fetch matchPosition, matches[position] {

					/**
					 * Check if the part has a converter
					 */
					if typeof converters == "array" {
						if fetch converter, converters[part] {
							let parts[part] = call_user_func_array(converter, [matchPosition]);
							continue;
						}
					}

					/**
					 * Update the parts if there is no converter
					 */
					let parts[part] = matchPosition;
				} else {

					/**
					 * Apply the converters anyway
					 */
					if typeof converters == "array" {
						if fetch converter, converters[part] {
							let parts[part] = call_user_func_array(converter, [position]);
						}
					}
				}
			}
		}

		else {
			let matches = null;
		}


		return [
			"matches": matches,
			"parts": parts
		];
	}
}
