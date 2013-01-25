//LocalPart.h
//written by Erik Arfvidson

#pragma once
#include "String.h"

#define MAX_LOCAL 64
#define MIN_LOCAL 1


class EmailLocal
{
public:
	//Check local IsValid

	bool IsValid();
	//= operator

	void operator = (const String& source);

private:
	String LocalAddress;
};