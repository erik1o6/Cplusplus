//EmailDomain.cpp
//written by Erik Arfvidson

#include "EmailDomain.h"

bool EmailDomain::IsValid()
{
	// Free Subdomain
	while(SubDomainList.GetSize() > 0)
	{
		SubDomainList.Remove(SubDomainList.GetSize()-1);
	}

	//Check length
	if( (DomainAddress.GetLength() < MIN_DOMAIN) || (DomainAddress.GetLength() > MAX_DOMAIN) )
	{
		return false;
	}

	// Check @
	if(DomainAddress.Find('@') != INVALID)
	{
		return false;
	}

	// Check if - or .
	if ( DomainAddress[0] == '.' ||
		DomainAddress[0] == '-' ||
		DomainAddress[DomainAddress.GetLength()-1] == '.' ||
		DomainAddress[DomainAddress.GetLength()-1] == '-' )
	{
		return false;
	}

	int start = 0;
	int dot = 0;

	// no subdomain
	if(DomainAddress.Find('.', 0) == INVALID)
	{
		return false;
	}

	// SubDomains and the TLD
	while(dot != INVALID)
	{
		dot = DomainAddress.Find('.', start);
		//TLD
		if(dot == INVALID)
		{
			String text = DomainAddress.SubString(start, DomainAddress.GetLength());
			EmailTld* tld = new EmailTld(text);

			
			SubDomainList.Add(tld);
			
		}
		else
		{	
			String text = DomainAddress.SubString(start,dot);
			EmailSubDomain* subDomain = new EmailSubDomain(text);
			SubDomainList.Add(subDomain);
			start = dot + 1;
		}
	}
	
	// Validifies subdomain
	for(int i = 0; i < SubDomainList.GetSize(); i++)
	{
		if( !(SubDomainList[i]->IsValid()) )
		{
			return false;
		}
	}
	return true;
}

//= operator
void EmailDomain::operator = (const String& source)
{
	DomainAddress = source;
}