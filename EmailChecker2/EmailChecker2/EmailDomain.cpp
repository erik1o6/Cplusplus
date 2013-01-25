//EmailDomain.cpp
//Written by Erik Arfvidson

#include "EmailDomain.h"

bool EmailDomain::IsValid()
{
	//Verify the Domain's length
	if( (DomainAddress.GetLength() < MIN_DOMAIN) || (DomainAddress.GetLength() > MAX_DOMAIN) )
		return false;

	// Check for two @
	if(DomainAddress.Find('@') != INVALID)
		return false;

	// specific checks to verify domain
	if ( DomainAddress[0] == '.' ||
		DomainAddress[0] == '-' ||
		DomainAddress[DomainAddress.GetLength()-1] == '.' ||
		DomainAddress[DomainAddress.GetLength()-1] == '-' )
	{
		return false;
	}

	EmailSubDomain subDomain;

	int index = 0;
	int dot = 0;
	//check subdomains
	if(DomainAddress.Find('.', 0) == INVALID)
		return false;

	// seperates the string
	while(dot != INVALID)
	{
		dot = DomainAddress.Find('.', index);
		// Find the TLD
		if(dot == INVALID)
		{
			Tld = DomainAddress.Substring(index, DomainAddress.GetLength());
		}
		else
		{
			subDomain = DomainAddress.Substring(index, dot);
			// Verifies Subdomain
			if( !subDomain.IsValid() )
				return false;
			index = dot + 1;
		}
	}

	// Verify TLD
	return Tld.IsValid();
}

//equal operator string
void EmailDomain::operator = (const String& feed)
{
	DomainAddress = feed;
}