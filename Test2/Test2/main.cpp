//Test 2
//Written by: Erik Arfvidson



#include <string>
#include <list>

#include <iostream>

using namespace std;

#define MAX_STRINGS 5

// Search function
// Arguments:
//  - aList: inputted list
//  - position: current iterator
//  - value: value being searched for
template<typename T> typename list<T>::iterator Search(list<T> *aList, typename list<T>::iterator position, T value)
{
	if (position == aList->end())	// Check for end of list
		throw "String not found in list";
	if (*position == value)	// Check for value at current node
		return position;
	position++;
	return Search<string>(aList, position, value);	// Recursively call Search
}

void main()
{
	// Get User input from cin and parse it into the list
	list<string>* aList = NULL;
	aList = new list<string>();
	string inputtedString, searchString;
	cout << "Please input 5 strings:" << endl;
	for (unsigned int i=0; i< MAX_STRINGS; i++)
	{
		cout << i << ": ";
		cin >> inputtedString;
		aList->push_back(inputtedString);
	}

	// Get the string to search for and initialize the iterator
	cout << "Value to search for: ";
	cin >> searchString;
	list<string>::iterator startingPosition;
	startingPosition = aList->begin();
	try
	{
		// Perform the search
		list<string>::iterator pos = Search<string>(aList, startingPosition, searchString);
		cout << "Found at index " << distance(aList->begin(), pos);
	}
	catch (char* exception)
	{
		// Catch an exception from the Search function if the value is not found
		cout << "Exception Caught: " << exception;
	}
	cout << endl;
	system("PAUSE");
}

