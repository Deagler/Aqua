#pragma once

// Netvar shit.
class RecvTable;

class RecvProp
{
public:
	char* name; //0x0000 
	int type; //0x0004 
	char pad_0x0008[0x20]; //0x0008
	RecvTable* datatable; //0x0028 
	int offset; //0x002C 
	char pad_0x0030[0x4]; //0x0030
	int elements; //0x0034 
	char pad[0x4]; // u gotta pad this shit holmes
};

class RecvTable
{
public:
	RecvProp* props; //0x0000 
	int numprops; //0x0004 
	char pad_0x0008[0x4]; //0x0008
	char* name; //0x000C 

	inline RecvProp* GetProp(int i) {
		
		return (&this->props[i]);
	}
};