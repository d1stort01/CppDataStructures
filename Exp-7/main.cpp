#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "LinkList.cpp"
using namespace std;
void disp(vector<int>& R, int low, int high)
{
    for (int i = low; i <= high; i++)
        printf("%d ", R[i]);
    printf("\n");
}
void disp2(LinkList<int>& L)
{
    LinkNode<int>* p = L.head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

bool comp(int A, int B) {
    return A < B;
}

void InsertSort(vector<int>& R, int n) {
    for (int i = 1; i < n; i++) {
        if (!comp(R[i - 1], R[i])) {
            int t = R[i];
            int j = i - 1;
            do {
                R[j + 1] = R[j];
                j--;
            } while (j >= 0 && !comp(R[j], t));
            R[j + 1] = t;
        }
        disp(R, 0, n - 1);
    }
}

void ShellSort(vector<int>& R, int n) {
    int d = n / 2;
    while (d > 0) {
        for (int i = d; i < n; i++) {
            if (!comp(R[i - d], R[i])) {
                int t = R[i];
                int j = i - d;
                do {
                    R[j + d] = R[j];
                    j -= d;
                } while (j >= 0 && !comp(R[j], t));
                R[j + d] = t;
            }
        }
        d /= 2;
        disp(R, 0, n - 1);
    }
}

void BubbleSort(vector<int>& R, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool exchange = false;
        for (int j = n - 1; j > i; j--) {
            if (!comp(R[j - 1], R[j])) {
                swap(R[j - 1], R[j]);
                exchange = true;
            }
        }
        if (!exchange) {
            return;
        }
        disp(R, 0, n - 1);
    }
}

int Partition(vector<int>& R, int s, int t) {
    int base = R[s];
    int i = s;
    int j = s + 1;
    while (j <= t) {
        if (comp(R[j], base)) {
            i++;
            if (i != j) {
                swap(R[i], R[j]);
            }
        }
        j++;
    }
    swap(R[s], R[i]);
    return i;
}

void _QuickSort(vector<int>& R, int s, int t) {
    if (s < t) {
        int i = Partition(R, s, t);
        disp(R, 0, R.size() - 1);
        _QuickSort(R, s, i - 1);
        _QuickSort(R, i + 1, t);
    }
}

void QuickSort(vector<int>& R, int n) {
    _QuickSort(R, 0, n - 1);
}

void SelectSort(vector<int>& R, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_j = i;
        for (int j = i + 1; j < n; j++) {
            if (R[j] < R[min_j]) {
                min_j = j;
            }
        }
        if (min_j != i) {
            swap(R[i], R[min_j]);
        }
        disp(R, 0, n - 1);
    }
}

void siftDown(vector<int>& R, int low, int high) {
    int i = low;
    int j = 2 * i + 1;
    int tmp = R[i];
    while (j <= high) {
        if (j < high&& comp(R[j], R[j + 1])) {
            j++;
        }
        if (!comp(R[j], tmp)) {
            R[i] = R[j];
            i = j;
            j = 2 * i + 1;
        }
        else {
            break;
        }
    }
    R[i] = tmp;
}

void HeapSort(vector<int>& R, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        siftDown(R, i, n - 1);
        disp(R, 0, n - 1);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(R[0], R[i]);
        siftDown(R, 0, i - 1);
        disp(R, 0, n - 1);
    }
}

void Merge(vector<int>& R, int low, int mid, int high) {
    vector<int> R1;
    R1.resize(high - low + 1);
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high) {
        if (comp(R[i], R[j])) {
            R1[k] = R[i];
            i++;
            k++;
        }
        else {
            R1[k] = R[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        R1[k] = R[i];
        i++;
        k++;
    }
    while (j <= high) {
        R1[k] = R[j];
        j++;
        k++;
    }
    for (k = 0, i = low; i <= high; k++, i++) {
        R[i] = R1[k];
    }
}

void MergePass(vector<int>& R, int length) {
    int n = R.size();
    int i = 0;
    for (i; i + 2 * length - 1 < n; i += 2 * length) {
        Merge(R, i, i + length - 1, i + 2 * length - 1);
    }
    if (i + length < n) {
        Merge(R, i, i + length - 1, n - 1);
    }
}

void MergeSort(vector<int>& R, int n) {
    for (int length = 1; length < n; length *= 2) {
        MergePass(R, length);
        disp(R, 0, n - 1);
    }
}

int geti(int key, int r, int i) {
    int k = 0;
    for (int j = 0; j <= i; j++) {
        k = key % r;
        key = key / r;
    }
    return k;
}

void RadixSort(LinkList<int>& L, int d, int r) {
    LinkNode<int>* front[10];
    LinkNode<int>* rear[10];
    LinkNode<int>* p = NULL, * t = NULL;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < r; j++) {
            front[j] = rear[j] = NULL;
        }
        p = L.head->next;
        while (p != NULL) {
            int k = geti(p->data, r, i);
            if (front[k] == NULL) {
                front[k] = p;
                rear[k] = p;
            }
            else {
                rear[k]->next = p;
                rear[k] = p;
            }
            p = p->next;
        }
        LinkNode<int>* h = NULL;
        for (int j = 0; j < r; j++) {
            if (front[j] != NULL) {
                if (h == NULL) {
                    h = front[j];
                    t = rear[j];
                }
                else {
                    t->next = front[j];
                    t = rear[j];
                }
            }
        }
        t->next = NULL;
        L.head->next = h;
        disp2(L);
    }
}

int main()
{
    typedef void(*FunctionPointer)(vector<int>&, int);

    // 创建函数指针数组，每个元素指向一个不同的函数
    FunctionPointer functions[] = { InsertSort, ShellSort, BubbleSort, QuickSort, SelectSort, HeapSort, MergeSort };
    string SortName[] = { "InsertSort", "ShellSort", "BubbleSort", "QuickSort", "SelectSort", "HeapSort", "MergeSort" };
    for (int i = 0; i < 7; i++) {
        vector<int> a1 = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        int n = a1.size();
        cout << endl << SortName[i] << "排序前:" << endl;
        disp(a1, 0, n - 1);
        functions[i](a1, n);

        vector<int> a2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        n = a2.size();
        cout << endl << SortName[i] << "排序前:" << endl;
        disp(a2, 0, n - 1);
        functions[i](a2, n);

        vector<int> a3 = { 27, 53, 14, 68, 3, 91, 5, 72, 2, 0, 46 }; //测试随机序列
        n = a3.size();
        cout << endl << SortName[i] << "排序前:" << endl;
        disp(a3, 0, n - 1);
        functions[i](a3, n);
    }

    int l[] = { 27, 53, 14, 68, 3, 91, 5, 72, 2, 0, 46 };
    LinkList<int>  L;
    L.CreateListF(l, 11);

    printf("\nRadixSort排序前:\n"); disp2(L);
    RadixSort(L, 2, 10);

    return 0;
}




