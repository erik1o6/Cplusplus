// String.h - my string class declaration
// Written by Erik Arfvidson

#pragma once
#include<sstream>
#include<iostream>
#include <string>

#define NULL 0
#define NOTFOUND -1
#define MAX_SIZE 300

class String
{
public:
	//Default constructor, creates an empty string
	String();
	// Initialization constructor, copy source into Text
    String(const char* source);
	//Inititiate-Constructor, creates a string of the desired length
	//length includes the null terminator
	String(int length);


	// A shallow copy of an object copies all of the member field value
	//Destructor, dispose allocated memory
	~String();
	//Copy-constructor, preforms deep-copy
	String (const String& source);

	// assignment operator, preforms deep-copy
	String& operator = (const String& source);
	// Assignment operator
    // which must contain a null character
    String& operator = (const char* source);
	
	//Comparison operator, returns true when the strings are of the same length
	// all characters are the same
	bool operator == (const String& compareTo) const;
	bool operator != (const String& compareTo) const;

	//Index operator
	char& operator [] (int index) const;
	//returns the length of this string
	int GetLength() const;
	//returns an index of a aChar in this string starting at startIndex
	// returns NOT_Found when aChar is not found in this string
	int Find(char aChar, int startIndex=0) const;
	//returns a substring of this string starting at startindex and
	// length characters long . length zero means that the entire substring
	// from start index until the end of this string is going to be returned
	String& Substring(int startIndex, int length = 0) const;

	//contcatenates two strings and returns a new string
	String& operator + (const String& aString) const;

	// Returns a new String which is a concatenation of this String and the suffix char[]
    String& operator + (const char* suffix) const;

	//get-accessor function for text, returns the encapsulated C-string
	char* GetText() const;







	//char* GetText() const;
private:
	//the encapsulated C-string
	char* Text;
	int Length;
};
// Stream output operator for string class
std::ostream& operator << (std::ostream& out, const String& aString);