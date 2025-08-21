//find in function: void CHARACTER::ClearAffect(bool bSave)

			if (IsPC())
			{
				SendAffectRemovePacket(GetDesc(), GetPlayerID(), pkAff->dwType, pkAff->bApplyOn);
			}

//add above;

#ifdef AFFECT_SYSTEM
			std::initializer_list<int> ignoreTypes =
			{
				AFFECT_YELLOW, AFFECT_BROWN, AFFECT_GREY,
				AFFECT_ELR, AFFECT_ELY, AFFECT_ELG,
				AFFECT_ELB, AFFECT_ELP, AFFECT_ELW,
				AFFECT_ORANGE, AFFECT_PINK, AFFECT_PURPLE,
				AFFECT_TURQUOISE, AFFECT_BLUE, AFFECT_RED,
				AFFECT_TORY, AFFECT_TORB, AFFECT_TORR, AFFECT_TORG
			};

			if (std::find(ignoreTypes.begin(), ignoreTypes.end(), pkAff->dwType) != ignoreTypes.end())
			{
				++it;
				continue;
			}
#endif
