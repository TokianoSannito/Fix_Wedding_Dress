//Search
	if (iWearCell != WEAR_ARROW && IsPolymorphed())
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("µÐ°© Áß¿¡´Â Âø¿ëÁßÀÎ Àåºñ¸¦ º¯°æÇÒ ¼ö ¾ø½À´Ï´Ù."));
		return false;
	}

//Add above

#ifdef ENABLE_WEDDING_FIX
	LPITEM armor = GetWear(WEAR_BODY);
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if ((item->GetSubType() == UNIQUE_SPECIAL_RIDE) && (iWearCell == WEAR_UNIQUE1 || iWearCell == WEAR_UNIQUE2))
	{
		if (armor && armor->GetVnum() >= 11901 && armor->GetVnum() <= 11904)
		{	
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Non puoi cavalcare con uno Smoking o Abito da Sposa."));
			return false;		
		}
	}

#else

	if (iWearCell == WEAR_COSTUME_MOUNT && (item->GetSubType() == COSTUME_MOUNT))
	{
		if (armor && armor->GetVnum() >= 11901 && armor->GetVnum() <= 11904)
		{	
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Non puoi cavalcare con uno Smoking o Abito da Sposa."));
			return false;		
		}
	}
#endif

	if (iWearCell == WEAR_COSTUME_BODY && (item->GetSubType() == COSTUME_BODY))
	{
		if (armor && armor->GetVnum() >= 11901 && armor->GetVnum() <= 11904)
		{	
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Non puoi usare un Costume con uno Smoking o Abito da Sposa."));
			return false;
		}
	}
	
	LPITEM CostumeBody = GetWear(WEAR_COSTUME_BODY);
	if (CostumeBody)
	{
		if (item->GetVnum() >= 11901 && item->GetVnum() <= 11904)
		{
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Devi rimuovere il Costume per usarlo."));
			return false;
		}
	}
#endif

//Search (If ACCE_SYSTEM)

		else if ((item->GetType() == ITEM_COSTUME) && (item->GetSubType() == COSTUME_ACCE))
				this->EffectPacket(SE_EFFECT_ACCE_EQUIP);

//Replace with
		else if ((item->GetType() == ITEM_COSTUME) && (item->GetSubType() == COSTUME_ACCE))
#ifdef ENABLE_WEDDING_FIX			
			if (armor && armor->GetVnum() != 11901 && armor->GetVnum() != 11902 && armor->GetVnum() != 11903 && armor->GetVnum() != 11904)
				this->EffectPacket(SE_EFFECT_ACCE_EQUIP);
			else if (!(armor))
#endif
				this->EffectPacket(SE_EFFECT_ACCE_EQUIP);

			
//Else Search (if SASH_SYSTEM)

		else if ((item->GetType() == ITEM_COSTUME) && (item->GetSubType() == COSTUME_SASH))
				this->EffectPacket(SE_EFFECT_SASH_EQUIP);
			
//Replace with

		else if ((item->GetType() == ITEM_COSTUME) && (item->GetSubType() == COSTUME_SASH))
#ifdef ENABLE_WEDDING_FIX			
			if (armor && armor->GetVnum() != 11901 && armor->GetVnum() != 11902 && armor->GetVnum() != 11903 && armor->GetVnum() != 11904)
				this->EffectPacket(SE_EFFECT_SASH_EQUIP);
			else if (!(armor))
#endif				
				this->EffectPacket(SE_EFFECT_SASH_EQUIP);			