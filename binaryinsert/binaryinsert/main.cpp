// main.cpp- Test binary Insert
//written by: Erik Arfvidson

#include <vector>

#include <iostream>
#include <string>

#define MAX 5
#define INVALID -1

using namespace std;
template<typename TYPE>
//Index  a new start in aphabetical order.
int BinaryInsert(vector<TYPE>& vector, const TYPE& start, int first, int length)
{
	
	//If statementes to test the base case
	//less than 0
	if(length < 0)
		return INVALID;
	else if(length == 0)
		return first;

	//length has to be equal to one
	else if(length == 1)
	{
		if(start < vector[first])
			return first;
		else
			return first + 1;
	
	}
	//The following is if there are more than one item.
	else
	{	//LEFT OF VECTOR
		if(start < vector[first + length/2])
			return BinaryInsert(vector, start, first, length/2);
		// Right of Vector
		else
			return BinaryInsert(vector, start, first+length/2, length - length/2);
	}
}

template<typename TYPE>
void Print(vector<TYPE>& vector)
{	
	cout << endl <<endl;
	for(int t = 0; t < (int)(vector.size()); t++)
	{
		//Print vector 
		cout << vector[t] << endl;
	}
	cout << endl<<endl;
}
//Start Main
void main()
{
	string initialString;
	int index;
	vector<string> ordered;

	cout << "Input five strings please:" << endl;
	for(int t = 0; t < MAX; t++)
	{
		// reads the line of strings
		getline(cin, initialString);
		//Alphabetize
		index = BinaryInsert( ordered, initialString, 0, ordered.size() );
		// Converting iterator
		vector<string>::iterator position = ordered.begin() + index;
		// insert the string at the indicated index
		ordered.insert(position, initialString);
	}



	// prints vector
	Print(ordered);




	system("pause");
}