//Vector Lab
//Written by Erik Arfvidson

#pragma once
#include <iostream>
#define CAPACITY 10




template<typename entryT>
class Vector
{
public:

	//Constructor
	Vector(int capacity = CAPACITY)
	{
		Num = 0;
		Capacity = capacity;
		Data = new entryT[Capacity];
	}

	// Copy-- deep copying
	Vector(const Vector& original)
	{
		Capacity = CAPACITY;
		Data = new entryT[Capacity];
		*this = original;
	}

	//destructor
	~Vector()
	{
		delete[] Data;
	}
	//= operator...  return vector
	Vector& operator = (const Vector& source)
	{
		this->Num = source.Num;
		this->Capacity = source.Capacity;
		
		//Must delete Data 
		delete[] Data;
		Data = new entryT[Capacity];
		//for loop
		for(int i = 0; i < Num; i++)
		{
			this->Data[i] = source.Data[i];
		}
		return *this;
	}

	//Index Operator
	entryT& operator [] (const int location)
	{
		//check- bounds
		//Throw Exception
		if( (location > Num) || (location < 0) )
		{
			throw("Vector::operator[]: invalid value for location.");
		}

		return Data[location];
	}
	int Find(const entryT entry)
	{
		int location = NOT_FOUND;
		for(int i = 0; i < Num; i++)
		{
			if(Data[i] == entry)
			{	
				location = i;
				return location;
			}
		}
		return location;
	}

	//Remove-entry
	void Remove(int index)
	{
		if( (index < 0) || (index > Num) )
		{
			throw("Vector::Remove():is out of b");
		}
		//Move-left
		for(int i = index; i < Num-1; i++)
		{
			Data[i] = Data[i+1];
		}
		Data[Num-1] = NULL;
		Num--;
	}
	
	//INSERT
	void Insert(const entryT& newEntry, int index)
	{
		//Create a new vector
		if(Num >= Capacity)
		{
			Capacity = Capacity+10;
			Vector newVector(*this);
			*this = newVector;
		}
		//check if values are withing bounds
		if( (index < 0) || (index > Num) )
		{
			throw("Vector::Insert(): index out of bounds");
		}
		
		//begin with index
		for(int i = Num-1; i >= index; i--)
		{
			Data[i+1] = Data[i];
		}
		Data[index] = newEntry;
		Num++;
	}
	//add function
	void Add(const entryT& newEntry)
	{
		Insert(newEntry,Num);
	}

	//getsize function	
	int GetSize()
	{
		return Num;
	}
	//Getcapacity function
	int GetCapacity()
	{
		return Capacity;
	}

private:

	
	entryT* Data;
	int Num;
	int Capacity;

};