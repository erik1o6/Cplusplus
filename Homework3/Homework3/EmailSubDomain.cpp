//SubDomain.cpp
//written by erik arfvidson

#include "EmailSubDomain.h"

EmailSubDomain::EmailSubDomain()
{

}

EmailSubDomain::EmailSubDomain(String text)
{
	this->SubDomainText = text;

}

	//isvalid
bool EmailSubDomain::IsValid()
	{	
		//Verify length
		if( (SubDomainText.GetLength() < MIN_SUBDOMAIN_LENGTH) || (SubDomainText.GetLength() > MAX_SUBDOMAIN_LENGTH) )
		{
			return false;

		}


		// check - or .
		if ( SubDomainText[0] == '.' ||
			SubDomainText[0] == '-' ||


			SubDomainText[SubDomainText.GetLength()-1] == '.' ||
			SubDomainText[SubDomainText.GetLength()-1] == '-' )
		{
			return false;
		}
		return true;

	}

	//= operator
void EmailSubDomain::operator = (const String& source)
		{
		SubDomainText = source;

	}