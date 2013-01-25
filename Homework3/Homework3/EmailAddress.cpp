//EmailAddress.cpp
//Written by Erik Arfvidson

#include "EmailAddress.h"

	// Check- current email
	bool EmailAddress::IsValid()
	{
		return CheckChars() && Parse() && LocalPart.IsValid() && DomainPart.IsValid();
	}


	// Devides it into its domain and local
	bool EmailAddress::Parse()
	{
		int loc = Address.Find('@');
		if(loc == INVALID)
		{
			return false;
		}
		
		LocalPart = Address.SubString(0,loc);

		DomainPart = Address.SubString( loc+1,Address.GetLength() );
		return true;
	}

	bool EmailAddress::CheckChars()
	{
		//check-spaces and other invalid characters
		int k = ' ';
		while(k < '~')
		{
			
			if( ((k>=' ') && (k<='&')) || 
				(k==',') || 

				((k>='(') && (k<='*')) || 
				(k == '/') || 


				((k>=':') && (k<='?')) || 
				((k>='[') && (k<='^')) || 

				(k=='`') || 



				((k>='{') && (k<='~')) )
			{
				//if char is not found
				if ( Address.Find(k) != NOTFOUND )
				{
					return false;
				}
			}
			k++;
		}
		return true;
	}

	//= operator
	void EmailAddress::operator = (char* source)
	{
		Address = source;
	}
