#pragma once
// Misc
#include "getvfunc.h"

// SDK
#include "clientclass.h"

class CHLClient
{
public:
	ClientClass * GetAllClasses() // ClientClass
	{
		typedef ClientClass * (__thiscall * vfunc)(void *);
		return(getvfunc<vfunc>(this, vfuncs::CHLClient::GetAllClasses)(this));
	}

	void IN_ActivateMouse()
	{
		typedef void(__thiscall * vfunc)(void *);
		return(getvfunc<vfunc>(this, vfuncs::CHLClient::IN_ActivateMouse)(this));
	}

	void CreateMove(int sequence_number, float input_sample_frametime, bool active)
	{
		typedef void(__thiscall * vfunc)(void *, int, float, bool);
		return(getvfunc<vfunc>(this, vfuncs::CHLClient::CreateMove)(this, sequence_number, input_sample_frametime, active));
	}

	bool WriteUserCmdDeltaToBuffer(void *buf, int from, int to, bool isnewcommand) // bf_write
	{
		typedef bool(__thiscall * vfunc)(void *, void *, int, int, bool);
		return(getvfunc<vfunc>(this, vfuncs::CHLClient::WriteUserCmdDeltaToBuffer)(this, buf, from, to, isnewcommand));
	}
};



