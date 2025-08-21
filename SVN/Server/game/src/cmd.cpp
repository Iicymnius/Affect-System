//find;

struct command_info cmd_info[] =

//add above;

#ifdef AFFECT_SYSTEM
ACMD(do_affect_give);
ACMD(do_affect_delete);
#endif

//find again;

			{ "\n",		NULL,			0,			POS_DEAD,	GM_IMPLEMENTOR	}

//add above;

#ifdef AFFECT_SYSTEM
	{ "affect_give",			do_affect_give,			0,			POS_DEAD,	GM_PLAYER	},
	{ "affect_delete",			do_affect_delete,		0,			POS_DEAD,	GM_PLAYER	},
#endif
