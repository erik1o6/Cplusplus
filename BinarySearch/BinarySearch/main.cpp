// main.cpp - binarysearch tree
// written by: Erik Arfvidson

#include <iostream>
#include "BinaryTree.h"

#include <string>

#define INVALID -1
#define MAX 20

using namespace std;




// Print tree 
template<typename TYPE>
void Print(TreeNode<TYPE>* root)
{
    // leftside
    if(root->Left != NULL)
        Print(root->Left);

    // Print this
    cout << root->Value << endl;

    // rightside
    if(root->Right != NULL)
        Print(root->Right);
}


// Set all Characters into the binary tree
template<typename TYPE>
void Insert(TreeNode<TYPE>*& node, TYPE& entry)
{
    // if-empty
    if(node == NULL)
    {
        node = new TreeNode<TYPE>(entry);
        return;
    }


    //if - they are the same value
    else if(entry == node->Value)
    {
        return;
    }


    // if - search left subtree recursively
    else if(entry < node->Value)
    {
        Insert(node->Left, entry);
    }


    // if - search right subtree recursively
    else if(entry > node->Value)
    {
        Insert(node->Right, entry);
    }


}

// Remove entry
template<typename TYPE>
void Remove(TreeNode<TYPE>*& node, TYPE& entry)
{
    // if -endline is equal to nothing return nothing
    if(node == NULL)
        return;
    // search - down the left subtree
    else if(entry < node->Value)
        Remove(node->Left, entry);
    // search - down the right subtree


    else if(entry > node->Value)
        Remove(node->Right, entry);
    // if- values are the same
    else
    {
        // REMOVE LEAF
        if( node->leaf() )
        {



            delete node;
            node = NULL;
        }
        // Remove- with a left child
        else if( node->Left != NULL && node->Right == NULL )
        {
			// Temporary pointer
			TreeNode<TYPE>* temporary = node->Left;

			//MOVE-values
			node->Value = temporary->Value;
			node->Right = temporary->Right;
			node->Left = temporary->Left;

			// erase the disposable information
			delete temporary;
			temporary = NULL;
        }
       // Remove- with a left child
        else if( node->Right != NULL && node->Left == NULL )
        {
				// Temporary pointer
			TreeNode<TYPE>* temporary = node->Right;

			//MOVE-values
			node->Value = temporary->Value;
			node->Left = temporary->Left;
			node->Right = temporary->Right;

				// erase the disposable information
			delete temporary;
			temporary = NULL;
        }
       // Remove- Two childs/leafs
        else
        {
           
            TreeNode<TYPE>* rightMost = node->Left;

			TreeNode<TYPE>* temporary = NULL;

            // move to the right until the subtree.
            while(rightMost->Right != NULL)
			{
                rightMost = rightMost->Right;
			}
			
			// Copy the righmost leaft
			node->Value = rightMost->Value;

			// Temporary pointer
			temporary = rightMost->Left;

			// move pointers
			if(temporary != NULL)
			{
				rightMost->Value = temporary->Value;

				rightMost->Left = temporary->Left;
				rightMost->Right = temporary->Right;
			}
			//delete- if there is no left subtree
			else
			{
				delete rightMost;
				rightMost = NULL;
			}

            // remove-left subtree
            delete temporary;
            temporary = NULL;
        }
    }
}



void main()
{
    char str[MAX]; 
    string sentence;
    TreeNode<string>* root = NULL;

    //User input
    cout << "Please enter a sentence: ";
    while(cin.peek() != '\n')
    {
        
        cin >> str;
        sentence = str;
        Insert(root, sentence);
    }

    // Print
    cout << endl << endl << "Printing" << endl <<endl << endl;
    Print(root);
    cout << endl << endl;

    // User to remove a sentence
    cout << "Please enter the word you wish to remove:"<<endl;
    cin >> sentence;
    cout << endl;

    // Remove
    Remove(root, sentence);

    // Print
    cout << endl << "Print" << endl <<endl<< endl;
    Print(root);
    cout << endl << endl;



	//pause
    system("pause");
}