#pragma once
// Source Engine
#include "../sdk/chlclient.h"
#include "../sdk/ipanel.h"
#include "../sdk/isurface.h"
#include "../sdk/ivmodelinfo.h"
#include "../sdk/ivengineclient.h"
#include "../sdk/entities.h"
#include "../sdk/iclientmode.h"

// Toolkit
#include "../toolkit/debug.h"



typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);

namespace source {
	extern const char* pszCurrentGame;
	extern const char* pszAbbGame; // Abbreviated name.
	extern int appID;
	void GrabCurrentGame();

	inline bool IsGMod(){ return (appID == 4000); }
	inline bool IsCSGO() { return (appID == 730); }
	inline bool IsCSS(){ return (appID == 240); }
	inline bool IsPortal2() { return (appID == 620); }
	inline bool IsFistulOfFrags() { return (appID == 265630); }
	inline bool IsTF2() { return (appID == 440); }
	inline bool IsL4D2() { return (appID == 550); }
	inline bool IsDODS() { return (appID == 300); }

	namespace sigs {
		extern char *clientMode_pattern;
		extern char *clientMode_mask;
	}

	namespace netvars {
		namespace backend {
			DWORD CrawlTableForOffset(RecvTable *pTable, const char *name, DWORD offset = 0);
			DWORD FindNetvar(const char *table, const char *name);
		}

		void DumpNetvars();

		namespace offsets {
			extern DWORD m_iHealth;
			extern DWORD m_vecOrigin;
			extern DWORD m_iTeamNum;
			extern DWORD m_iObserverMode;
			extern DWORD m_hObserverTarget;
			extern DWORD m_Collision;
			extern DWORD m_vecMins;
			extern DWORD m_vecMaxs;
			extern DWORD m_hActiveWeapon;
			extern DWORD m_fFlags; 
			extern DWORD m_nTickBase;
			extern DWORD m_nModelIndex;
			extern DWORD m_nHitboxSet;
			extern DWORD m_bSpottedBy;
			void GrabOffsets();
		}
	}

	namespace interfaces
	{
		extern IVEngineClient *pEngineClient;
		extern IClientEntityList *pEntityList;
		extern CHLClient *pClient;
		extern IPanel *pPanel;
		extern ISurface *pSurface;
		extern IVModelInfo *pModelInfo;
		extern IClientMode *pClientMode;
		extern void *pIInput;
		void GrabInterfaces();

		namespace backend {
			inline CreateInterfaceFn getFactory(const char *pszModule) {
				return ((CreateInterfaceFn)GetProcAddress(GetModuleHandle(pszModule), "CreateInterface"));
			}

			template <class CInterface>
			CInterface GetInterface(const char *pszModule, const char *pszInterface, const char *pszPrintName);

			inline void CheckInterface(const char *pszPrintName, const char*pszInterface, void *pInterface)
			{
				if (pInterface)
					toolkit::debug::Log(GRAY, "Grabbed %s [%s].\n", pszPrintName, pszInterface);
				else				
					toolkit::debug::Log(RED, "Failed to grab %s.\n", pszPrintName);
			}
		}
	}

}