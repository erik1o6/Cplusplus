//main.cpp
//Written by : Erik Arfvidson
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define NUM_STRINGS 5
#define MAX_SIZE 10

//Partition
template<typename TYPE>
int Partition(vector<TYPE>& myVector, int begin, int last)
{
	TYPE pivotValue = myVector[begin];
	int n;
	int bottom = 0;
	int top = -1;
	

	while(top < bottom)
	{
		for(n = begin + 1; n < last; n++)
		{
			if(myVector[n] > pivotValue)
				break;
		}
		top = n;

		for(n = last; n > begin; n--)
		{
			if(myVector[n] < pivotValue)
				break;
		}
		bottom = n;

		//swap
		if(top < bottom)
			swap(myVector[top], myVector[bottom]);
	}
	swap(myVector[begin], myVector[bottom]);
	return bottom;
}

//Quicksort
template<typename TYPE>
void QuickSort(vector<TYPE>& myVector, int begin, int last)
{
	if( (last-begin) < 2)
		return;

	int pivot = Partition(myVector,begin,last);
	//left
	QuickSort(myVector,begin,pivot);
	//right
	QuickSort(myVector,pivot+1,last);
}
//PRINT
template<typename TYPE>
void PrintVector(vector<TYPE>& myVector)
{
	//print from begin to last
	cout << endl;
	for(int n = 0; n < (int)myVector.size();n++)
	{
		cout << myVector[n] << " ";
	}
	cout << endl;
}

//main function
void main()
{
    char charArray[MAX_SIZE];
    vector<string> myVector;

    // Input String
    cout << "Enter " << NUM_STRINGS << " strings: " << endl;
    for(int n = 0; n < NUM_STRINGS; n++)
    {
        cin >> charArray;
        myVector.push_back(string(charArray));
    }

	//Unsorted
	cout<<endl<<" Unsorted"<<endl;
	PrintVector(myVector);
	// Sorted
	QuickSort(myVector, 0, (int)myVector.size()-1);

	//Completly sorted
	cout<<endl <<"Sorted"<<endl;
	PrintVector(myVector);

	cout << endl;
	system("pause");
}