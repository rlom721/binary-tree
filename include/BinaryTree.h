// Specification file for BinaryTree class
//
// This BinaryTree class...

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryTreeNode.h"
#include <vector>
#include <string>
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
        // public members
        std::vector<DataType> sortedEntries;
        // constructors
        BinaryTree();                       // default
        BinaryTree(DataType dat);           // parametrized
        BinaryTree(const BinaryTree& bt);   // copy ???
        // destructor
        ~BinaryTree();
        // modification methods
        void insert(DataType dat);
        bool search(DataType entry);
        void sort(Code orderMode);
        void remove(DataType entry);
        void clearTree();
        void insertFromFile(std::string fileName);
        // constant methods
        void print();     // make enum of modes? (post, pre, in order)
        void iterate(void (*func)(DataType), Code orderMode);     // make enum of modes? (post, pre, in order)
        int getEntries() { return entries; }
    private:
        // member variables
        BinaryTreeNode<DataType>* rootPtr;
        BinaryTreeNode<DataType>* currentPtr;   // current node pointer (latest insert)
        int entries;
        // helper methods
        void insert(DataType dat, BinaryTreeNode<DataType>* nodePtr);
        bool search(DataType entry, BinaryTreeNode<DataType>* nodePtr);
        void dispInorder(const BinaryTreeNode<DataType>* nodePtr);
        void clearTree(BinaryTreeNode<DataType>*& node);
        void sortToArray(Code orderMode, BinaryTreeNode<DataType>* nodePtr, int& index);
        BinaryTreeNode<DataType>* remove(DataType entry, BinaryTreeNode<DataType>*& nodePtr);
        BinaryTreeNode<DataType>* findMax(BinaryTreeNode<DataType>* currentPtr);
        BinaryTreeNode<DataType>* copyTree(BinaryTreeNode<DataType>* root);
        void process(void (*func)(DataType), BinaryTreeNode<DataType>* nodePtr, Code orderMode);
        void print(BinaryTreeNode<DataType>* nodePtr);
    };

}

#endif