//EmailValidator.cpp   Email Validator____ Validates an email from a txt file outputs validity of email in another txt file
//Written By: Erik Arfvidson
#include "EmailValidator.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <fstream> // responsible for file input/output
using namespace std;

//Email validation function
//false otherwise
string StringToUpper(string strToConvert)
{//change each element of the string to upper case
   for(unsigned int i=0;i<strToConvert.length();i++)
   {
      strToConvert[i] = toupper(strToConvert[i]);
   }
   return strToConvert;//return the converted string
}


bool IsValid(string email)
{

	//1. Make sure thtat the email length is <=254
	if(!(email.length()<=254))
		return false;
	//2. Make sure that there is one and only one '@' Symbol
	int i = 0;
	int at_Count = 0;
	for(i = email.find("@", 0); i != string::npos; i = email.find("@", i))
	{
    at_Count++;
    i++;
	}
	if(at_Count!=1)
		return false;


	//email= localPart@domain
	// 3. Make sure that the localPart is <=64 CHECK ME
	i = 0;
	at_Count = 0;
	for(i = email.find("@", 0); at_Count != 0; i = email.find("@", i))
	{
    at_Count++;
    i++;
	}
	if(!(i<=64 && i!=0))
		return false;
	//4. check localPart for invalid characters
	i=0;
	int count=0;
	int isValid=0;
	string validLocal = ".+abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!#$%&*-/'`=?^_{}~'";  
while(email.at(i)!='@')
{	
	count=0;
	isValid=0;
	while((validLocal.length() > count) && (isValid!=1))
	{
		if(email.at(i)==validLocal.at(count))
		{
			isValid=1;
		}
		else
			count++;
	}
	if(isValid==0)
	return false;


i++;
}
int whereAt=i;
	//5. Check domain for invalid characters
	//Insert Makes sure that there is no @ at the beggining or end
	int test= email.length()-1;
	if (email.at(test)=='@')
		return false;
	if(email.at(0)=='@')
		return false;	
		
	//Insert Makes sure that there is not dot or  hyphen after and before the @
	if( email.at(0)=='.')
		return false;
	if(email.at(i+1)=='.')
		return false;
	if(email.at(i-1)=='.')
		return false;
	if(email.at(test)=='.')
		return false;
	if(email.at(i+1)=='-')
		return false;
	if(email.at(i-1)=='-')
		return false;
	if(email.at(i+1)=='-')
		return false;
	if(email.at(test-4)=='-')
		return false;
	//return false;
i++;
string validDomain = ".abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_-+[]";
while(email.length() > i)
{	
	count=0;
	isValid=0;
	while((validDomain.length() > count) && (isValid!=1))
	{
		if(email.at(i)==validDomain.at(count))
		{
			isValid=1;
		}
		else
			count++;
	}
	if(isValid==0)
	return false;


i++;
}

	//6. Make sure that there is atleast one or more dot
			i = 0;
	int	dot_Count = 0;
	for(i = email.find('.', 0); i != string::npos; i = email.find('.', i))
	{
    dot_Count++;
    i++;
	}
	if(dot_Count==0)
		return false;

	//does not contain ".."
		i = 0;
	 dot_Count = 0;
	for(i = email.find("..", 0); i != string::npos; i = email.find("..", i))
	{
    dot_Count++;
    i++;
	}
	if(dot_Count!=0)
		return false;
	//makes sure that there is no spaces
			i = 0;
	int	space_Count = 0;
	for(i = email.find(' ', 0); i != string::npos; i = email.find(' ', i))
	{
    space_Count++;
    i++;
	}
	if(space_Count > 0)
		return false;

	//domain = sub.sub.tld

	//10. make sure that all subdomains are <=64
	if((whereAt-email.length())<=64)
		return false;
	//11. Validate tld against the list of allowed tld is extra credit
	ifstream in("ValidTLD.txt");
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
	//return true if everything is correct
	return true;
}

