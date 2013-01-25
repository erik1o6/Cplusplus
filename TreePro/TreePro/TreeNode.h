// TreeNode.h-- Tree node header
// written: Erik Arfvidson

#pragma once

template<typename TYPE>
struct TreeNode
{
	//Constructor
	TreeNode(const TYPE& data = NULL)
	{
		Data = data;
	}

	//Destructor
	~TreeNode()
	{
		delete Left;
		delete Right;
	}

	TYPE Data;
	TreeNode* Left;
	TreeNode* Right;
};