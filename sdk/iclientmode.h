#pragma once

//Misc
#include "getvfunc.h"

//SDK
#include "usercmd.h"

class IClientMode
{
public:

	bool ShouldDrawFog()
	{
		typedef bool(__thiscall * vfunc)(void *);
		return(getvfunc<vfunc>(this, vfuncs::IClientMode::ShouldDrawFog)(this));
	}

	void CreateMove(float flInputSampleTime, void *cmd)
	{
		typedef void(__thiscall * vfunc)(void *, float, void *);
		return(getvfunc<vfunc>(this, vfuncs::IClientMode::CreateMove)(this, flInputSampleTime, cmd));
	}

};
