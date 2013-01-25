//SubDomain.h
//Written by Erik Arfvidson

#pragma once
#include "String.h"

#define MIN_SUBDOMAIN 1
#define MAX_SUBDOMAIN 50

class EmailSubDomain
{
public:
	//IsValid verifies the subdomain
	bool IsValid();

	//operator for string
	void operator = (const String& feed);

protected:
	String SubDomainText;
};