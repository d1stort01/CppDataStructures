#include <iostream>
#include "PolyList.hpp"
using std::cout;

int main() {
    PolyList A, B, C1, C2, C3;  // ��������ʽ���������
    A.CreateList("abc1.in");
    cout << "��1������ʽ: ";
    A.DispPoly();
    A.Sort();
    cout << "�������:  ";
    A.DispPoly();

    B.CreateList("abc2.in");
    cout << "\n��2������ʽ: ";
    B.DispPoly();
    B.Sort();
    cout << "�������:  ";
    B.DispPoly();

    PolyAdd(A, B, C1);
    cout << "\n��Ӷ���ʽ:  ";
    C1.DispPoly();

    PolySubstract(A, B, C2);
    cout << "\n�������ʽ:  ";
    C2.DispPoly();

    PolyMultiply(A, B, C3);
    cout << "\n��˶���ʽ:  ";
    C3.DispPoly();

    A.insertOrder(new PolyNode(3.3, 3));
    cout << "\n��1������ʽ����ڵ�[3.3,3]: ";
    A.DispPoly();

    double x = 3.14;
    cout << "\n��1������ʽ��x=" << x << "����ֵΪ: " << A.value(x);
    return 0;
}
