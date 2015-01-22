
extern zend_class_entry *phalcon_yowik_router_route_ce;

ZEPHIR_INIT_CLASS(Phalcon_Yowik_Router_Route);

PHP_METHOD(Phalcon_Yowik_Router_Route, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_yowik_router_route_handle, 0, 0, 3)
	ZEND_ARG_INFO(0, request)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, router)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_yowik_router_route_method_entry) {
	PHP_ME(Phalcon_Yowik_Router_Route, handle, arginfo_phalcon_yowik_router_route_handle, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
