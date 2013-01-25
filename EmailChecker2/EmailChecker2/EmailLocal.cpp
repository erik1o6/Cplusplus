//Local Part.cpp - local part cpp file
//Written by Erik Arfvidson

#include "EmailLocal.h"


bool EmailLocal::IsValid()
{
	//Verify local part is valid
	if( (LocalAddress.GetLength() < MIN_LOCAL) || (LocalAddress.GetLength() > MAX_LOCAL) )
	{
		return false;
	}

	//Specific checks to verify validity of the Local Address
	if ( LocalAddress[0] == '.' ||
		LocalAddress[0] == '-' ||
		LocalAddress[LocalAddress.GetLength()-1] == '.' ||
		LocalAddress[LocalAddress.GetLength()-1] == '-' )
	{
		return false;
	}

	//checks to verify that there are two '.' or '-' in the localpart
	for(int i = 1; i < LocalAddress.GetLength(); i++)
	{
		// check if there are two together
		if( (LocalAddress[i-1] == '.') && (LocalAddress[i] == '.') )
		{
			return false;
		}
		// check if there are two together
		if( (LocalAddress[i-1] == '-') && (LocalAddress[i] == '-') )
		{
			return false;
		}
	}
	return true;
}

//operator for string
void EmailLocal::operator = (const String& feed)
{
	LocalAddress = feed;
}