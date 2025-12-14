#include "BSTree.cpp"

int main()
{
    vector<int> a = { 25, 18, 46, 2, 53, 39, 32, 4, 74, 67, 60, 11 };
    vector<int> b = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    cout << "\n  (1)关键字序列(不考虑值)\n    ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
    BSTClass<int, int> bst;
    cout << "  (2)创建BSTbst\n";
    bst.CreateBST(a, b);
    cout << "  (3)输出BST\n";
    cout << "    BST: "; bst.DispBST(); cout << endl;
    cout << "  (4)删除操作\n";
    vector<int> c = { 2, 4, 60, 25, 32, 11 };
    for (int i = 0; i < c.size(); i++)
    {
        bst.DeleteBST(c[i]);
        printf("    删除%2d后: ", c[i]); bst.DispBST(); cout << endl;
    }
    cout << "  (5)插入操作\n";
    vector<int> d = { 32, 11, 1 };
    for (int i = 0; i < d.size(); i++)
    {
        bst.InsertBST(d[i], b[i]);
        printf("    插入%2d后: ", d[i]); bst.DispBST(); cout << endl;
    }

    cout << "  (6)删除最小值3次\n";
    for (int i = 0; i < 3; i++) {
        bst.deleteMin();
        printf("    删除最小值后: "); bst.DispBST(); cout << endl;
    }

    cout << "  (7)小于x的结点数量\n";
    vector<int> e = { 46,32,31,74,66 };
    for (int i = 0; i < e.size(); i++)
    {
        printf("    小于%d的结点数量:%d ", e[i], bst.findKsmaller(e[i])); cout << endl;
    }

    cout << "  (8)将树转为从大到小\n";
    bst.exchange();
    printf("    转化后: "); bst.DispBST(); cout << endl;

    return 0;
}

