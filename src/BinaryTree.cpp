#include "BinaryTree.h"    // header file for BinaryTree class
#include <iostream>
#include <fstream>
#include <cassert>
// #include <vector>     
using namespace std;
namespace lomboy_a4 {

    // Default constructor sets rootPtr to nullptr and entry count to 0
    template <class DataType>
    BinaryTree<DataType>::BinaryTree() : rootPtr(nullptr), currentPtr(nullptr), entries(0)
                                        { }

    // Parametrized constructor sets rootPtr to a new node and entry count to 0.
    // It also initializes the node with the entered data.
    template <class DataType>
    BinaryTree<DataType>::BinaryTree(DataType dat) : rootPtr(nullptr), currentPtr(nullptr), 
                          entries(0) { 
        rootPtr = new BinaryTreeNode<DataType>(dat);
    }

    // Copy constructor copies data value (and key via copy assignment) from another 
    // BinaryTree, but NOT its pointers! It sets leftPtr and rightPtr fields to nullptr
    template <class DataType>
    BinaryTree<DataType>::BinaryTree(const BinaryTree& bt) {
        rootPtr = copyTree(bt.rootPtr);

        entries = bt.entries;
    }

    // destructor clears tree
    template <class DataType>
    BinaryTree<DataType>::~BinaryTree() {
        clearTree();
    }

    // Inserts an entry to the next available leaf
    template <class DataType>
    void BinaryTree<DataType>::insert(DataType dat) {
        // if (rootPtr != nullptr) cout << "Root is: " << *rootPtr << endl;
        // empty tree case, create node for root
        if (rootPtr == nullptr) {
            rootPtr = new BinaryTreeNode<DataType>(dat);
            // right and left pointers are nullptr by default
        }
        // recursive insert to look for empty spot
        else {
            insert(dat, rootPtr);
        }

        entries++;
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
            // call recursive insert
            else {
                insert(dat, nodePtr->getRight());
            }
        }

