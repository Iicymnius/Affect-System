//add to bottom;

#ifdef AFFECT_SYSTEM
ACMD(do_affect_give)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));

	if (ch->CountSpecifyItem(90005) < 1)
	{
		ch->ChatPacket(CHAT_TYPE_INFO,"Envanterinde Su Taşı yok iken bu efekti alamazsın.");
		return;
	}
	
	if (ch->IsDead() || !ch->IsPC())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Ölü iken bu işlemi yapamazsın.");
		return;
	}

	if (*arg1)
	{
		static const struct AffectData {
			char key;
			int affectConst;
			int flagConst;
		} affectTable[] = {
			{ 'a', AFFECT_YELLOW,     AFF_YELLOW },
			{ 'b', AFFECT_BROWN,      AFF_BROWN },
			{ 'c', AFFECT_GREY,       AFF_GREY },
			{ 'd', AFFECT_ORANGE,     AFF_ORANGE },
			{ 'e', AFFECT_PINK,       AFF_PINK },
			{ 'f', AFFECT_PURPLE,     AFF_PURPLE },
			{ 'g', AFFECT_TURQUOISE,  AFF_TURQUOISE },
			{ 'h', AFFECT_BLUE,       AFF_BLUE },
			{ 'j', AFFECT_RED,        AFF_RED },
			{ 'k', AFFECT_ELR,        AFF_ELR },
			{ 'l', AFFECT_ELY,        AFF_ELY },
			{ 'm', AFFECT_ELG,        AFF_ELG },
			{ 'n', AFFECT_ELB,        AFF_ELB },
			{ 'o', AFFECT_ELP,        AFF_ELP },
			{ 'p', AFFECT_ELW,        AFF_ELW },
			{ 'q', AFFECT_TORY,       AFF_TORY },
			{ 'r', AFFECT_TORB,       AFF_TORB },
			{ 's', AFFECT_TORR,       AFF_TORR },
			{ 't', AFFECT_TORG,       AFF_TORG },
		};

		const int affectsToRemove[] = {
			AFFECT_YELLOW, AFFECT_BROWN, AFFECT_GREY, AFFECT_ORANGE,
			AFFECT_PINK, AFFECT_PURPLE, AFFECT_TURQUOISE, AFFECT_BLUE,
			AFFECT_RED, AFFECT_ELR, AFFECT_ELY, AFFECT_ELG,
			AFFECT_ELB, AFFECT_ELP, AFFECT_ELW,
			AFFECT_TORY, AFFECT_TORB, AFFECT_TORR, AFFECT_TORG
		};

		constexpr int EFFECT_DURATION = 3 * 24 * 60 * 60; // 3 gün (saniye cinsinden)

		char key = LOWER(*arg1);

		for (auto& data : affectTable)
		{
			if (data.key == key)
			{
				if (ch->FindAffect(data.affectConst))
				{
					ch->ChatPacket(CHAT_TYPE_INFO, "Bu efekt zaten aktif. Süresi bitene kadar yeniden ekleyemezsin.");
					break;
				}

				for (int aff : affectsToRemove)
					ch->RemoveAffect(aff);

				ch->AddAffect(data.affectConst, POINT_NONE, 0, data.flagConst, EFFECT_DURATION, 0, false);
				ch->RemoveSpecifyItem(90005, 1);

				ch->ChatPacket(CHAT_TYPE_INFO, "Efekt uygulandı. 3 gün sonra sona erecek.");
				break;
			}
		}
	}
}

ACMD(do_affect_delete)
{
	if (ch->IsDead() || !ch->IsPC())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Ölü iken bu işlemi yapamazsın.");
		return;
	}

	static const int affectsToRemove[] = {
		AFFECT_YELLOW, AFFECT_BROWN, AFFECT_GREY, AFFECT_ORANGE,
		AFFECT_PINK, AFFECT_PURPLE, AFFECT_TURQUOISE, AFFECT_BLUE,
		AFFECT_RED, AFFECT_ELR, AFFECT_ELY, AFFECT_ELG,
		AFFECT_ELB, AFFECT_ELP, AFFECT_ELW,
		AFFECT_TORY, AFFECT_TORB, AFFECT_TORR, AFFECT_TORG
	};

	for (int aff : affectsToRemove)
		ch->RemoveAffect(aff);

	ch->ChatPacket(CHAT_TYPE_INFO, "Efekt başarıyla silindi.");
}

#endif
