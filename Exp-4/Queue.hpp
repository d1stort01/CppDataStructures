#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct LinkNode								//链队数据结点类型
{
    T data;									//结点数据域
    LinkNode* next;							//指向下一个结点
    LinkNode() :next(NULL) {}				//构造函数 
    LinkNode(T d) :data(d), next(NULL) {}	//重载构造函数 
};

template <typename T>
class Queue					//链队类模板
{
public:
    LinkNode<T>* rear;		//队尾指针
    Queue();	            //构造函数 
    ~Queue();				//析构函数
    bool empty() const; 	//判队空运算 
    bool push(T e);			//进队运算
    bool pop(T& e);			//出队运算
    bool gethead(T& e);		//取队头运算
    bool getbottom(T& e);	//取队头运算
    bool display() const;

    Queue(const Queue<T>& other);
    Queue<T>& operator=(const Queue<T>& other);
};
