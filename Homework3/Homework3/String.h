// String.h - string header
// Written by Erik ARfvidson

#pragma once

#define NOTFOUND -1
#define MAX 300
#define NULL 0

class String
{
public:

    //Default constructor, creates an empty string
    String();
    // Initialization constructor, copy source into Text
    String(const char* source);
	//Inititiate-Constructor, creates a string of the desired length
	//length includes the null terminator
    String(int Size);
	 	// A shallow copy of an object copies all of the member field value
	//Destructor, dispose allocated memory
    ~String();

    	//Copy-constructor, preforms deep-copy
    String(const String& source);

    //= operator
    String& operator = (const String& source);
    String& operator = (const char* source);

    // Index operator,
    char& operator [] (int index);

    //returns the length of this string
    int GetLength() const;

	//returns an index of a aChar in this string starting at startIndex
	// returns NOT_Found when aChar is not found in this string
    int Find(char aChar, int startPosition = 0) const;
	//returns a substring of this string starting at startindex and
	// length characters long . length zero means that the entire substring
	// from start index until the end of this string is going to be returned
    String& SubString(int start, int end) const;

	//contcatenates two string
	String& operator + (const String& suffix) const;

	// Returns a new String which is a concatenation
	String& operator + (const char* suffix) const;

	//compare two strings
	bool String::operator == (const String& other) const;

	// Checks to see if this String object is equivalent to the given char[] other
	bool operator == (const char* other) const;

	// Checks to see if this String object is NULL or not
	bool IsValid();

private:

	int GetLength(const char* charArray);
    char* Text;

    int Length;
};