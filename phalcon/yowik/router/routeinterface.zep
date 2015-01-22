
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

/**
 * Phalcon\Mvc\Router\RouteInterface
 *
 * Interface for Phalcon\Mvc\Router\Route
 */
interface RouteInterface
{
	/**
	 * Returns the route's name
	 *
	 * @return string
	 */
	public function getName();

	/**
	 * Returns the route's id
	 *
	 * @return string
	 */
	public function getRouteId();

	public function handle();
}