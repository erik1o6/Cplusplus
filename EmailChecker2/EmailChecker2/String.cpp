// String.cpp - my string implementation
// Written by Erik Arfvidson

#include "String.h"


//Default csontructor, creates an empty string
	String::String()
	{
		Length = 0;
		Text= NULL;
	}
	// Init constructor
	String::String(const char* source)
	{
    Text = new char[MAX_SIZE];
    *this = source;
	}
	//Inititiate-Constructor, creates a string of the desired length
	//length includes new char at the end space for /n
	String::String(int size)
	{
    Length = size;
    Text = new char[Length+1];
	}

	//Copy-constructor, preforms deep-copy
	String::String (const String& source)
	{
		Text = new char[MAX_SIZE];
		Text= NULL;
		*this = source;
	}

	// A shallow copy of an object copies all of the member field value
	//Destructor, dispose allocated memory
	String::~String()
	{
		delete [] Text;
		Text= NULL;
	}

	// assignment operator, preforms deep-copy
	String& String::operator = (const String& source)
	{
    Length = source.GetLength();
    // erases the old pointer
    delete[] Text;
    if(Length > 0)
    {
        // And make a new char[] of the correct length for Text
        Text = new char[Length+1];
        // dcopy between source Text and Text 
         for(int i = 0; i <Length+1 ; i++)
            Text[i] = source.Text[i];
    }
    else
    {
        Text = NULL;
    }
    // Return new object data
    return *this;
	}
	

	String& String::operator = (const char* source)
{
  int i = 0;
    while( (source[i] != '\0') && (i < MAX_SIZE) )
    {
        i++;
	}
		if(i >= MAX_SIZE)
		{
			Length = 0;
			Text = NULL;
		}
		else
		{
			// Number of characters
			Length = i;
			// erase the previous data
			// to account for the null character
			delete[] Text;
			Text = new char[Length+1];
      
			// deep copying on source which should include the null character
			for(int k = 0; k < Length+1; k++)
			{
				Text[k] = source[k];
			}
		}
    
    // Return a modified String object
    return *this;

}

	//Index operator
	char& String::operator [] (int index) const
	{
		if ( (index< 0) && (index>= GetLength() - 1) )
		{
		std::stringstream error;
			error<< "Vector:: operator[] Index " << index << "is out of range  0... "<< (GetLength()-1);
			throw error.str();
		}
		return Text[index];
	}
	//returns the length of this string
	int String::GetLength() const
	{
	return Length;
	} // diff

	//returns an index of a aChar in this string starting at startIndex
	// returns NOT_Found when aChar is not found in this string
	int String::Find(char aChar, int startIndex/*=0*/) const
	{
		for (int i = startIndex; i < Length ; i++)
			{
				if ( Text[i]== aChar)
				{
					return i ;
				}

			}
									
		return NOTFOUND;
	}

	//returns a substring of this string starting at startindex and
	// length characters long . length zero means that the entire substring
	// from start index until the end of this string is going to be returned
	String& String::Substring(int startIndex, int length/* =0 */ ) const
	{
   // StartIndex validator
    if( (startIndex < 0) || (startIndex > Length) )
    {
        throw("INVALID");
    }
    // length validator
    if( (length < 0) || (length > Length) )
    {
        throw("INVALID");
    }
    
    String * newText = new String(length);
    for(int i = startIndex; i < startIndex+length; i++)
    {
        newText->Text[i-startIndex] = Text[i];
    }
    newText->Text[length] = '\0';
    return *newText;
	}



	//Comparison operator, returns true when the strings are of the same length
	// all characters are the same
	bool String::operator == (const String& compareTo) const
	{
		return 	(*this == compareTo);
	}
	bool String::operator != (const String& compareTo) const
	{
		return !(*this==compareTo);
	}



	//contcatenates two strings and returns a new string TEST ME
	String& String::operator + (const String& aString) const
	{
		String result(GetLength() + aString.GetLength() +1);

		// write the for loops to copy the contents
		for(int i = 0  ; Text[i] <= result.GetLength() ; i++)
		{
			result[i] = Text[i];
		}

		// place the new null terminator
		Text[GetLength()] = '\0';
		return result;
	}

	// Returns a new String concatenates a string and a char
	String& String::operator + (const char* bString) const
	{
    String dString(bString);
    // Create a new String object that will hold this String object
    String * nString = new String(*this);


    // Attempt to store both this String object
    // and appending String into newString
    *nString = *nString + dString;
    return *nString;
}

/*	String& String::operator = (const char* source)
	{
		Text = new char[MAX_SIZE];
		// this class' assignment operator performs the deep copying
		*this = source;
	}*/	
	//get-accessor function for text, returns the encapsulated C-string
	char* String::GetText() const
	{
		return Text;
	}
	
	

//the encapsulated C-string
//char* Text;

// Stream output operator for string class
std::ostream& operator << (std::ostream& out, const String& aString)
{
	return out << aString.GetText();
}