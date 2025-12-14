#include "BTree.hpp"
#include <stack>
#include <queue>
#include <iostream>

void BTree::PreOrder(BTree& bt)
{
    if (bt.root != nullptr) {
        stack<BTNode*> st;
        BTNode* p;
        st.push(bt.root);
        while (!st.empty()) {
            p = st.top();
            st.pop();
            cout << p->data;
            if (p->right_child != nullptr) {
                st.push(p->right_child);
            }
            if (p->left_child != nullptr) {
                st.push(p->left_child);
            }
        }
        cout << endl;
    }
}

void BTree::InOrder(BTree& bt)
{
    InOrder1(bt.root);
    cout << endl;
}

void BTree::PostOrder(BTree& bt)
{
    PostOrder1(bt.root);
    cout << endl;
}

void BTree::CreateBTree(string str)
{
    stack<BTNode*> st;
    BTNode* p = nullptr;
    bool flag = false;
    int i = 0;

    while (i < str.length()) {
        switch (str[i]) {
        case '(':
            st.push(p);
            flag = true;
            break;
        case ')':
            st.pop();
            break;
        case ',':
            flag = false;
            break;
        default:
            p = new BTNode(str[i]);
            if (root == nullptr) {
                root = p;
            }
            else if (!st.empty()) {
                if (flag)
                    st.top()->left_child = p;
                else
                    st.top()->right_child = p;
            }
            break;
        }
        i++;
    }
}

void BTree::DisplayBTree()
{
    DisplayBTree1(root);
    cout << endl;
}

int BTree::getHeight()
{
    return getHeight1(root);
}

int BTree::getWidth()
{
    if (!root) return 0;
    queue<BTNode*> q;
    q.push(root);
    int max_wid = 0;
    while (!q.empty()) {
        int sz = q.size();
        max_wid = max(max_wid, sz);
        for (int i = 0; i < sz; ++i) {
            BTNode* p = q.front();
            q.pop();
            if (p->left_child)
                q.push(p->left_child);
            if (p->right_child)
                q.push(p->right_child);
        }
    }
    return max_wid;
}

void BTree::PreOrder1(BTNode* node)
{
    if (node != nullptr) {
        cout << node->data;
        PreOrder1(node->left_child);
        PreOrder1(node->right_child);
    }
}

void BTree::InOrder1(BTNode* node)
{
    if (node != nullptr) {
        InOrder1(node->left_child);
        cout << node->data;
        InOrder1(node->right_child);
    }
}

void BTree::PostOrder1(BTNode* node)
{
    if (node != nullptr) {
        PostOrder1(node->left_child);
        PostOrder1(node->right_child);
        cout << node->data;
    }
}

void BTree::DisplayBTree1(BTNode* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        if (node->left_child != nullptr || node->right_child != nullptr) {
            cout << "(";
            DisplayBTree1(node->left_child);
            if (node->right_child != nullptr) {
                cout << ",";
            }
            DisplayBTree1(node->right_child);
            cout << ")";
        }

    }
}

void BTree::DestroyBTree(BTNode* node)
{
    if (node != nullptr) {
        DestroyBTree(node->left_child);
        DestroyBTree(node->right_child);
        delete node;
    }
}

int BTree::getHeight1(BTNode* node)
{
    if (node == nullptr) return 0;
    int lh = getHeight1(node->left_child);
    int rh = getHeight1(node->right_child);
    return max(lh, rh) + 1;
}
