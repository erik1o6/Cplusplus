// main.cpp - main program
// Written by: Erik Arfvidson

#include <iostream>
#include <string>
#include "Hash.h"
#define ENTRIES 2
#define LENGTH 15

using namespace std;

void main()
{
    try
    {
        string key;
        char valueChar[ENTRIES];
        int value;
        HashTable<string, int> hashTable;


			for(int i = 0; i < ENTRIES; i++)
			{
				// Input Key
				cout << "Please Input the key: ";
				getline(cin,key);

				//input value
				cout << endl << "Value: ";
				cin >> valueChar;

				value = atoi(valueChar);

				cin.ignore();



				cout << endl << endl;


				hashTable.Insert(key, value);
			}


		// Print hash
        hashTable.Print();
		// Remove entry
        hashTable.Remove(key);
		hashTable.Print();
    }
    catch(char* check)
    {
        cout << check << endl << endl;
    }
    system("pause");
}