// queues.h - Header class
// Written by: Erik Arfvidson

#pragma once

#include <vector>

using namespace std;

template<typename T> 
class queues
{
public:
    // Return top entry
	const T& Up() const
	{
		if( this->IsEmpty() )
			throw("ERROR there are no remaining entries");
		return Data[0];
	}

	// Check if queue is empty
	bool IsEmpty() const
	{
		return Data.empty();
	}

	// Remove the top entry
	void Pop()
	{
		// Replace the top entry's value with the last entry's value
		int lastEntry = (int)Data.size() - 1;

		Data[0] = Data[lastEntry];

		// Delete last
		Data.pop_back();

		int parent = 0;
		int lChild = parent*2 + 1;

		int rChild = lChild + 1;


		// check position
		while( lChild >= (int)Data.size() )
		{
			//lChild < rChild
			if( (lChild != NULL && rChild == NULL) || (lChild <= rChild) )
			{
				if(parent > lChild)
				{
					swap(Data[parent], Data[lChild]);
					parent = lChild;

				}
				else
					break;
			}
			else if(rChild < lChild)
			{
				if(parent > rChild)
				{
					swap(Data[parent], Data[rChild]);
					parent = rChild;

				}
				else
					break;
			}

			lChild = parent*2 + 1;
		    rChild = lChild + 1;
		}
	}

	// New Entry push
	void Insert(const T& value)
	{
		//Insert the values
		Data.push_back(value);

		int child = (int)Data.size() - 1;
		int parent = (child - 1)/2;

		//check bounds
		while(parent >= 0)
		{
			if(Data[child] < Data[parent])
			{
				swap(Data[child], Data[parent]);
				child = parent;
				parent = (child - 1)/2;
			}
			else
				break;
		}
	}

	//Print
	void Print()
	{
		cout << "PRINTING:" << endl << endl;
		cout << endl;
		while( !this->IsEmpty() )
		{
			cout << this->Up() << endl;
			this->Pop();
		}
	}

private:
	vector<T> Data;
};