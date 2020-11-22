//Search

BOOL CInstanceBase::IsWearingDress()

//Add above(If ACCE_SYSTEM)

#ifdef ENABLE_WEDDING_FIX
BOOL CInstanceBase::__IsChangeableAcce(int iAcceID)
{

	if (IsWearingDress())
	{
		const int c_iAcce[] =
		{
			0, // Insert Here excluded value
		};

		for (int i = 0; c_iAcce[i] != 0; ++i)
			if (iAcceID == c_iAcce[i])
				return true;

		return false;
	}
	else
		return true;
}

BOOL CInstanceBase::__IsChangeableHair(int iHairID)
{

	if (IsWearingDress())
	{
		const int c_iHair[] =
		{
			0, // Insert Here excluded value
		};

		for (int i = 0; c_iHair[i] != 0; ++i)
			if (iHairID == c_iHair[i])
				return true;

		return false;
	}
	else
		return true;
}
#endif

//Else (If SASH_SYSTEM)

#ifdef ENABLE_WEDDING_FIX
BOOL CInstanceBase::__IsChangeableSash(int iSashID)
{

	if (IsWearingDress())
	{
		const int c_iSash[] =
		{
			0, // Insert Here excluded value
		};

		for (int i = 0; c_iSash[i] != 0; ++i)
			if (iSashID == c_iSash[i])
				return true;

		return false;
	}
	else
		return true;
}

BOOL CInstanceBase::__IsChangeableHair(int iHairID)
{

	if (IsWearingDress())
	{
		const int c_iHair[] =
		{
			0, // Insert Here excluded value
		};

		for (int i = 0; c_iHair[i] != 0; ++i)
			if (iHairID == c_iHair[i])
				return true;

		return false;
	}
	else
		return true;
}
#endif

//If ACCE_SYSTEM
//Search in void CInstanceBase::SetAcce(DWORD dwAcce)

	if (IsPoly())
		return;
	
//Add under

#ifdef ENABLE_WEDDING_FIX
	if (__IsChangeableAcce(dwAcce) == false)
		dwAcce = 0;
#endif

//Else If SASH_SYSTEM

#ifdef ENABLE_WEDDING_FIX
	if (__IsChangeableSash(dwSash) == false)
		dwSash = 0;
#endif
	
//Search in void CInstanceBase::SetHair(DWORD eHair)

	if (IsPC()==false)
		return;
	
//Add above

#ifdef ENABLE_WEDDING_FIX
	if (__IsChangeableHair(eHair) == false)
		eHair = 0;
#endif