        // avoid dangling pointer (automatically freed after going OOS)
        tempNode = nullptr;
    }

    // This method returns true if entry is found within tree.
    template <class DataType>
    bool BinaryTree<DataType>::search(DataType entry) {
        // empty tree case
        if (rootPtr == nullptr) {
            return false;
        }
        // recursive search
        else {
            return search(entry, rootPtr);
        }
    }

    // Helper function - recursively inserts an entry to the next available leaf
    template <class DataType>
    bool BinaryTree<DataType>::search(DataType entry, BinaryTreeNode<DataType>* nodePtr) {
        // entry matches data of node
        if (nodePtr->getData() == entry) {
            return true;
        }
        // data precedes current node's data, so search on left
        else if (entry < nodePtr->getData()) {
            // empty left node found, so return it
            if (nodePtr->getLeft() == nullptr) {
                return false;
            }
            // call recursive search
            else {
                return search(entry, nodePtr->getLeft());
            }
        }
        // data proceeds current node's data, so search on left
        else {
            // empty left node found, so create new node
            if (nodePtr->getRight() == nullptr) {
                return false;
            }
            // call recursive search
            else {
                return search(entry, nodePtr->getRight());
            }
        }
    }

    template <class DataType>
    void BinaryTree<DataType>::print() {
        dispInorder(rootPtr);
    } 

    // This method takes a pointer to function and applies it to each entry in the
    // binary tree, traversing through it in the indicated mode.
    template <class DataType>
    void BinaryTree<DataType>::iterate(void (*func)(DataType), Code orderMode) {
        process(func, rootPtr, orderMode);
    }

    // This method clears all tree entries, leaving rootPtr nullptr.
    template <class DataType>
    void BinaryTree<DataType>::clearTree() {
        // clear entries if tree is not empty
        clearTree(rootPtr);
        sortedEntries.clear();
        entries = 0;
    }

    // This helper method is the recursive version of clearTree.
    template <class DataType>
    void BinaryTree<DataType>::clearTree(BinaryTreeNode<DataType>*& nodePtr) {
        // clear entries if tree is not empty
        if (nodePtr != nullptr) {
            // clear left and right subtrees
            clearTree(nodePtr->getLeft());
            clearTree(nodePtr->getRight());
            
            // finally, clear node at root
            delete nodePtr;
            nodePtr = nullptr;
        }
    }

    // Iterates over all entries in tree, printing in-order (LT ROOT RT)
    template <class DataType>
    void BinaryTree<DataType>::dispInorder(const BinaryTreeNode<DataType>* nodePtr) {
        if (nodePtr != nullptr) {
            dispInorder(nodePtr->getLeft());
            // cout << nodePtr->getData() << endl;
            cout << *nodePtr << endl;
            dispInorder(nodePtr->getRight());
        }
    }

    // Sorts entries in tree and stores them in the array passed
    template <class DataType>
    void BinaryTree<DataType>::sort(Code orderMode) {
        int index = 0;
        sortedEntries.clear();
        
        sortToArray(orderMode, rootPtr, index);
    }

    // Helper function - sorts entries in tree and stores them in the array passed
    template <class DataType>
    void BinaryTree<DataType>::sortToArray(Code orderMode, BinaryTreeNode<DataType>* nodePtr, int& index) {

        if (nodePtr != nullptr) {
            if (orderMode == Code::ASCEND) {
                // ascending sort by adding to array in-order
                sortToArray(orderMode, nodePtr->getLeft(), index);
                sortedEntries.push_back(nodePtr->getData());
                sortToArray(orderMode, nodePtr->getRight(), index);
            }
            else if (orderMode == Code::DESCEND) {
                // descending sort by adding to array in-order
                sortToArray(orderMode, nodePtr->getRight(), index);
                sortedEntries.push_back(nodePtr->getData());
                sortToArray(orderMode, nodePtr->getLeft(), index);
            }
        }
    }

    // Deletes an entry in tree
    template <class DataType>
    void BinaryTree<DataType>::remove(DataType entry) {
        rootPtr = remove(entry, rootPtr);
        entries--;
    }

    // Helper function - recursively deletes an entry in tree, returning new root (of that portion of tree)
    template <class DataType>
    BinaryTreeNode<DataType>* BinaryTree<DataType>::remove(DataType entry, BinaryTreeNode<DataType>*& nodePtr) {
        // BinaryTreeNode<DataType>* tempPtr;    // pointer of entry to delete
        
        // empty tree
        if (nodePtr == nullptr) {
            return nullptr;
        }
        // data precedes current node's data, so remove on left
        else if (entry < nodePtr->getData()) {
            remove(entry, nodePtr->getLeft());
        }
        // data proceeds current node's data, so remove on right
        else if (entry > nodePtr->getData()) {
            remove(entry, nodePtr->getRight());
        }
        // data matches the current node!
        else {
            // current node doesn't have left child, OR is a leaf
            if (nodePtr->getLeft() == nullptr) {
                BinaryTreeNode<DataType>* tempPtr = nodePtr;
                nodePtr = nodePtr->getRight();
                delete tempPtr;
            }
            // current node has two children
            else {
                // find max value in left tree, copy data to entryPtr
                BinaryTreeNode<DataType>* tempPtr = findMax(nodePtr->getLeft());
                nodePtr->set(tempPtr->getData());

                // delete old location of max value and reassign current node's left pointer
                nodePtr->setLeft(remove(tempPtr->getData(), nodePtr->getLeft()));
            }
        }
        
        return nodePtr;
    }

    // Returns pointer to maximum value in a (sub)tree
    template <class DataType>
    BinaryTreeNode<DataType>* BinaryTree<DataType>::findMax(BinaryTreeNode<DataType>* currentPtr) {
        BinaryTreeNode<DataType>* maxPtr = currentPtr;

        while (maxPtr != nullptr && maxPtr->getRight() != nullptr)
            maxPtr = maxPtr->getRight();

        return maxPtr;
    }

    template <class DataType>
    BinaryTreeNode<DataType>* BinaryTree<DataType>::copyTree(BinaryTreeNode<DataType>* root) {
        BinaryTreeNode<DataType>* copyNode;

        if (root == NULL) 
            return nullptr;
        // create copy of root
        copyNode = new BinaryTreeNode<DataType>(root->getData());
        // copy left and right subtrees
        copyNode->setLeft(copyTree(root->getLeft()));
        copyNode->setRight(copyTree(root->getRight()));

        return copyNode;
    }

    // This method takes a data file name and inserts all records into the binary tree
    // from file, line by line.
    template <class DataType>
    void BinaryTree<DataType>::insertFromFile(string fileName) {
        ifstream inFile;
        string line, word;
        inFile.open(fileName);

        // check for failure in opening file
        assert(inFile);

        // read data in from file loop until end of file reached
        while (getline(inFile, line)) {
            // parse each line 
            word = line.substr(0, line.find('\n'));

            //insert text to tree
            insert(word);
        }

        inFile.close();
    }

    // This helper method takes a pointer to function and applies it to each entry in the
    // binary tree, traversing through it in the indicated mode.
    template <class DataType>
    void BinaryTree<DataType>::process(void (*func)(DataType), BinaryTreeNode<DataType>* nodePtr, Code orderMode) {
        if (nodePtr != nullptr) {
            // pre-order processing
            if (orderMode == Code::PREORDER) {
                func(nodePtr->getData());
                process(func, nodePtr->getLeft(), orderMode);
                process(func, nodePtr->getRight(), orderMode);
            }
            // in-order processing
            else if (orderMode == Code::INORDER) {
                process(func, nodePtr->getLeft(), orderMode);
                func(nodePtr->getData());
                process(func, nodePtr->getRight(), orderMode);
            }
            // post-order processing
            else if (orderMode == Code::POSTORDER) {
                process(func, nodePtr->getLeft(), orderMode);
                process(func, nodePtr->getRight(), orderMode);
                func(nodePtr->getData());
            }
        }
    }
}