// BinaryTree.h -definition: binary tree data type
// written by: Erik Arfvidson

#pragma once

template<typename TYPE> struct TreeNode
{
    // constructor
    TreeNode(const TYPE& value, TreeNode<TYPE>* left = NULL, TreeNode<TYPE>* right = NULL)
    {
        Value = value;

        Left = left;
        Right = right;
    }

    ~TreeNode()
    {}





    TYPE Value;

    TreeNode<TYPE>* Left;
    TreeNode<TYPE>* Right;

  // if checking leaf.
    bool leaf() const
    {
        return (Right == NULL) && (Left == NULL);
    }
};