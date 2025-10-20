#include <iostream>
#include "PolyList.hpp"
using std::cout;

int main() {
    PolyList A, B, C1, C2, C3;  // 建立多项式单链表对象
    A.CreateList("abc1.in");
    cout << "第1个多项式: ";
    A.DispPoly();
    A.Sort();
    cout << "排序后结果:  ";
    A.DispPoly();

    B.CreateList("abc2.in");
    cout << "\n第2个多项式: ";
    B.DispPoly();
    B.Sort();
    cout << "排序后结果:  ";
    B.DispPoly();

    PolyAdd(A, B, C1);
    cout << "\n相加多项式:  ";
    C1.DispPoly();

    PolySubstract(A, B, C2);
    cout << "\n相减多项式:  ";
    C2.DispPoly();

    PolyMultiply(A, B, C3);
    cout << "\n相乘多项式:  ";
    C3.DispPoly();

    A.insertOrder(new PolyNode(3.3, 3));
    cout << "\n第1个多项式插入节点[3.3,3]: ";
    A.DispPoly();

    double x = 3.14;
    cout << "\n第1个多项式在x=" << x << "处的值为: " << A.value(x);
    return 0;
}
