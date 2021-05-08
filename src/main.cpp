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
    bt.iterate();

    return 0;
}