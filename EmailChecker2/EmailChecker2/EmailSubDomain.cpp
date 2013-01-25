//SubDomain.cpp -- manages the subdomain
//Written by Erik Arfvidson

#include "EmailSubDomain.h"

	//IsValid subdomain is valid
bool EmailSubDomain::IsValid()
	{	
		//Verify SubDomain correct length
		if( (SubDomainText.GetLength() < MIN_SUBDOMAIN) || (SubDomainText.GetLength() > MAX_SUBDOMAIN) )
		{
			return false;
		}


		// Specific checks to verify validity of the subdomain
		if ( SubDomainText[0] == '.' ||
			SubDomainText[0] == '-' ||
			SubDomainText[SubDomainText.GetLength()-1] == '.' ||
			SubDomainText[SubDomainText.GetLength()-1] == '-' )
		{
			return false;
		}
		return true;
	}

	//operator for string
void EmailSubDomain::operator = (const String& feed)
	{
		SubDomainText = feed;
	}