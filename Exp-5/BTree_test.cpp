#include "BTree.hpp"
#include <iostream>
int main()
{
    string tree = "A(B(D(,G)),C(E,F))";
    cout << "str: " + tree << endl;
    BTree btree;
    btree.CreateBTree(tree);
    btree.DisplayBTree();
    BTree::PreOrder(btree);
    BTree::InOrder(btree);
    BTree::PostOrder(btree);
    cout << "height: " << btree.getHeight() << endl;
    cout << "width: " << btree.getWidth() << endl;
    return 0;
}