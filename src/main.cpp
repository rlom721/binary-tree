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
void GenBTReport();

int main() {

    BinaryTree<string> test;
    // bt.iterate();
    test.insert("Pitt");
    test.insert("Chica");
    test.insert("Atlanta");
    test.insert("Denver");
    test.insert("Seattle");
    test.insert("Rochester");
    test.insert("Wichita");
    test.iterate();
    // test.remove("Pitt");
    test.remove("Denver");
    // cout << "---REMOVED Pitt ---\n";
    cout << "---REMOVED Denver ---\n";
    test.iterate();
    cout << "entries: " << test.getEntries() << endl;

    // GenBTReport();

    return 0;
}

// This function generates reports after sorting and deleting in the
// binary tree.
void GenBTReport() {
    ofstream sortFile;
    sortFile.open("Sort-Report.txt");

    BinaryTree<string> bt;

    bt.insertFromFile("words.txt");
    cout << "bt: " << bt.getEntries();

    sortFile << "SORTED ENTRIES REPORT\n\n"
             << "Ascending order:\n\n";

    bt.sort(BinaryTree<string>::Code::ASCEND);

    for (int i = 0; i < bt.sortedEntries.size(); i++)
        sortFile << bt.sortedEntries[i] << '\n';

        sortFile << "Descending order:\n\n";

        bt.sort(BinaryTree<string>::Code::DESCEND);

        for (int i = 0; i < bt.sortedEntries.size(); i++)
            sortFile << bt.sortedEntries[i] << '\n';

    sortFile.close();
}