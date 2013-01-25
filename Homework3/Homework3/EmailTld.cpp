//EmailTld.cpp
//Written by Erik Arfvidson

#include "EmailTld.h"

#include <fstream>
#define TLD_LIST "ValidTLD.txt"

EmailTld::EmailTld()
{}

EmailTld::EmailTld(String text)
{
	this->SubDomainText = text;

}

Vector<String> EmailTld::TLDs;
void EmailTld::TLDlist()
{

	char word[MAX_TLD];
	std::ifstream inFile(TLD_LIST);
	while( inFile.getline(word,MAX_TLD) )
	{
		String tldString = word;
		TLDs.Add(tldString);
	}
	inFile.close();


}

//IsValid
bool EmailTld::IsValid()
{
	// TLD's


	for(int i = 0; i < TLDs.GetSize(); i++)
	{
		if(TLDs[i] == this->SubDomainText)
			return true;

	}
	return false;
}

//= operator
void EmailTld::operator = (const String& source)
{
	SubDomainText = source;

}
