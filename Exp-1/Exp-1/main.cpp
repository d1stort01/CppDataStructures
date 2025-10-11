#include "SqList.hpp"	//引用顺序表类 
#include <vector>

// 第七题

// 第八题

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
	cout << "Vecotr: " << endl;
	Disp(Av);
	Disp(Bv);

	cout << "\nSqList差集结果" << endl;
	difference(A, B, C1);
	C1.DispList();

	cout << "Vecotr差集结果" << endl;
	difference(Av, Bv, C1v);
	C1.DispList();


	cout << "\n创建整数顺序表" << endl;
	A.CreateList(a2, 3);
	B.CreateList(b2, 4);

	Av.assign(a2, a2 + sizeof(a2) / sizeof(a2[0]));
	Bv.assign(b2, b2 + sizeof(b2) / sizeof(b2[0]));

	cout << "SqList: " << endl;
	A.DispList();
	B.DispList();
	cout << "Vecotr: " << endl;
	Disp(Av);
	Disp(Bv);

	intersection(A, B, C2);
	intersection(Av, Bv, C2v);

	cout << "\nSqList交集结果" << endl;
	C2.DispList();

	cout << "\Vecotr交集结果" << endl;
	Disp(C2v);

	return 0;
}



