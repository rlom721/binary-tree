#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "BinaryTreeNode.h"
#include "BinaryTreeNode.cpp"
using namespace std;
using namespace lomboy_a4;

int main() {
    // BinaryTreeNode<int> li(4), li1(5), li2(6);
    // li.setLeft(&li1);
    // li.setRight(&li2);
    // cout << li << endl;

    BinaryTree<int> bt(7);
    // bt.iterate();

    bt.insert(5);
    bt.insert(6);
    bt.insert(4);
    // bt.iterate();
    bt.clearTree();
    bt.insert(1);
    bt.insert(2);
    bt.insert(0);
    bt.insert(3);
    cout << "1 in tree? " << (bt.search(1) ? "true" : "false") << endl;
    cout << "2 in tree? " << (bt.search(2) ? "true" : "false") << endl;
    cout << "0 in tree? " << (bt.search(0) ? "true" : "false") << endl;
    cout << "3 in tree? " << (bt.search(3) ? "true" : "false") << endl;
    cout << "4 in tree? " << (bt.search(4) ? "true" : "false") << endl;
    bt.iterate();
    bt.sort(BinaryTree<int>::Code::ASCEND);

    for (int i = 0; i < bt.getEntries(); i++) 
        cout << " " << bt.sortedEntries[i];
    
    cout << endl;

    bt.sort(BinaryTree<int>::Code::DESCEND);

    for (int i = 0; i < bt.getEntries(); i++) 
        cout << " " << bt.sortedEntries[i];
    
    cout << endl;

    return 0;
}