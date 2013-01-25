//main.cpp reverse the list
//written by erik arfvidson

using namespace std;

#include <iostream>
#include <list>
#include <string>
#define MAX 5




void main()
{
	//define variables
	list<string> myList;
	string myString;
	list<string>::iterator pointer;
	pointer=myList.begin();
	//loop to record all variables in
	for (int counter=0; counter < MAX; counter++  )
	{

		cin >> myString;

		myList.insert(pointer, myString);
		//aplahabetize this is part pf my program that is broken
		while((pointer!=myList.end()) && (*pointer <= myString))
		{
			
			++pointer;	
		}


	}
	//resetp pointer to first on list
	pointer = myList.begin();
	//outputs the list in aphabet orfer
	for (list<string>::iterator pointer=myList.begin(); pointer!= myList.end(); ++pointer )
	{		
		
		// Current element
		string s = *pointer;
		cout << s << endl;
	}

	system ("pause");

}

