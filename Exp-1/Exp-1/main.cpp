#include "SqList.hpp"	//引用顺序表类 
#include <vector>
#include <iostream>
using namespace std;
// 第七题
void differenceSqList(SqList<int>& A, SqList<int>& B, SqList<int>& C) {
    if (C.length != 0) {
        return;
    }
    for (int i = 0; i < A.GetLength(); i++) {
        int elem;                   // A复制到C
        A.GetElem(i, elem);
        C.Add(elem);                
    }
    for (int i = 0; i < B.GetLength(); i++) {
        int elem;
        B.GetElem(i, elem);         // 遍历B
        int pos = C.GetNo(elem);
        if (pos != -1) {            // C中存在B的元素则删除
            C.Delete(pos);
        }
    }
}
void differenceVector(vector<int>& A, vector<int>& B, vector<int>& C) {
    C = A;
    for (int i = 0; i < B.size(); i++) {
        auto it = find(C.begin(), C.end(), B[i]);
        if (it != C.end()) {
            C.erase(it);
        }
    }
}
// 第八题
void intersectionSqList(SqList<int>& A, SqList<int>& B, SqList<int>& C) {
    if (C.length != 0) {
        return;
    }
    for (int i = 0; i < A.GetLength(); i++) {
        int elem;                       // 遍历A
        A.GetElem(i, elem);
        if (B.GetNo(elem) != -1) {      // B中存在A的元素则加入C
            C.Add(elem);
        }
    }
}
void intersectionVector(vector<int>& A, vector<int>& B, vector<int>& C) {
    C.clear();
    for (int i = 0; i < A.size(); i++) {
        if (find(B.begin(), B.end(), A[i]) != B.end()) {
            C.push_back(A[i]);
        }
    }
}
void Disp(vector<int>& myv)		       //输出vector的元素
{
    vector<int>::iterator it;
    for (it = myv.begin(); it != myv.end(); it++)
        cout << *it << " ";
    cout << endl;
}
int main()
{
    int a1[] = { 1, 3, 5, 7 };
    int b1[] = { 1, 2, 4, 5, 9 };
    int a2[] = { 1, 3, 2 };
    int b2[] = { 5, 1, 4, 2 };

    SqList<int> A, B, C1, C2;  //建立类型为int的顺序表对象
    vector<int> Av, Bv, C1v, C2v;

    cout << "创建整数顺序表" << endl;
    A.CreateList(a1, 4);
    B.CreateList(b1, 5);
    Av.assign(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    Bv.assign(b1, b1 + sizeof(b1) / sizeof(b1[0]));

    cout << "SqList: " << endl;
    A.DispList();
    B.DispList();
    cout << "Vector: " << endl;
    Disp(Av);
    Disp(Bv);

    cout << "\nSqList差集结果" << endl;
    differenceSqList(A, B, C1);
    C1.DispList();

    cout << "Vector差集结果" << endl;
    differenceVector(Av, Bv, C1v);
    C1.DispList();


    cout << "\n创建整数顺序表" << endl;
    A.CreateList(a2, 3);
    B.CreateList(b2, 4);

    Av.assign(a2, a2 + sizeof(a2) / sizeof(a2[0]));
    Bv.assign(b2, b2 + sizeof(b2) / sizeof(b2[0]));

    cout << "SqList: " << endl;
    A.DispList();
    B.DispList();
    cout << "Vector: " << endl;
    Disp(Av);
    Disp(Bv);

    intersectionSqList(A, B, C2);
    intersectionVector(Av, Bv, C2v);

    cout << "\nSqList交集结果" << endl;
    C2.DispList();

    cout << "Vector交集结果" << endl;
    Disp(C2v);

    return 0;
}