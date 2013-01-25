//EmailAddress.h
//written by Erik Arfvidson

#pragma once
#include "String.h"

#include "EmailDomain.h"
#include "EmailLocal.h"

#define INVALID -1


class EmailAddress
{
public:

	// check current email
	bool IsValid();

	// Devides it into local and domain
	bool Parse();

	//Verifies validity of characters
	//CHECK ME
	bool CheckChars();

	//= operator
	void operator = (char* source);

private:
	String Address;
	EmailLocal LocalPart;
	EmailDomain DomainPart;
};