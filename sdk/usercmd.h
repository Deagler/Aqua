#pragma once

// SDK
#include "vector.h"

#define IN_ATTACK		(1 << 0)
#define IN_JUMP			(1 << 1)
#define IN_DUCK			(1 << 2)
#define IN_ATTACK2		(1 << 11)
#define IN_RELOAD		(1 << 13)
#define IN_SCORE		(1 << 16)

#define	FL_ONGROUND				(1<<0)
#define FL_DUCKING				(1<<1)
#define	FL_CLIENT				(1<<7) // IsPlayer - Efficient way

class CSGOUserCmd
{
public:
	virtual ~CSGOUserCmd() { };

	int             command_number;
	int             tick_count;
	Vector  viewangles;
	Vector  aimdirection;
	float   forwardmove;
	float   sidemove;
	float   upmove;
	int             buttons;
	unsigned char    impulse; // BYTE
	int             weaponselect;
	int             weaponsubtype;
	int             random_seed;
	short   mousedx;
	short   mousedy;
	bool    hasbeenpredicted;
	Vector  headangles;
	Vector  headoffset;
};