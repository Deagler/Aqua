#pragma once

#define	FL_CLIENT				(1<<7)

class EntityHelper {
private:
	IClientEntity * m_pEnt;
	int m_iEntityIndex;
	bool m_bIsPlayer;
public:
	EntityHelper() {
		m_iEntityIndex = NULL;
		m_bIsPlayer = NULL;
		m_pEnt = nullptr;
	};

	EntityHelper(int iEntityIndex) {
		m_iEntityIndex = iEntityIndex;
		m_pEnt = source::interfaces::pEntityList->GetClientEntity(iEntityIndex);
		m_bIsPlayer = ((*(int*)((DWORD)m_pEnt + source::netvars::offsets::m_fFlags)) & FL_CLIENT) != 0;
	};

	inline bool IsPlayer() { return m_bIsPlayer; };
	inline int GetEntIndex() { return m_iEntityIndex; };

	inline Vector &GetOBBsMins() { return *(Vector*)((DWORD)m_pEnt + source::netvars::offsets::m_vecMins); };
	inline Vector &GetOBBsMaxs() { return *(Vector*)((DWORD)m_pEnt + source::netvars::offsets::m_vecMaxs); };
	
	inline int GetHealth() { return *(int*)((DWORD)m_pEnt + source::netvars::offsets::m_iHealth); };
	inline bool IsAlive() { return (GetHealth() > 0) && (GetObserverMode() == 0); };
	inline void* GetActiveWeapon() { return (void*)((DWORD)m_pEnt + source::netvars::offsets::m_hActiveWeapon); };
	inline int GetObserverMode() {return *(int*)((DWORD)m_pEnt + source::netvars::offsets::m_iObserverMode); };
	inline int GetTeam() { return *(int*)((DWORD)m_pEnt + source::netvars::offsets::m_iTeamNum); };
	inline int GetModelIndex() { return *(int*)((DWORD)m_pEnt + source::netvars::offsets::m_nModelIndex); }
	inline void* GetObserverTarget() { return (void*)((DWORD)m_pEnt + source::netvars::offsets::m_hObserverTarget); };
	inline int GetTickBase() { return *(int*)((DWORD)m_pEnt + source::netvars::offsets::m_nTickBase); };
	inline Vector &GetVecOrigin() { return *(Vector*)((DWORD)m_pEnt + source::netvars::offsets::m_vecOrigin); };
	inline bool IsSpottedBy(int iEntityIndex) { return iEntityIndex < 65 ? ((bool*)((DWORD)m_pEnt + source::netvars::offsets::m_bSpottedBy))[iEntityIndex] : false ; };


	inline bool operator !() { return(m_pEnt == NULL || m_pEnt == nullptr); };
};