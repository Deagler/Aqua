#pragma once
//SDK
#include "getvfunc.h"

class IPanel
{
public:
	const char *GetName(unsigned int vguiPanel)
	{
		typedef const char *(__thiscall* vfunc)(void*, unsigned int);
		return(getvfunc<vfunc>(this, vfuncs::IPanel::GetName)(this, vguiPanel));
	}

	void PaintTraverse(unsigned int vguiPanel, bool forceRepaint, bool allowForce = true)
	{
		typedef void(__thiscall* vfunc)(void*, unsigned int);
		return(getvfunc<vfunc>(this, vfuncs::IPanel::PaintTraverse)(this, vguiPanel));
	}
};
