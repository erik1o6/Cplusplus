//Tld.cpp 
//Written by Erik Arfvidson
//DAmien i tried including the code from my last assigment to try to get work but i failed and so i commented it out
#include "EmailTld.h"

//IsValid function that verifies the correct length for the tld
bool EmailTld::IsValid()
{
	//verifies length of the tld
	if( (SubDomainText.GetLength() < MIN_TLD) && (SubDomainText.GetLength() > MAX_TLD) )
	{
		return false;
	}
	return true;
}
/*	ifstream in("ValidTLD.txt");
	isValid=0;
	int point= email.rfind('.')+1;
	int final= email.length()-1;

	string emailsubtld= email.substr(point,final);
	

	string tld;
	while((!(in.eof())) && (isValid==0))
	{
		in >>tld;
		if(StringToUpper(emailsubtld)==tld)
			isValid=1;
			
	}
	if(isValid==0)
		return false;
		*/

//operator for string
void EmailTld::operator = (const String& feed)
{
	SubDomainText = feed;
}
