#pragma once
// Base
#include <Windows.h>
#include <Psapi.h>


namespace toolkit {
	namespace sigscan {
		DWORD FindPattern(char *module, char *pattern, char *mask);
		MODULEINFO GetModuleInfo(char * szModule);
		bool bDataCompare(const BYTE* pData, const char* bMask, const char* szMask);
		DWORD dwFindPattern(DWORD dwAddress, DWORD dwLen, char* bMask, char* szMask);

	}
}

