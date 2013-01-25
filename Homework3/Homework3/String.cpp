// String.cpp - string.cpp
// Written by Erik Arfvidson

#include "String.h"
//Default csontructor, creates an empty string
String::String()
{
    Length = 0;
    Text = NULL;
}



// Initialization constructor
String::String(const char* source)
{
    Text = new char[MAX];
    *this = source;
}
	//Inititiate-Constructor, creates a string of the desired length
	//length includes new char at the end space for /n
String::String(int Size)
{
    Length = Size;
    Text = new char[Length+1];
}



// Copy constructor
String::String(const String& source)
{
    Text = new char[MAX];
    Text = NULL;
    *this = source;
}



// Destructor
String::~String()
{
    delete[] Text;
    Text = NULL;
}



//= operator
String& String::operator = (const String& source)
{
    Length = source.GetLength();
    delete[] Text;
    if(Length > 0)
    {     
        Text = new char[Length+1];
        for(int i = 0; i < Length+1; i++)
        {
            Text[i] = source.Text[i];
        }
    }
    else
    {
        Text = NULL;
    }
    return *this;
}
//= operator
String& String::operator = (const char* source)
{
    int i = 0;
	Length = GetLength(source);
	delete[] Text;
	Text = new char[Length+1];
	for(int j = 0; j < Length+1; j++)
	{
		Text[j] = source[j];
	}
	return *this;
}

char& String::operator [] (int index)
{
    if( (index < 0) || (index > Length) )
    {
        throw("Invalid value");
    }
    return Text[index];
}

int String::GetLength() const
{
    return Length;
}
//find function
int String::Find(char aChar, int startPosition/* = 0*/) const
{
    if( (startPosition < 0) || (startPosition > Length) )
    {
        throw("Find()");
    }
    for(int i = startPosition; i < Length; i++)
    {
        if(Text[i] == aChar)
        {
            return i;
        }
    }
    return NOTFOUND;
}
//Substring
String& String::SubString(int start, int end) const
{
    // Check start
    if( (start < 0) || (start > Length) )
    {
        throw("Invalid value");
    }
    // Make sure length is a valid value
    if( (end < start) || (end > Length) )
    {
        throw("Invalid");
    }
    //new String
    String * newString = new String(end-start);

    // copy char
    for(int i = start; i < end; i++)
    {
        newString->Text[i-start] = Text[i];
    }
    newString->Text[end-start] = '\0';
      //newString
    return *newString;
}
//add operator
String& String::operator + (const String& suffix) const
{
    int i,j;
    int lengthNewString = GetLength() + suffix.GetLength();
    String * newString = new String(lengthNewString);

    // Copy
    for(i = 0; i < GetLength(); i++)
    {
        newString->Text[i] = Text[i];
    }

    // Copy contents of suffix String over to the new String
    for(j = 0; j < suffix.GetLength() + 1; j++)
    {
        newString->Text[j+i] = suffix.Text[j];
    }
    // Return newString
    return *newString;
}



// Concatenation of this string and the suffix char[]
String& String::operator + (const char* suffix) const
{
    String appendingString(suffix);

    String * newString = new String(*this);
	*newString = *newString + appendingString;
	return *newString;
}



// String== String
bool String::operator == (const String& other) const
{
	if( Length != other.GetLength() )
	{
		return false;
	}
	//COmpare characters
	for(int i = 0; i < Length; i++)
	{
		// Check if one does not match
		if(Text[i] != other.Text[i])
		{
			return false;
		}
	}//return true if i passes the previous test
	return true;
}

//check == operator
bool String::operator == (const char* newss) const
{
	String * otherString = new String(newss);
	// == of two strings
	return (*this == *otherString);
}



// CHeck if null
bool String::IsValid()
{
	if( GetLength() == NULL )
	{
		return false;
	}
	return true;
}
//get length of string
int String::GetLength(const char* charArray)
{
	int i = 0;
    while( (charArray[i] != '\0') && (i < MAX) )
    {
        i++;
    }
    if(i >= MAX)
    {
		throw("Invalid");
    }
	return i;
}