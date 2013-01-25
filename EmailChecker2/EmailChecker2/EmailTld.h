//Tld.h
//Written by Erik Arfvidson

#pragma once
#include "EmailSubDomain.h"
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <iostream>

#define MIN_TLD 2
#define MAX_TLD 6

class EmailTld : EmailSubDomain
{
public:
	//IsValid verifies length of the tld
	bool IsValid();

	//operator for strings
	void operator = (const String& source);
};