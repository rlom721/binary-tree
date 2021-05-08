#include "BinaryTree.h"    // header file for BinaryTree class
#include <iostream>
using namespace std;
namespace lomboy_a4 {

    // Default constructor sets rootPtr to nullptr and entry count to 0
    template <class DataType>
    BinaryTree<DataType>::BinaryTree() : rootPtr(nullptr), currentPtr(nullptr), entries(0) { }

    // Parametrized constructor sets rootPtr to a new node and entry count to 0.
    // It also initializes the node with the entered data.
    template <class DataType>
    BinaryTree<DataType>::BinaryTree(DataType dat) : rootPtr(nullptr), currentPtr(nullptr), entries(0) { 
        rootPtr = new BinaryTreeNode<DataType>(dat);
    }

    // Copy constructor copies data value (and key via copy assignment) from another 
    // BinaryTree, but NOT its pointers! It sets leftPtr and rightPtr fields to nullptr
    template <class DataType>
    BinaryTree<DataType>::BinaryTree(const BinaryTree& bt) {
        // COPY ROOT AND CURRENT! PTRS
        entries = bt.entries;
    }

    // Inserts an entry to the next available leaf
    template <class DataType>
    void BinaryTree<DataType>::insert(DataType dat) {
        // empty tree case, create node for root
        if (rootPtr == nullptr) {
            rootPtr = new BinaryTreeNode<DataType>(dat);
            // right and left pointers are nullptr by default
        }
        // recursive insert to look for empty spot
        else {
            insert(dat, rootPtr);
        }
    }

    // Helper function - recursively inserts an entry to the next available leaf
    template <class DataType>
    void BinaryTree<DataType>::insert(DataType dat, BinaryTreeNode<DataType>* nodePtr) {
        // NEED TO LINK NODES!
        BinaryTreeNode<DataType>* tempNode;     // for creating new nodes

        // data precedes current node's data, call recursive insert on left
        if (dat < nodePtr->getData()) {
            // empty left node found, so create new node
            if (nodePtr->getLeft() == nullptr) {
                // cout << "Inserting " << dat << " on left!\n";
                tempNode = new BinaryTreeNode<DataType>(dat);
                nodePtr->setLeft(tempNode);
                currentPtr = nodePtr->getLeft();
            }
            // call recursive insert
            else {
                insert(dat, nodePtr->getLeft());
            }
        }
        // data proceeds current node's data, call recursive insert on right
        else {
            // empty left node found, so create new node
            if (nodePtr->getRight() == nullptr) {
                // cout << "Inserting " << dat << " on right!\n";
                tempNode = new BinaryTreeNode<DataType>(dat);
                nodePtr->setRight(tempNode);
                currentPtr = nodePtr->getRight();
            }
            // call recursive insert ?? another comparison
            else {
                insert(dat, nodePtr->getLeft());
            }
        }

        // avoid dangling pointer (automatically freed after going OOS)
        tempNode = nullptr;
    }

    // Iterates over all entries in tree, printing in-order
    template <class DataType>
    void BinaryTree<DataType>::iterate() {
        dispInorder(rootPtr);
    }

    // Iterates over all entries in tree, printing in-order 
    template <class DataType>
    void BinaryTree<DataType>::dispInorder(const BinaryTreeNode<DataType>* nodePtr) {
        if (nodePtr != nullptr) {
            dispInorder(nodePtr->getLeft());
            // cout << nodePtr->getData() << endl;
            cout << *nodePtr << endl;
            dispInorder(nodePtr->getRight());
        }
    }
}