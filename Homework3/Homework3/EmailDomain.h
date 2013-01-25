//Domain Part header
//Written by Erik Arfvidson

#pragma once

#include "EmailTld.h"
#include "Vector.h"

#define MIN_DOMAIN 1
#define MAX_DOMAIN 256
#define INVALID -1

class EmailDomain
{
public:

	bool IsValid();

	//= operator
	void operator = (const String& source);

private:
	String DomainAddress;
	Vector<EmailSubDomain*> SubDomainList;
	EmailTld Tld;
};