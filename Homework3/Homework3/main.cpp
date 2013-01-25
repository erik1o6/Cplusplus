//main.cpp
//written by erik arfvidson

#include "EmailAddress.h"


#include <iostream>
#include <fstream>

using namespace std;

#define INPUT_FILE "Email.txt"
#define OUTPUT_FILE "Result.txt"
#define MAX 300

void main()
{
	char word[MAX];

	EmailAddress address;

	ifstream inFile(INPUT_FILE);
	ofstream outFile(OUTPUT_FILE);

	EmailTld::TLDlist();

	// check- input file
	if(!inFile)
	{
		cout << INPUT_FILE << "File was not found.........." << endl;
	}
	else
	{
		while( inFile.getline(word,MAX) )
		{
			address = word;
			outFile << (int)address.IsValid() << " " << word << endl;
		}
	}
	inFile.close();
	outFile.close();
}