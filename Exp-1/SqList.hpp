#pragma once
#include <iostream>
using namespace std;
constexpr int initcap = 5;
template <typename T>
class SqList
{
public:
    T* data;
    int capacity;
    int length;
    SqList() {
        data = new T[initcap];
        capacity = initcap;
        length = 0;
    }
    SqList(const SqList<T>& s) {
        capacity = s.capacity;
        length = s.length;
        data = new T[capacity];
        for (int i = 0; i < length; i++) {
            data[i] = s.data[i];
        }
    }
    ~SqList() {
        delete[] data;
        data = nullptr;
    }
    void recap(int newcap) {
        if (newcap <= 0) {
            return;
        }
        T* olddata = data;
        data = new T[newcap];
        capacity = newcap;
        for (int i = 0; i < length; i++) {
            data[i] = olddata[i];
        }
        delete[] olddata;
    }
    void CreateList(T a[], int n) {
        length = 0;
        for (int i = 0; i < n; i++) {
            if (length == capacity) {
                recap(2 * length);
            }
            data[length] = a[i];
            length++;
        }
    }
    void Add(T e) {
        if (length == capacity) {
            recap(2 * length);
        }
        data[length] = e;
        length++;
    }
    int GetLength() {
        return length;
    }
    bool GetElem(int i, T& e) {
        if (i < 0 || i >= length) {
            return false;
        }
        e = data[i];
        return true;
    }
    bool SetElem(int i, T e) {
        if (i < 0 || i >= length) {
            return false;
        }
        data[i] = e;
        return true;
    }
    int GetNo(T e) {
        int i = 0;
        while (i < length&& data[i] != e) {
            i++;
        }
        if (i >= length) {
            return -1;
        }
        return i;
    }
    bool Insert(int i, T e) {
        if (i<0 || i>length) {
            return false;
        }
        if (length == capacity) {
            recap(2 * length);
        }
        for (int j = length; j > i; j--) {
            data[j] = data[j - 1];
        }
        data[i] = e;
        length++;
        return true;
    }
    bool Delete(int i) {
        if (i < 0 || i > length) {
            return false;
        }
        for (int j = i; j < length - 1; j++) {
            data[j] = data[j + 1];
        }
        length--;
        if (capacity > initcap && length <= capacity / 4) {
            recap(capacity / 2);
        }
        return true;
    }
    void DispList() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};