//EmailDomain.h -- header file for the domain portion of the program
//Written by Erik Arfvidson

#pragma once

#include "EmailSubDomain.h"
#include "EmailTld.h"

#define MIN_DOMAIN 1
#define MAX_DOMAIN 256
#define INVALID -1

class EmailDomain
{
public:
	//verifies if email domain is valid
	bool IsValid();
	//operator for string
	void operator = (const String& feed);

private:
	String DomainAddress;
	EmailTld Tld;
};