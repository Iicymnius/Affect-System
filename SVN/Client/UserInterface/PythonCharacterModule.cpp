//find;

	PyModule_AddIntConstant(poModule, "NEW_AFFECT_DRAGON_SOUL_DECK2", CInstanceBase::NEW_AFFECT_DRAGON_SOUL_DECK2);

//add below;

#ifdef AFFECT_SYSTEM
	PyModule_AddIntConstant(poModule, "AFFECT_YELLOW", CInstanceBase::AFFECT_YELLOW);
	PyModule_AddIntConstant(poModule, "AFFECT_BROWN", CInstanceBase::AFFECT_BROWN);
	PyModule_AddIntConstant(poModule, "AFFECT_GREY", CInstanceBase::AFFECT_GREY);
	PyModule_AddIntConstant(poModule, "AFFECT_ORANGE", CInstanceBase::AFFECT_ORANGE);
	PyModule_AddIntConstant(poModule, "AFFECT_PINK", CInstanceBase::AFFECT_PINK);
	PyModule_AddIntConstant(poModule, "AFFECT_PURPLE", CInstanceBase::AFFECT_PURPLE);
	PyModule_AddIntConstant(poModule, "AFFECT_TURQUOISE", CInstanceBase::AFFECT_TURQUOISE);
	PyModule_AddIntConstant(poModule, "AFFECT_BLUE", CInstanceBase::AFFECT_BLUE);
	PyModule_AddIntConstant(poModule, "AFFECT_RED", CInstanceBase::AFFECT_RED);
	PyModule_AddIntConstant(poModule, "AFFECT_ELR", CInstanceBase::AFFECT_ELR);
	PyModule_AddIntConstant(poModule, "AFFECT_ELY", CInstanceBase::AFFECT_ELY);
	PyModule_AddIntConstant(poModule, "AFFECT_ELG", CInstanceBase::AFFECT_ELG);
	PyModule_AddIntConstant(poModule, "AFFECT_ELB", CInstanceBase::AFFECT_ELB);
	PyModule_AddIntConstant(poModule, "AFFECT_ELP", CInstanceBase::AFFECT_ELP);
	PyModule_AddIntConstant(poModule, "AFFECT_ELW", CInstanceBase::AFFECT_ELW);
	PyModule_AddIntConstant(poModule, "AFFECT_TORY", CInstanceBase::AFFECT_TORY);
	PyModule_AddIntConstant(poModule, "AFFECT_TORB", CInstanceBase::AFFECT_TORB);
	PyModule_AddIntConstant(poModule, "AFFECT_TORR", CInstanceBase::AFFECT_TORR);
	PyModule_AddIntConstant(poModule, "AFFECT_TORG", CInstanceBase::AFFECT_TORG);
#endif
