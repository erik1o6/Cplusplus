// Hash.h - Hash header file
// Written by: Erik Arfvidson
#pragma once

#include <vector>
#include <list>
#include "keyValue.h"
#include <math.h>

using namespace std;

#define DEFAULT_SIZE 3
#define INVALID -1

template<typename KeyType, typename ValueType>
class HashTable
{
public:

	//constructor
	HashTable()
	{
		int Size = DEFAULT_SIZE;


		Size = DetermineNearestPrime(Size);
		Table.resize(Size);
	}
	//hashtable-size
	HashTable(int Size)
	{
		//if prime it remains the same but if not if finds the nearest one
		Size = DetermineNearestPrime(Size);

		Table.resize(Size);
	}

	//Insert function takes key and value
	void Insert(KeyType key, ValueType value)
	{

		//find index
		int hashValue = ConvertToHash(key);

		//check bounds
		if( hashValue >= (int)Table.size() )
		{
			int Size = DetermineNearestPrime(hashValue*2);
			Table.resize(Size);

		}

		KeyValuePair<KeyType,ValueType> pair;
		pair.Key = key;
		pair.Value = value;

		Table[hashValue].push_back(pair);
	}

	//Remove function
	void Remove(KeyType key)
	{

		int hashValue = ConvertToHash(key);

		// Check bounds
		if( hashValue >= (int)Table.size() )
			throw("The hash table is out of bounds.");

		list<KeyValuePair<KeyType,ValueType>>::iterator position = Table[hashValue].begin();
		while( position != Table[hashValue].end() )

		{
			if( (*position).Key == key)
			{
				Table[hashValue].erase(position);
				return;
			}
			position++;
		}
		throw("The Item was not found");
	}

	//Print function
	void Print()

	{
		cout << endl;
		list<KeyValuePair<KeyType,ValueType>>::iterator point;
		// go through all the table

		for(int i = 0; i < (int)Table.size(); i++)
		{
			cout << endl;

			point = Table[i].begin();
			while(point != Table[i].end())
			{
				cout << *point << endl;
				point++;
			}
			cout << endl;
		}
		cout << endl;
	}

private:

	//key to hash
	int ConvertToHash(KeyType key)
	{
		int hashValue = 0;
		int exponent = 0;


		// reach each character
		for(int i = 0; i < (int)key.size(); i++)
		{
			exponent = (int)key.size() - i - 1;
			hashValue += key[i]*int ( pow(31.0,exponent));
		}

		hashValue %= int( Table.size() );
		return hashValue;
	}

					//***EXTRA CREDIT****

					//find the closest prime number
					int DetermineNearestPrime(int value)
					{
						//check if it is already prime
						if( IsPrime(value) )
							return value;


						//else find the prime
						for(int i = value-1; i > 1; i--)
						{
							if(IsPrime(i))
								return i;
						}
						return INVALID;
					}

					// check if it is prime
					bool IsPrime(int value)
					{
						for(int i = 2; i < value; i++)
						{
							//divisibility
							if(value % i == 0)
								return false;
						}
						return true;
					}

					vector<list< KeyValuePair<KeyType,ValueType> >> Table;
				};