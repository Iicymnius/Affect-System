//find;

#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 0);
#endif

//add below;

#ifdef AFFECT_SYSTEM
	PyModule_AddIntConstant(poModule, "AFFECT_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "AFFECT_SYSTEM", 0);
#endif
