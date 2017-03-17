#pragma once

// SDK
#include "vector.h"
#include "getvfunc.h"



class IClientEntity
{
public:
	Vector &GetAbsOrigin()
	{
		typedef Vector &(__thiscall * vfunc)(void *);
		return(getvfunc<vfunc>(this, vfuncs::IClientEntity::GetAbsOrigin)(this));
	}
	/*
	const void * GetModel() {
		void *pRenderable = (void*)(this + 0x4);
		typedef const void*(__thiscall* vfunc)(void*);
		return(getvfunc<vfunc>(this, vfuncs::IClientEntity::GetModel)(pRenderable));
	} inb4 i need this again.
	*/
	bool SetupBones(matrix3x4_t *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime) {
		void *pRenderable = (void*)(this + 0x4);
		typedef bool(__thiscall* vfunc)(void*, matrix3x4_t*, int, int, float);
		return(getvfunc<vfunc>(pRenderable, vfuncs::IClientEntity::SetupBones)(pRenderable, pBoneToWorldOut, nMaxBones, boneMask, currentTime));
	}

	bool IsDormant() {
		void *pNetworkable = (void*)(this + 0x8);
		typedef bool(__thiscall* vfunc)(void*);
		return(getvfunc<vfunc>(pNetworkable, vfuncs::IClientEntity::IsDormant)(pNetworkable));
	}

};

class IClientEntityList
{
public:
	IClientEntity * GetClientEntity(int entnum)
	{
		typedef IClientEntity *(__thiscall * vfunc)(void *, int);
		return(getvfunc<vfunc>(this, vfuncs::IClientEntityList::GetClientEntity)(this, entnum));
	}

	IClientEntity * GetClientEntityFromHandle(void *hEntity)
	{
		typedef IClientEntity *(__thiscall * vfunc)(void *, void *);
		return(getvfunc<vfunc>(this, vfuncs::IClientEntityList::GetClientEntityFromHandle)(this, hEntity));
	}

	int NumberOfEntities(bool bIncludeNonNetworkable)
	{
		typedef int(__thiscall * vfunc)(void *, bool);
		return(getvfunc<vfunc>(this, vfuncs::IClientEntityList::NumberOfEntities)(this, bIncludeNonNetworkable));
	}

	int GetHighestEntityIndex()
	{
		typedef int(__thiscall * vfunc)(void *);
		return(getvfunc<vfunc>(this, vfuncs::IClientEntityList::GetHighestEntityIndex)(this));
	}
};