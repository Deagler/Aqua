#pragma once

//SDK
#include "getvfunc.h"
#include "qangle.h"
#include "vector.h"

#pragma region player_info
struct player_info_t
{
	char			name[32];
	int				userID;
	char			guid[32 + 1];
	unsigned int			friendsID;
	char			friendsName[32];
	bool			fakeplayer;
	bool			ishltv;
	unsigned long		customFiles[4]; 
	unsigned char	filesDownloaded;
};

struct csgoplayer_info_t
{
	unsigned long long      unknown;
	unsigned long long      xuid;
	char                    name[128];
	int                     userID;
	char                    guid[32 + 1];
	unsigned int            friendsID;
	char                    friendsName[128];
	bool                    fakeplayer;
	bool                    ishltv;
	unsigned long           customFiles[4];
	unsigned char           filesDownloaded;
};
#pragma endregion

class IVEngineClient
{
public:
	void GetScreenSize(int &width, int &height)
	{
		typedef void(__thiscall* vfunc)(void*, int &, int &);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::GetScreenSize)(this, width, height));
	}

	bool GetPlayerInfo(int ent_num, void *pinfo)
	{
		typedef bool(__thiscall* vfunc)(void*, int, void*);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::GetPlayerInfo)(this, ent_num, pinfo));
	}

	bool Con_IsVisible()
	{
		typedef bool(__thiscall* vfunc)(void*);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::Con_IsVisible)(this));
	}

	int GetLocalPlayer()
	{
		typedef int(__thiscall* vfunc)(void*);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::GetLocalPlayer)(this));
	}

	float Time()
	{
		typedef float(__thiscall* vfunc)(void*);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::GetLastTimeStamp)(this));
	}

	void GetViewAngles(QAngle &va)
	{
		typedef void(__thiscall* vfunc)(void*, QAngle &);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::GetViewAngles)(this, va));
	}

	void SetViewAngles(QAngle &va)
	{
		typedef void(__thiscall* vfunc)(void*, QAngle &);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::SetViewAngles)(this, va));
	}

	int GetMaxClients()
	{
		typedef int(__thiscall* vfunc)(void*);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::GetMaxClients)(this));
	}

	bool IsInGame()
	{
		typedef bool(__thiscall* vfunc)(void*);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::IsInGame)(this));
	}

	bool IsDrawingLoadingImage()
	{
		typedef bool(__thiscall* vfunc)(void*);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::IsDrawingLoadingImage)(this));
	}

	const VMatrix & WorldToScreenMatrix()
	{
		typedef const VMatrix &(__thiscall* vfunc)(void*);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::WorldToScreenMatrix)(this));
	}

	bool IsTakingScreenshot()
	{
		typedef bool(__thiscall* vfunc)(void*);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::IsTakingScreenshot)(this));
	}

	void * GetNetChannelInfo()
	{
		typedef void *(__thiscall* vfunc)(void*);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::GetNetChannelInfo)(this));
	}

	void ClientCmd_Unrestricted(const char *pszCommand)
	{
		typedef void(__thiscall* vfunc)(void*, const char*);
		return(getvfunc<vfunc>(this, vfuncs::IVEngineClient::ClientCmd_Unrestricted)(this, pszCommand));
	}


};
