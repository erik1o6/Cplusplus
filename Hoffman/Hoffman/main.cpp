// main.cpp - Hoffman Test
// Written by: Erik Arfvidson

#include <iostream>
#include "Hoffman.h"

using namespace std;

void main()
{
	try
	{
		int binary = 0, point = 0;
		// Input a sentence to encoded or decoded
		cout << "Input a sentence that you wish to encode: ";
		string sentence;
		getline(cin,sentence);
		cout << endl;

		Hoffman hoffman;

		// create Tree
		hoffman.MakeTree(sentence);

		// encode sentence
		hoffman.Encode(sentence,binary, point);

		// Convert binary string to readable text
		string resultSentence = hoffman.Decode(binary,point);

		cout << "ORIGINAL : " << sentence << endl;
		cout << "BINARY : ";
		for(int i = point; i > 0; i--)
		{
			int refresh = 1 << (i-1);
			int bit = binary & refresh;
			bit = bit >> (i-1);
			cout << bit;
		}
        cout << endl;
		cout << "RESULT: " << resultSentence << endl;
	}
	catch(char* checker)
	{
		cout << checker << endl << endl;
	}
	system("pause");
}