//EmailAddress.cpp -- email address cpp file
//Written by Erik Arfvidson
#include <iostream>
#include "EmailAddress.h"


	// Verifies the email address
	bool EmailAddress::IsValid()
	{
	
		return InvalidChars() && Seperate() && LocalPart.IsValid() && DomainPart.IsValid();
	}


	// Seperate into Local and Domain
	bool EmailAddress::Seperate()
	{
		int location = Address.Find('@');
		if(location == INVALID)
		{
			return false;
		}
		// Store Domain and Local String Address
		LocalPart = Address.Substring(0,location);
		DomainPart = Address.Substring( location+1,Address.GetLength() );
		return true;
	}

	bool EmailAddress::InvalidChars()
	{
		// Checks specific invalid characters
		int i = ' ';
		while(i < '~')
		{
			
			if( ((i>=' ') && (i<='&')) || 
				(i==',') || 
				((i>='(') && (i<='*')) || 
				(i == '/') || 
				((i>=':') && (i<='?')) || 
				((i>='[') && (i<='^')) || 
				(i=='`') || 
				((i>='{') && (i<='~')) )
			{
				// if any of the characters is found return false else true
				if ( Address.Find(i) != -1 )
				{
				return false;
				}
			}
			i++;
		}
		return true;
	}

	//= operator for string
	void EmailAddress::operator = (char* feed)
	{
		Address = feed;
	}
