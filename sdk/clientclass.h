#pragma once

//Recv* Classes
#include "dt_recv.h"

class ClientClass
{
public:
	char pad_0x0000[0x8]; //0x0000
	const char* name; //0x0008 
	RecvTable* datatable; //0x000C 
	ClientClass* next; //0x0010 
	int unused_classid; //0x0014 
};