//LocalPart.h - local part header
//Written by Erik Arfvidson

#pragma once
#include "String.h"

#define MAX_LOCAL 64
#define MIN_LOCAL 1

class EmailLocal
{
public:
	//Verify local part is valid
	bool IsValid();
	//operator for string
	void operator = (const String& source);

private:
	String LocalAddress;
};