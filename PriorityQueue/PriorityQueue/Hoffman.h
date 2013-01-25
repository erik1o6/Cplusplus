// Hoffman.h - Implementation: Hoffman algorithm
// Written by: Erik ARfvidson
#pragma once


#include <string>
#include "MyPriorityQueue.h"
#include "SymbolPriority.h"
#include "BinaryTree.h"
using namespace std;

string FOUND("F");
string NOT_FOUND("");

class Hoffman
{
public:

    //constructs a PriorityQueue stores the node's location
    void MakeTree(const string& aString)
    {
        //populated PrelimPriorityQueue 
        BuildPriorityQueue(aString);

        while( HuffmanPriorityQueue.HasAtleastTwoItems() )
        {
            // store each in TreeNode<SymbolPriority> object
            TreeNode<SymbolPriority>* first = HuffmanPriorityQueue.Top();
            HuffmanPriorityQueue.Pop();
            TreeNode<SymbolPriority>* second = HuffmanPriorityQueue.Top();
            HuffmanPriorityQueue.Pop();

            SymbolPriority nodeSymPriority('*', first->Value.Priority + second->Value.Priority);

            // Create a new TreeNode<SymbolPriority>* and leftChild(from first) and rightChild(from second)
            TreeNode<SymbolPriority>* node = new TreeNode<SymbolPriority>(nodeSymPriority, first, second);

            // Insert TreeNode pointer
            HuffmanPriorityQueue.Push(node);
        }
        // Declare the Root
        Root = HuffmanPriorityQueue.Top();
    }

    // Returns the Huffman code of a given string in a "00101" format.
    void Encode(const string& aString, int& binary, int& overallIndex)
	{
		int flags, index;
		// Loop through each character in aString
		for(int i = 0; i < (int)aString.size(); i++)
		{
			flags = 0;
			index = 0;

			// Obtain the string of binary directions
			this->HuffmanCode(this->Root, aString[i], flags, index);
			// Remove the last flag
			flags = flags >> 1;
			index--;

			// Update the overall index
			overallIndex += index;
			// Shift by the new number of flags
			binary = binary << index;
			// Tack the additional flags onto the end
			binary = binary | flags;
		}
	}

    // Takes a string representing a binary code and returns the corresponding string of characters.
    //     This function relies on the helper function Huffman::HuffmanDecode() to determine each character
    //     that corresponds to part of the binary code.
    string Decode(int binary, int index)
	{
		char aChar;
		string aString;

		// As long as there are still entries in the binary string
		while( index > 0 )
		{
			aChar = this->HuffmanDecode(Root, binary, index);
			aString += aChar;
		}
		return aString;
	}

private:

	// Helper function that assists Huffman::MakeTree() in counting the characters and the number of occurrences.
	//     Also, this function places the TreeNode<SymbolPriority>* objects into the priority queue (in the preliminary fashion)
	void BuildPriorityQueue(const string& aString)
    {
        // The temporary vector that will count the characters and their number of occurrences in aString
        vector<SymbolPriority> priorities;
        SymbolPriority symbolPriority;
        TreeNode<SymbolPriority>* priorityNode = NULL;

        // Loop through each character in the sentence and store it into the vector of SymbolPriorities
		for(int i = 0; i < (int)aString.size(); i++)
		{
			int j;
			// Loop through each entry in the vector
			for(j = 0; j < (int)priorities.size(); j++)
			{
				// Case we've already seen this symbol
				if(aString[i] == priorities[j].Symbol)
				{
					priorities[j].Priority++;
					break;
				}
			}
			// Case we looped through each entry and did not find a match
			if( j >= (int)priorities.size() )
			{
				//Case this is a new character, so we should add it to the vector
				symbolPriority.Symbol = aString[i];
				symbolPriority.Priority = 1;
				priorities.push_back(symbolPriority);
			}
		}

        // Now that the priorities vector has been populated, store these entries into the HuffmanPriorityQueue of type TreeNode<SymbolPriority>*
		for(int i = 0; i < (int)priorities.size(); i++)
		{
			symbolPriority = priorities[i];
            priorityNode = new TreeNode<SymbolPriority>(symbolPriority);
			// Push this new TreeNode<SymbolPriority>* entry into the priority queue
			HuffmanPriorityQueue.Push(priorityNode);
		}
    }

    // Helper function that gets the Huffman code of a single character
    void HuffmanCode(TreeNode<SymbolPriority>* node, const char aChar, int& flags, int& index)
    {
        // Case we've found a match
        if(node->Value.Symbol == aChar)
		{
			// Signal that the character has finally been found
			flags = flags | 1;
			index++;
			return;
		}
        // Case we've reached the end of the line
        if( node->IsLeaf() )
		{
			// Do not change the flags
			flags = flags | 0;
			return;
		}
        // Traverse the left subtree
        if(node->Left != NULL)
		{
			HuffmanCode(node->Left, aChar, flags, index);
			// Case the last entry was a found somewhere in the left subtree so stamp your mark of "0" and pass it back up the chain
			if ( flags != 0 )
			{
				// Put a 0 in
				index++;
				int update = 0 << (index-1);
				flags = flags | update;
				return;
			}
		}
        // Traverse the right subtree
        if(node->Right != NULL)
		{
			HuffmanCode(node->Right, aChar, flags, index);
			// Case the last entry was a found somewhere in the right subtree so stamp your mark of "1" and pass it back up the chain
			if ( flags != 0 )
			{
				// Put a 1 in
				index++;
				int update = 1 << (index-1);
				flags = flags | update;
				return;
			}
		}
    }

    // Helper function that gets the character corresponding to part of a Huffman code
    char HuffmanDecode(TreeNode<SymbolPriority>* node, int& binary, int& index)
    {
		// Case we have navigated to the character that should be returned
		if( node->IsLeaf() )
		{
			return node->Value.Symbol;
		}

		// As long as there are still entries in the binary string
		if( index > 0 )
		{
			int update = 1 << (index - 1);
			int currBinary = binary & update;
			currBinary = currBinary >> (index - 1);
			// Need to turn left
			if(currBinary == 0)
			{
				// Erase this move
				index--;
				return HuffmanDecode(node->Left, binary, index);
			}
			// Need to turn right
			if(currBinary == 1)
			{
				// Erase this move
				index--;
				return HuffmanDecode(node->Right, binary, index);
			}
		}
		// Case the binary string has run out, so I should throw and exception
		throw("Huffman::Decode: Can't find character.");
    }

    // THE priority queue that will hold all of the huffman codes in the correct format.
    //     This is what we will traverse when we want to decode a character.
    MyPriorityQueue< TreeNode<SymbolPriority>* > HuffmanPriorityQueue;

	// The root node of the Huffman encoding structure
    TreeNode<SymbolPriority>* Root;
};


