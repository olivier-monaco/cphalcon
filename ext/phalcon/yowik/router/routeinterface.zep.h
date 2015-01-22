
extern zend_class_entry *phalcon_yowik_router_routeinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Yowik_Router_RouteInterface);

ZEPHIR_INIT_FUNCS(phalcon_yowik_router_routeinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Yowik_Router_RouteInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Yowik_Router_RouteInterface, getRouteId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Yowik_Router_RouteInterface, handle, NULL)
  PHP_FE_END
};
