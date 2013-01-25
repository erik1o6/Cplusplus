//EmailLocal.cpp
//Written by Erik Arfvidson

#include "EmailLocal.h"


bool EmailLocal::IsValid()
{
	//Verify the local part length
	if( (LocalAddress.GetLength() < MIN_LOCAL) || (LocalAddress.GetLength() > MAX_LOCAL) )
	{

		return false;
	}

	// check-  - or .
	if ( LocalAddress[0] == '.' ||
		LocalAddress[0] == '-' ||


		LocalAddress[LocalAddress.GetLength()-1] == '.' ||
		LocalAddress[LocalAddress.GetLength()-1] == '-' )
	{
		return false;

	}

	//for- '.' or '-' local
	for(int i = 1; i < LocalAddress.GetLength(); i++)

	{
		// check- '.' twice
		if( (LocalAddress[i-1] == '.') && (LocalAddress[i] == '.') )
		{
			return false;


		}
		// Check '-' twice
		if( (LocalAddress[i-1] == '-') && (LocalAddress[i] == '-') )

		{
			return false;

		}
	}
	return true;
}

//= operator
void EmailLocal::operator = (const String& source)
{
	LocalAddress = source;


}