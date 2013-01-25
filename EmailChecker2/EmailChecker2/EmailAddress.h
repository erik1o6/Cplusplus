//EmailAddress.h-- email address header file
//Written by Erik Arfvidson

#pragma once
#include "String.h"
#include "EmailLocal.h"
#include "EmailDomain.h"

//macro
#define INVALID -1


class EmailAddress
{
public:

	// verify email address
	bool IsValid();

	// Seperate into Local and Domain parts
	bool Seperate();

	//Check for invalid characters
	bool InvalidChars();

	//= operator for string
	void operator = (char* feed);

private:
	String Address;
	EmailLocal LocalPart;
	EmailDomain DomainPart;
};