#include <string>
using namespace std;

struct BTNode {
    char data;
    BTNode* left_child;
    BTNode* right_child;

    BTNode() :data('#'), left_child(nullptr), right_child(nullptr) {}
    BTNode(char d) {
        data = d;
        left_child = nullptr;
        right_child = nullptr;
    }
};

class BTree {
public:
    static void PreOrder(BTree& bt);
    static void InOrder(BTree& bt);
    static void PostOrder(BTree& bt);

    BTree() :root(nullptr) {}
    ~BTree() { DestroyBTree(root); }
    void CreateBTree(string str);
    void DisplayBTree();
    int getHeight();
    int getWidth();
private:
    static void PreOrder1(BTNode* node);
    static void InOrder1(BTNode* node);
    static void PostOrder1(BTNode* node);

    BTNode* root;

    void DisplayBTree1(BTNode* node);
    void DestroyBTree(BTNode* node);
    int getHeight1(BTNode* node);
};