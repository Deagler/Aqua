#pragma once

// SDK
#include "vector.h"
#include "getvfunc.h"

typedef unsigned char byte;
typedef unsigned char BYTE;

struct mstudiobbox_t
{
	int bone; //0x0000 
	int group; //0x0004 
	Vector bbmin; //0x0008 
	Vector bbmax; //0x0014 
	//int hitboxnameoffset; //0x0020 <- Leads to region in memory where all names of hitboxes are stored.
	
	//const char* pszHitboxName()
	//{
	//	if (hitboxnameoffset == 0)
	//		return "";
	//	char ** hitboxes = (char**)((unsigned long)this + hitboxnameoffset);
	//	
	//
	//	return hitboxes[1];
	//}
};

struct mstudiohitboxset_t
{
	int nameoffset; //0x0000 This is like an offset to the region of memory where our pointers are
	int numhitboxes; //0x0004 
	int hitboxoffset; //0x0008 This is like an offset to the region of memory where our pointers are

	inline char * pszName() const { return ((char *)this) + nameoffset; } 
	inline mstudiobbox_t *pHitbox(int i) const { return (mstudiobbox_t *)(((byte *)this) + hitboxoffset) + i; };

};
class mstudiobone_t
{
public:
	int szNameIndex; //0x0000 
	int parent; //0x0004 
	char pad_0x0008[0x18]; //0x0008
	Vector pos; //0x0020 
	char pad_0x002C[0x74]; //0x002C
	int flags; //0x00A0 
	char pad_0x00A4[0x8]; //0x00A4
	int physicsBone; //0x00AC 
	char pad_0x00B0[0x28]; //0x00B0
	inline char * GetName() { return (char*)((byte*)this + szNameIndex); }
};//Size=0x00D8
struct studiohdr_t
{
	char pad_0x0000[0x4]; //0x0000
	int namelength; //0x0004 
	char pad_0x0008[0x4]; //0x0008
	char name[64]; //0x000C 
	char pad_0x004C[0x4]; //0x004C
	Vector eyepos; //0x0050 
	Vector illumpos; //0x005C 
	Vector hull_min; //0x0068 
	Vector hull_max; //0x0074 
	char pad_0x0080[0x18]; //0x0080
	int flags; //0x0098 
	int numbones; //0x009C 
	int boneindex;
	char pad_0x00A0[0xC]; //0x00A0
	int hitboxsetindex; //0x00B0 This is like an offset to the region of memory where our pointers are

	/*man valve is wise.*/
	inline mstudiohitboxset_t *pHitboxSet(int i) const { return (mstudiohitboxset_t *)(((byte *)this) + hitboxsetindex) + i; };
	inline mstudiobone_t *pBone(int i) const { return (mstudiobone_t *)(((byte *)this) + boneindex) + i; };
	inline mstudiobbox_t *pHitbox(int i, int set = 0) const 
	{
		mstudiohitboxset_t const *s = pHitboxSet(set);
		if (!s)
			return 0;

		return s->pHitbox(i);
	}

	inline int iHitboxCount(int set = 0) const
	{
		mstudiohitboxset_t const *s = pHitboxSet(set);
		if (!s)
			return 0;

		return s->numhitboxes;
	};


};

class IVModelInfo
{
public:
	void * GetModel(int modelindex)
	{
		typedef void*(__thiscall * vfunc)(void *, int);
		return(getvfunc<vfunc>(this, vfuncs::IVModelInfo::GetModel)(this, modelindex));
	}

	const char * GetModelName(const void *model)
	{
		typedef const char *(__thiscall * vfunc)(void *, const void *);
		return(getvfunc<vfunc>(this, vfuncs::IVModelInfo::GetModelName)(this, model));
	}


	studiohdr_t * GetStudiomodel(const void *model)
	{
		typedef studiohdr_t *(__thiscall * vfunc)(void *, const void *);
		return(getvfunc<vfunc>(this, vfuncs::IVModelInfo::GetStudiomodel)(this, model));
	}
};