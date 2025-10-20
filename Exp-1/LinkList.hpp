#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct LinkNode
{
    T data;
    LinkNode<T>* next;
    LinkNode() :next(nullptr) {}
    LinkNode(T d) :data(d), next(nullptr) {}
};

template<typename T>
class LinkList
{
public:
    LinkNode<T>* head;
    LinkList() {
        head = new LinkNode<T>();
    }
    ~LinkList() {
        LinkNode<T>* pre, * p;
        pre = head;
        p = pre->next;
        while (p != nullptr) {
            delete pre;
            pre = p;
            p = pre->next;
        }
        delete pre;
    }
    void CreateListF(T a[], int n) {
        for (int i = 0; i < n; i++)
        {
            LinkNode<T>* s = new LinkNode<T>(a[i]);
            s->next = head->next;
            head->next = s;
        }
    }
    void CreateListR(T a[], int n) {
        LinkNode<T>* s, * r;
        r = head;
        for (int i = 0; i < n; i++)
        {
            s = new LinkNode<T>(a[i]);
            r->next = s;
            r = s;
        }
        r->next = nullptr;
    }
    LinkNode<T>* geti(int i) {
        if (i < -1) {
            return nullptr;
        }
        LinkNode<T>* p = head;
        int j = -1;
        while (j < i && p != nullptr) {
            j++;
            p = p->next;
        }
        return p;
    }
    void Add(T e) {
        LinkNode<T>* s = new LinkNode<T>(e);
        LinkNode<T>* p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = s;
    }
    int Getlength() {
        LinkNode<T>* p = head;
        int cut = 0;
        while (p->next != nullptr) {
            cut++;
            p = p->next;
        }
        return cut;
    }
    bool GetElem(int i, T& e) {
        if (i < 0) {
            return false;
        }
        LinkNode<T>* p = geti(i);
        if (p != nullptr) {
            e = p->data;
            return true;
        }
        else {
            return false;
        }
    }
    bool SetElem(int i, T& e) {
        if (i < 0) {
            return false;
        }
        LinkNode<T>* p = geti(i);
        if (p != nullptr) {
            p->data = e;
            return true;
        }
        else {
            return false;
        }
    }
    int GetNo(T e) {
        int j = 0;
        LinkNode<T>* p = head->next;
        while (p != nullptr && p->data != e) {
            j++;
            p = p->next;
        }
        if (p == nullptr) {
            return -1;
        }
        else {
            return j;
        }
    }
    bool Insert(int i, T& e) {
        if (i < 0) {
            return false;
        }
        LinkNode<T>* p = geti(i - 1);
        if (p != nullptr) {
            LinkNode<T>* s = new LinkNode<T>(e);
            s->next = p->next;
            p->next = s;
            return true;
        }
        else {
            return false;
        }
    }
    bool Delete(int i) {
        if (i < 0) {
            return false;
        }
        LinkNode<T>* p = geti(i - 1);
        if (p != nullptr) {
            LinkNode<T>* q = p->next;
            if (q != nullptr) {
                p->next = q->next;
                delete q;
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    void Display() {
        LinkNode<T>* p;
        p = head->next;
        while (p != nullptr) {
            cout << p->data << ' ';
            p = p->next;
        }
        cout << '\n';
    }
};