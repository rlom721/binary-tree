// Program Name:    Dictionary (Binary Tree)
// File Name:       main.cpp
// Author:          Rafaela Lomboy
// Date:            2021.05.14
// Description:     This program demonstrates the insert, sort and deletion of the
//                  dictionary, which was implemented using a binary tree.
//                  It produces the results of the stub program in two report files.

#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "BinaryTreeNode.h"
#include "BinaryTreeNode.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using namespace lomboy_a4;

// function prototypes
void GenBTReports();

int main() {
    GenBTReports();

    return 0;
}

// This function generates reports after sorting and deleting in the
// binary tree.
void GenBTReports() {
    ofstream sortFile, deleteFile;

    // file contains sorted entries report
    sortFile.open("Sort-Report.txt");

    // file contains sorted entries after deletion
    deleteFile.open("Delete-Report.txt");

    BinaryTree<string> bt;

    bt.insertFromFile("words.txt");

    sortFile << "SORTED ENTRIES REPORT\n\n"
             << "Ascending order:\n\n";

    bt.sort(BinaryTree<string>::Code::ASCEND);

    for (int i = 0; i < static_cast<int>(bt.sortedEntries.size()); i++)
        sortFile << bt.sortedEntries[i] << '\n';

    sortFile << "\nDescending order:\n\n";

    bt.sort(BinaryTree<string>::Code::DESCEND);

    for (int i = 0; i < static_cast<int>(bt.sortedEntries.size()); i++)
        sortFile << bt.sortedEntries[i] << '\n';

    cout << "entries: " << bt.getEntries() << endl;

    deleteFile << "DELETED ENTRIES REPORT\n\n"
             << "The following entries have been deleted from the report:\n"
             << "\t\tIsolation, Normalization, Distributed Processing\n\n";
    
    bt.remove("Isolation");
    bt.remove("Normalization");
    bt.remove("Distributed Processing");

    deleteFile << "Ascending order:\n\n";

    bt.sort(BinaryTree<string>::Code::ASCEND);

    for (int i = 0; i < static_cast<int>(bt.sortedEntries.size()); i++)
        deleteFile << bt.sortedEntries[i] << '\n';

    deleteFile << "\nDescending order:\n\n";

    bt.sort(BinaryTree<string>::Code::DESCEND);

    for (int i = 0; i < static_cast<int>(bt.sortedEntries.size()); i++)
        deleteFile << bt.sortedEntries[i] << '\n';

    cout << "entries: " << bt.getEntries() << endl;

    bt.print();

    sortFile.close();
    deleteFile.close();
}