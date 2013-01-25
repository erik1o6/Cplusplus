//Set.h - set header class for calculating the  intersection, difference, and search
//Written by Erik Arfvidson
#pragma once

#include<set>
#include<iterator>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

void Print(set<string>& mySet)
{
	set<string>::iterator position = mySet.begin();

	if(position != mySet.end())
	{
		cout << "(" << *position;
		position++;
	}

	while( position != mySet.end() )
	{
		cout << ", " << *position;
		position++;
	}
	cout << ")" << endl;
}

void insertStrings()
{
	string word;
	set<string> Set1, Set2;
	
	cout<<"Input  5 strings for set #1"<<endl<<endl;

	// INPUT 5 strinfgs
	for(int i=1; i<=5;i++)
	{
		cout<<"Input string # "<< i<<":";
		getline(cin,word);
		Set1.insert(word);
	}

	cout<<endl<<endl;
	cout<<"Input  5 strings for set #2"<<endl;

	// INPUT 5 strinfgs
	for(int i=1; i<=5;i++)
	{
		cout<<"Input string # "<< i<<":";
		getline(cin,word);
		Set2.insert(word);
	}

	set<string> unionSet;
	set_union(Set1.begin(), Set1.end(), Set2.begin(), Set2.end(), inserter(unionSet, unionSet.begin()));


	set<string> intersectionSet;
	set_intersection(Set1.begin(), Set1.end(), Set2.begin(), Set2.end(), inserter(intersectionSet, intersectionSet.begin()));


	set<string> differenceSet;
	set_difference(Set1.begin(), Set1.end(), Set2.begin(), Set2.end(), inserter(differenceSet, differenceSet.begin()));



	cout << "Input an entry to find in the unionset:";
	getline(cin,word);
	set<string>::iterator position = unionSet.find(word);
	cout << endl;

	cout << "OUTPUT"<< endl << endl;

	cout << "Set1: ";
	Print(Set1);

	cout << "Set2: ";
	Print(Set2);

	cout << "Union: ";
	Print(unionSet);

	cout << "Intersection: ";
	Print(intersectionSet);

	cout << "Difference: ";
	Print(differenceSet);

	if( position != unionSet.end() )
		cout << "Found!" << endl;
	else
		cout << "Not found." << endl;
}
