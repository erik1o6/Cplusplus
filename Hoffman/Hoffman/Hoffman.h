// Hoffman.h- hoffman header class
// Written by: Erik Arfvidson
#pragma once
#include <string>
#include "Queues.h"
#include "SymbolPriority.h"
#include "BinaryTree.h"
using namespace std;


class Hoffman
{
public:

    // Construct a PriorityQueue store in the Root node
    void MakeTree(const string& Text)
    {
		CreateQueue(Text);

        while( HoffmanQueue.TwoItems() )
        {
            TreeNode<SymbolPriority>* first = HoffmanQueue.Up();
            HoffmanQueue.Pop();
            TreeNode<SymbolPriority>* second = HoffmanQueue.Up();
            HoffmanQueue.Pop();

            SymbolPriority nodeSymPriority('*', first->Value.Priority + second->Value.Priority);

            
            TreeNode<SymbolPriority>* node = new TreeNode<SymbolPriority>(nodeSymPriority, first, second);

            // Insert pointer back into the priority queue
            HoffmanQueue.Insert(node);
        }
        Root = HoffmanQueue.Up();
    }

    // Returns the Hoffman code
    void Encode(const string& Text, int& binary, int& overallIndex)
	{
		int flash, point;
		for(int i = 0; i < (int)Text.size(); i++)
		{
			flash = 0;
			point = 0;

			// Obtain the string of binary directions
			this->HoffmanCode(this->Root, Text[i], flash, point);
			flash = flash >> 1;
			point--;
			overallIndex += point;
			binary = binary << point;
			binary = binary | flash;
		}
	}

	//decodes the hoffmancode
    string Decode(int binary, int point)
	{
		char single;
		string Text;

		//check if there is an entry
		while( point > 0 )
		{
			single = this->HoffmanDecode(Root, binary, point);
			Text += single;
		}
		return Text;
	}

private:

	//counting the characters and the number of occurrences.
	

	void CreateQueue(const string& Text)
    {
        // Counter
        vector<SymbolPriority> priorities;
        SymbolPriority symbolPriority;
        TreeNode<SymbolPriority>* priorityNode = NULL;

        // Store vector
		for(int i = 0; i < (int)Text.size(); i++)
		{
			int j;
			for(j = 0; j < (int)priorities.size(); j++)
			{
				if(Text[i] == priorities[j].Symbol)
				{
					priorities[j].Priority++;
					break;
				}
			}
			// check for match
			if( j >= (int)priorities.size() )
			{
				//new character
				symbolPriority.Symbol = Text[i];
				symbolPriority.Priority = 1;
				priorities.push_back(symbolPriority);
			}
		}
		for(int i = 0; i < (int)priorities.size(); i++)
		{
			symbolPriority = priorities[i];
            priorityNode = new TreeNode<SymbolPriority>(symbolPriority);
			// Insert into the priority queue
			HoffmanQueue.Insert(priorityNode);
		}
    }

    void HoffmanCode(TreeNode<SymbolPriority>* node, const char single, int& flash, int& point)
    {
        // check same
        if(node->Value.Symbol == single)
		{
			flash = flash | 1;
			point++;
			return;
		}
        //check if its the end
        if( node->IsLeaf() )
		{
			flash = flash | 0;
			return;
		}
		//LEFT
        if(node->Left != NULL)
		{
			HoffmanCode(node->Left, single, flash, point);
			if ( flash != 0 )
			{
				//0
				point++;
				int refresh = 0 << (point-1);
				flash = flash | refresh;
				return;
			}
		}
        //Right
        if(node->Right != NULL)
		{
			HoffmanCode(node->Right, single, flash, point);
			if ( flash != 0 )
			{
				//1
				point++;
				int refresh = 1 << (point-1);
				flash = flash | refresh;
				return;
			}
		}
    }

    //decoder
    char HoffmanDecode(TreeNode<SymbolPriority>* node, int& binary, int& point)
    {
		//check if its a leaf
		if( node->IsLeaf() )
		{
			return node->Value.Symbol;
		}

		if( point > 0 )
		{
			int refresh = 1 << (point - 1);
			int currBinary = binary & refresh;
			currBinary = currBinary >> (point - 1);
			//left
			if(currBinary == 0)
			{
				// Erase this move
				point--;
				return HoffmanDecode(node->Left, binary, point);
			}
			// Need to turn right
			if(currBinary == 1)
			{
				// Erase this move
				point--;
				return HoffmanDecode(node->Right, binary, point);
			}
		}
		throw("Failed to decode");
    }
    Queues< TreeNode<SymbolPriority>* > HoffmanQueue;

	//Hoffmans's root
    TreeNode<SymbolPriority>* Root;
};


