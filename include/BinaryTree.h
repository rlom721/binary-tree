// Specification file for BinaryTree class
//
// This BinaryTree class...

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryTreeNode.h"
// #include <iostream>
namespace lomboy_a4 {

    // forward declaration
    template <class DataType> class BinaryTree;

    template <class DataType>
    class BinaryTree {
    public:
        // typedef
        typedef DataType dataType;   // to access data type of binary tree
        // enumerated (codes for method parameters)
        enum class Code { ASCEND, DESCEND, PREORDER, INORDER, POSTORDER };
        // constructors
        BinaryTree();                       // default
        BinaryTree(DataType dat);           // parametrized
        BinaryTree(const BinaryTree& bt);   // copy ???
        // destructor
        ~BinaryTree();
        // modification methods
        void insert(DataType dat);
        bool search(DataType dat);
        void sort(Code orderMode);
        // void sortAsc();
        // void sortDsc();
        void remove(DataType dat);
        void clearTree();
        // constant methods
        void iterate();     // default is in-order
        // void iterate(Code orderMode);     // make enum of modes? (post, pre, in order)
        int getEntries() { return entries; }
        // overloaded operators
        // BinaryTree& operator=(const BinaryTree& li);
        // friend functions
    private:
        // member variables
        BinaryTreeNode<DataType>* rootPtr;
        BinaryTreeNode<DataType>* currentPtr;   // current node pointer (latest insert)
        int entries;
        // helper methods
        void insert(DataType dat, BinaryTreeNode<DataType>* nodePtr);
        void dispInorder(const BinaryTreeNode<DataType>* nodePtr);
        void clearTree(BinaryTreeNode<DataType>*& node);
    };

}

#endif