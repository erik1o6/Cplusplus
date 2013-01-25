// main.cpp-Tree Program
// written: Erik Arfvidson


#include "TreeNode.h"
#include <string>

#include <iostream>

#define INVALID -1

using namespace std;

TreeNode<char>* CreateBinaryTree(string& expression)
{
	TreeNode<char>* root = NULL;

	TreeNode<char>* current = NULL;

				// Start a loop
				for(int i = 0; i < (int)expression.size(); i++)
				{
					// Checks for an integer
					if(expression[i] >= '0' && expression[i] <= '9')
					{
						// Creates a leaf
						TreeNode<char>* Leaf = new TreeNode<char>(expression[i]);

						// FIRST ENTRY
						if(current == NULL)
						{
							// node ----> LEAF
							root = Leaf;
							current = Leaf;
						}
						//OTHER ENTRIES
						else
						{
							// new integer to the right side
							current->Right = Leaf;
						}
					}
					// IF = + or - then make a new root of a tree
					else if( expression[i] == '+' || expression[i] <= '-' || (current->Right == NULL && (expression[i] == '*' || expression[i] <= '/') ) )
					{
						TreeNode<char>* newRoot = new TreeNode<char>(expression[i]);
						newRoot->Left = root;
						//makes a new root
						root = newRoot;
						current = newRoot;
					}
					// Case we've found a '*' or '/' sign so make it a child on the right-hand side of the parent above
					else if(expression[i] == '*' || expression[i] == '/')
					{
						TreeNode<char>* child = new TreeNode<char>(expression[i]);
						// Now that we've found a '*' or '/', prepare to make this '*' or '/' the right-hand child of the current root node
						child->Left = current->Right;
						current->Right = child;
						current = child;
					}
				}
				//Return pointer root
				return root;
}

//Search value of CHAR
double ValueOf(TreeNode<char>* node)
{
	//ADD
	if(node->Data == '+')
		return ValueOf(node->Left) + ValueOf(node->Right);

	//SUBTRACT
	else if(node->Data == '-')
		return ValueOf(node->Left) - ValueOf(node->Right);

	//DEVIDE
	else if(node->Data == '/')
	{	
		//Checks if we are not deviding by 0
		if(node->Right->Data == '0')

			throw("VALUE is a  division by 0");
		return ValueOf(node->Left) / ValueOf(node->Right);
	}

	//Multiply 2 NODES
	else if(node->Data == '*')
		return ValueOf(node->Left) * ValueOf(node->Right);

	//if last is a number return it
	else if(node->Data >= '0' && node->Data <= '9')
	{
		return node->Data - '0';
	}
	//Return Invalid if it fails to fit any of the previous parameters
	else
		return INVALID;
}

void main()
{
	cout<<"********************************"<<endl;
	cout<<"* WELCOME TO THE TREE PROGRAM  *"<<endl;
	cout<<"*             *                *"<<endl;
	cout<<"*            ***               *"<<endl;
	cout<<"*           *****              *"<<endl;
	cout<<"*             *                *"<<endl;
	cout<<"*             *                *"<<endl;
	cout<<"********************************"<<endl;
	cout<<endl;

	double result;

	string eq;
	cout << "Enter Equation: ";
	getline(cin, eq);
	cout << endl;

	TreeNode<char>* root;

	// Construct a binary tree
	root = CreateBinaryTree(eq);

	try
	{
		// Outputs binary tree
		result = ValueOf(root);

		cout << "The result: " << result << endl << endl;
	}
	catch(char* error)
	{

		cout << "Error: " << error << endl << endl;
	}

	system("pause");
}