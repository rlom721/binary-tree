#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "BinaryTreeNode.h"
#include "BinaryTreeNode.cpp"
#include <iostream>
#include <string>
using namespace std;
using namespace lomboy_a4;

int main() {
    // BinaryTreeNode<int> li(4), li1(5), li2(6);
    // li.setLeft(&li1);
    // li.setRight(&li2);
    // cout << li << endl;

    BinaryTree<string> bt("Loopy");
    // bt.iterate();

    bt.insert("Haha");
    bt.insert("Iostream");
    bt.insert("Floop");
    // bt.iterate();
    bt.clearTree();
    bt.insert("Bababa");
    bt.insert("Cacaca");
    bt.insert("Ababa");
    bt.insert("Don't");
    cout << "1 in tree? " << (bt.search("Bababa") ? "true" : "false") << endl;
    cout << "2 in tree? " << (bt.search("Cacaca") ? "true" : "false") << endl;
    cout << "0 in tree? " << (bt.search("Ababa") ? "true" : "false") << endl;
    cout << "3 in tree? " << (bt.search("Floop") ? "true" : "false") << endl;
    bt.iterate();
    bt.sort(BinaryTree<string>::Code::ASCEND);

    for (int i = 0; i < bt.getEntries(); i++) 
        cout << " " << bt.sortedEntries[i];
    
    cout << endl;

    bt.sort(BinaryTree<string>::Code::DESCEND);

    for (int i = 0; i < bt.getEntries(); i++) 
        cout << " " << bt.sortedEntries[i];
    
    cout << endl;
    BinaryTree<string> copy = bt;
    // bt.remove("Bababa");
    copy.iterate();

    return 0;
}