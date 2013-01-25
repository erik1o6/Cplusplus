// main.cpp - Priority queue
// Written by: Erik Arfvidson

#include <iostream>
#include <string>
#include "SymbolPriority.h"
#include "queues.h"

using namespace std;

void main()
{
	try
	{
		cout << "Input a Sentence: ";
		string sentence;
		getline(cin,sentence);
		cout << endl;

		SymbolPriority symbol;
		vector<SymbolPriority> symPrior;

		// Reads the character in the sentence
		for(int i = 0; i < (int)sentence.size(); i++)
		{
			int j;
			for(j = 0; j < (int)symPrior.size(); j++)
			{
				// CHeck = characters
				if(sentence[i] == symPrior[j].Symbol)
				{
					symPrior[j].Priority++;
					break;
				}
			}
			//Create a new entry
			if( j >= (int)symPrior.size() )
			{
				symbol.Symbol = sentence[i];
				symbol.Priority = 1;
				symPrior.push_back(symbol);
			}
		}

		//Move entry into priority queu
		queues<SymbolPriority> priorityQueue;

		for(int i = 0; i < (int)symPrior.size(); i++)
		{
			priorityQueue.Insert(symPrior[i]);
		}
		
		//Print Queue
		priorityQueue.Print();
	}
	catch(char* letter)
	{
		cout << letter << endl;
	}

	system("pause");
}