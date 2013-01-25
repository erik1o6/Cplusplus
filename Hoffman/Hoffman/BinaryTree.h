// BinaryTree.h - BinaryTree header class
// Written by: Erik Arfvidson

#pragma once

template<typename TYPE> struct TreeNode
{
    TreeNode(const TYPE& value, TreeNode<TYPE>* left = NULL, TreeNode<TYPE>* right = NULL)
    {
        Value = value;

        Left = left;
        Right = right;
    }

    ~TreeNode()
    {
    }

    TYPE Value;

    TreeNode<TYPE>* Left;
    TreeNode<TYPE>* Right;

    // Check Treenode is a leaf.
    bool IsLeaf() const
    {
        return (Left == NULL) && (Right == NULL);
    }
};