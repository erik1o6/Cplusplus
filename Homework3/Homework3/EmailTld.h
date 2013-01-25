//Tld.h
//written erik arfvidson

#pragma once
#include "EmailSubDomain.h"
#include "Vector.h"

#define MIN_TLD 2
#define MAX_TLD 6

class EmailTld : public EmailSubDomain
{
public:

	EmailTld();

	EmailTld(String text);

	//IsValid
	bool IsValid();

	//= operator
	void operator = (const String& source);

	static void TLDlist();

private:

	static Vector<String> TLDs;
};