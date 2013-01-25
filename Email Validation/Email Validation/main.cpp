//main.cpp   Email Validator____ Validates an email from a txt file outputs validity of email in another txt file
//Written By: Erik Arfvidson

#include <iostream>
#include "EmailValidator.h"
#include <string>
#include <fstream> // responsible for file input/output
using namespace std;

//Email validation function
//false otherwise

//main program entry point
void main()
{

	// 1.Open file Input
	//asume it always reside in the current directory
	ifstream in("Email.txt");
	// 2. open Output file
	ofstream out("Result.txt");
	
	while(!in.eof())
	{
		//3. Read email from the in file
		string email;
		getline(in, email);

		//4. Validate email
			if( IsValid(email) )
				out<< "1" << endl;
			else
				out<<"0"<< endl;
	}	

system("pause");
}