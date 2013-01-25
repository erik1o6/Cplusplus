//Test 2
//Written by: Erik Arfvidson


#include <string>
#include <list>

#include <iostream>

using namespace std;

#define MAX 5

// search function
template<typename TYPE> typename list<TYPE>::iterator Search(list<TYPE> *stList, typename list<TYPE>::iterator pos, TYPE look)
{
	// checks end of list
	if (pos == stList->end())	
		throw " Search failed to find string";


	// Checks the current position
	if (*pos == look)	
		return pos;

	pos++;

	//calls itself again with a different position
	return Search<string>(stList, pos, look);	
}

void main()
{
	//create list
	list<string>* stList = NULL;
	stList = new list<string>();

	// ASK user input a list
	string inString, sString;

	cout << "Please enter 5 strings:" << endl;
	for (int i=0; i< MAX; i++)
	{
		//USER INPUT
		cin >> inString;
		stList->push_back(inString);
	}

	// Search the string in the list
	cout << " What do you wish to search for? : ";
	cin >> sString;
	list<string>::iterator startingPosition;
	startingPosition = stList->begin();
	try
	{
		// INITIATE search
		list<string>::iterator pos = Search<string>(stList, startingPosition, sString);

		cout << "Search sucessful..."<<endl << "Found string in position : " << distance(stList->begin(), pos);
	}
	catch (char* except)
	{
		// Catches an exception
		cout << "The Exception was caught at: " << except;
	}
	cout<<endl<<endl;
	system("pause");
}