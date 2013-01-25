// Homework - Email Checker 2 
//verifies the integrity of an email address
//Written by Erik Arfvidson


#include <iostream>
#include <fstream>
#include "EmailAddress.h"

using namespace std;

#define MAX_SIZE 300

void main()
{
	char email[MAX_SIZE];
	EmailAddress address;

	// 1.Open file Input
	//asume it always reside in the current directory
	ifstream in("Email.txt");
	// 2. open Output file
	ofstream out("Result.txt");

	if(!in)
	{
		cout<< "Could not read the file" << endl;
	}
	else
	{
		while( in.getline(email,MAX_SIZE) )
		{
			//3. Read email from the in file
			//4. Validate email
			address = email;
			out << (int)address.IsValid() << "--" << email << endl;
		}
	}
	//Remember to close files
	in.close();
	out.close();
	system("pause");
}