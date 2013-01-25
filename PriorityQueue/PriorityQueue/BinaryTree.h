// BinaryTree.h - header class definition
// Written by Erik Arfvidson
#pragma once

template<typename TYPE> struct TreeNode
{
    //Constructor
    TreeNode(const TYPE& value, TreeNode<TYPE>* left = NULL, TreeNode<TYPE>* right = NULL)
    {
        Value = value;
		Right = right;
        Left = left;
     }

    ~TreeNode()
    {//DELETE
    }

    TYPE Value;

	TreeNode<TYPE>* Right;

    TreeNode<TYPE>* Left;
    

    // if Treenode Isleaf
    bool IsLeaf() const
    {
        return (Left == NULL) && (Right == NULL);
    }
};