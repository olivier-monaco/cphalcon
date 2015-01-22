
extern zend_class_entry *phalcon_yowik_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_Yowik_Router);

PHP_METHOD(Phalcon_Yowik_Router, __construct);
PHP_METHOD(Phalcon_Yowik_Router, handle);
PHP_METHOD(Phalcon_Yowik_Router, add);
PHP_METHOD(Phalcon_Yowik_Router, addRoute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_yowik_router___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultRoutes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_yowik_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_yowik_router_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_yowik_router_addroute, 0, 0, 1)
	ZEND_ARG_INFO(0, route)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_yowik_router_method_entry) {
	PHP_ME(Phalcon_Yowik_Router, __construct, arginfo_phalcon_yowik_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Yowik_Router, handle, arginfo_phalcon_yowik_router_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Yowik_Router, add, arginfo_phalcon_yowik_router_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Yowik_Router, addRoute, arginfo_phalcon_yowik_router_addroute, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
