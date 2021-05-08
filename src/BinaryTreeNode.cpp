// Implementation file for BinaryTreeNode class
// File name: BinaryTreeNode.cpp

#include "BinaryTreeNode.h"    // header file for BinaryTreeNode class
#include <iostream>
using namespace std;
namespace lomboy_a4 {

    // Default constructor uses default constructor of DataType to set default value
    // for data field, then sets leftPtr field to nullptr
    template <class DataType>
    BinaryTreeNode<DataType>::BinaryTreeNode()
        : data(DataType()), leftPtr(nullptr), rightPtr(nullptr) { }

    // Parametrized constructor takes argument of DataType and sets data field to it,
    // then sets leftPtr and rightPtr fields to nullptr
    template <class DataType>
    BinaryTreeNode<DataType>::BinaryTreeNode(DataType ldt)
        : data(ldt), leftPtr(nullptr), rightPtr(nullptr) { }

    // Parametrized constructor sets data and leftPtr fields to arguments then sets rightPtr
    // pointer to nullptr.
    template <class DataType>
    BinaryTreeNode<DataType>::BinaryTreeNode(DataType ldt, BinaryTreeNode* firstNode)
        : data(ldt), leftPtr(firstNode), rightPtr(nullptr) { }

    // Copy constructor copies data value (and key via copy assignment) from another 
    // BinaryTreeNode, but NOT its pointers! It sets leftPtr and rightPtr fields to nullptr
    template <class DataType>
    BinaryTreeNode<DataType>::BinaryTreeNode(const BinaryTreeNode& li) {
        data = li.getData();
        leftPtr = nullptr;
        rightPtr = nullptr;
    }

    // This method sets the data AND key field to the argument provided (via
    // copy assignment).
    template <class DataType>
    void BinaryTreeNode<DataType>::set(const DataType& ldt) {
        data = ldt;
    }

    // This method sets leftPtr field (pointer to next BinaryTreeNode) to the argument provided.
    template <class DataType>
    void BinaryTreeNode<DataType>::setLeft(BinaryTreeNode* leftPtr) {
        this->leftPtr = leftPtr;
    }

    // This method sets rightPtr field (pointer to previous BinaryTreeNode) to argument provided.
    template <class DataType>
    void BinaryTreeNode<DataType>::setRight(BinaryTreeNode* rightPtr) {
        this->rightPtr = rightPtr;
    }

    // Overloaded copy assignment
    // This method copies data value from another BinaryTreeNode object, but NOT its pointers!
    template <class DataType>
    BinaryTreeNode<DataType>& BinaryTreeNode<DataType>::operator=(const BinaryTreeNode& li) {
        // check for self-assignment
        if (this != &li) {
            data = li.getData();
        }

        return *this;
    }

    // Overloaded < bool comparison
    // This method compares the data of two BinaryTreeNodes, returning true if b1 < b2.
    // Assumes DataType has < capability.
    template <class DataType>
    bool operator<(const BinaryTreeNode<DataType>& b1, const BinaryTreeNode<DataType>& b2) {

        return b1.getData() < b2.getData();
    }

    // Friend function: Overloaded outstream operator
    // Displays data of BinaryTreeNode object
    // Assumes DataType can be outputted to console (or has outstream capabilities) and
    // that DataType has getData member function.
    template <class DataType>
    ostream& operator<<(ostream& out, const BinaryTreeNode<DataType>& li){
        out << li.getData() << endl;

        // check for nullptr to avoid seg fault
        if (li.leftPtr == nullptr)
            out << "leftPtr is nullptr";
        else
            out << "leftPtr " << li.leftPtr->getData();

        if (li.rightPtr == nullptr)
            out << "\nrightPtr is nullptr" << endl;
        else
            out << "\nrightPtr " << li.rightPtr->getData() << endl;

        return out;
    }

}
