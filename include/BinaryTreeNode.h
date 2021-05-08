// Specification file for BinaryTreeNode class
//
// This BinaryTreeNode class represents an item (or node) of a linked list.

#ifndef BinaryTreeNode_H
#define BinaryTreeNode_H

#include <iostream>
namespace lomboy_a4 {

    // forward declaration
    template <class DataType> class BinaryTreeNode;
    template<class DataType> 
    std::ostream& operator<<(std::ostream& out, const BinaryTreeNode<DataType>& li);
    template<class DataType> 
    bool operator<(const BinaryTreeNode<DataType>& b1, const BinaryTreeNode<DataType>& b2);

    template <class DataType>
    class BinaryTreeNode {
    public:
        // typedef
        typedef DataType dataType;   // to access data type node holds
        // constructors
        BinaryTreeNode();                   // default
        BinaryTreeNode(DataType ldt);       // parametrized
        BinaryTreeNode(DataType ldt, BinaryTreeNode* firstNode); // parametrized
        BinaryTreeNode(const BinaryTreeNode& li);   // copy
        // modification methods
        void set(const DataType& ldt);
        // void setKey(const DataType& ldt);  // no need?
        void setRight(BinaryTreeNode* rightPtr);
        void setLeft(BinaryTreeNode* leftPtr);
        BinaryTreeNode* getLeft() { return leftPtr; }       // needed??
        BinaryTreeNode* getRight() { return rightPtr; }        
        // constant methods
        DataType getData() const { return data; }
        const BinaryTreeNode* getRight() const { return rightPtr; }   // cannot change DATA
        const BinaryTreeNode* getLeft() const { return leftPtr; }  
        // overloaded operators
        BinaryTreeNode& operator=(const BinaryTreeNode& li);
        // friend functions
        friend bool operator< <DataType>(const BinaryTreeNode<DataType>& b1, const BinaryTreeNode<DataType>& b2);
        friend std::ostream& operator<< <DataType>(std::ostream& out, const BinaryTreeNode<DataType>& li);
    private:
        // member variables
        DataType data;
        BinaryTreeNode* leftPtr;
        BinaryTreeNode* rightPtr;
    };

}

#endif
