#pragma once
#ifndef __VMTHOOK_H__
#define __VMTHOOK_H__
// Base Headers
#include <Windows.h>

class CVMTHook
{
public:
	CVMTHook(void* instance);
	~CVMTHook();
	void* hookFunction(size_t iIndex, void* pfnHook);
	void* getOriginalFunction(size_t iIndex);
	void setHookEnabled(bool bEnabled = true);
protected:
	size_t m_iNumIndices;
	void** m_pOriginalVTable;
	void** m_pNewVTable;
	void*** m_pInstance;
};



#endif //__VMTHOOK_H__