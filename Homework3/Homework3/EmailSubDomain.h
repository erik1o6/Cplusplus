//SubDomain.h
//written by Erik Arfvidson

#pragma once
#include "String.h"

#define MIN_SUBDOMAIN_LENGTH 1
#define MAX_SUBDOMAIN_LENGTH 50

class EmailSubDomain
{
public:
	EmailSubDomain();
	EmailSubDomain(String text);
	// write here IsValid

	virtual bool IsValid();

	//= operator
	void operator = (const String& source);

protected:
	String SubDomainText;
};