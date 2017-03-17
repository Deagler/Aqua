//Toolkit
#include "sigscan.h"


/*REDO ALL THIS*/
DWORD toolkit::sigscan::FindPattern(char *module, char *pattern, char *mask)
{
	MODULEINFO mInfo = GetModuleInfo(module);

	DWORD base = (DWORD)mInfo.lpBaseOfDll;
	DWORD size = (DWORD)mInfo.SizeOfImage;

	DWORD patternLength = (DWORD)strlen(mask);

	for (DWORD i = 0; i < size - patternLength; i++)
	{
		bool found = true;
		for (DWORD j = 0; j<patternLength; j++)
		{
			found &= mask[j] == '?' || pattern[j] == *(char*)(base + i + j);
		}
		if (found)
		{
			return base + i;
		}
	}
	return NULL;
}

MODULEINFO toolkit::sigscan::GetModuleInfo(char * szModule)
{
	MODULEINFO modInfo = { 0 };
	HMODULE hModule = GetModuleHandle(szModule);
	if (hModule == 0)
	{
		return modInfo;
	}

	GetModuleInformation(GetCurrentProcess(), hModule, &modInfo, sizeof(MODULEINFO));
	return (modInfo);
}


bool toolkit::sigscan::bDataCompare(const BYTE* pData, const char* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
	if (*szMask == 'x' && *pData != *bMask)
		return false;
	return (*szMask) == NULL;
}

DWORD toolkit::sigscan::dwFindPattern(DWORD dwAddress, DWORD dwLen, char* bMask, char* szMask)
{
	for (DWORD i = 0; i < dwLen; i++)
	{
		if (bDataCompare((BYTE*)(dwAddress + i), bMask, szMask))
			return (DWORD)(dwAddress + i);
	}
	return 0;
}
