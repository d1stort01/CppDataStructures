#include "PolyList.hpp"
#include <cstdio>
#include <math.h>

void PolyList::CreateList(const char* filename)
{
    FILE* stream1;
    freopen_s(&stream1, filename, "r", stdin);
    PolyNode* s, * r;
    double c;
    int n, e;
    scanf_s("%d", &n);
    r = head;
    for (int i = 0; i < n; i++)
    {
        scanf_s("%lf%d", &c, &e);
        s = new PolyNode(c, e);
        r->next = s;
        r = s;
    }
    r->next = nullptr;
}

void PolyList::DispPoly() const
{
    bool first = true;
    PolyNode* p = head->next;
    while (p != nullptr)
    {
        if (first) {
            printf("[%.1lf,%d]", p->coef, p->exp);
            first = false;
        }
        else {
            printf(",[%.1lf,%d]", p->coef, p->exp);
        }
        p = p->next;
    }
    printf("\n");
}

void PolyList::Sort()
{
    PolyNode* p, * pre, * q;
    q = head->next;
    if (q == nullptr) {
        return;
    }
    p = head->next->next;
    if (p == nullptr) {
        return;
    }
    q->next = nullptr;
    while (p != nullptr) {
        q = p->next;
        pre = head;
        while (pre->next != nullptr && pre->next->exp > p->exp) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

void PolyList::insertOrder(PolyNode* p)
{
    PolyNode* pre = head;
    while (pre->next != nullptr && pre->next->exp > p->exp) {
        pre = pre->next;
    }
    if (pre->next != nullptr && pre->next->exp == p->exp) {
        pre->next->coef += p->coef;
        delete p;
    }
    else {
        p->next = pre->next;
        pre->next = p;
    }
}

double PolyList::value(double xValue)
{
    double result = 0.0;
    PolyNode* p = head->next;
    while (p != nullptr) {
        result += p->coef * pow(xValue, p->exp);
        p = p->next;
    }
    return result;
}

void PolyAdd(const PolyList& A, const PolyList& B, PolyList& C)
{
    PolyNode* pa = A.head->next;
    PolyNode* pb = B.head->next;
    PolyNode* s, * r;
    double c;
    r = C.head;
    while (pa != nullptr && pb != nullptr) {
        if (pa->exp > pb->exp) {
            s = new PolyNode(pa->coef, pa->exp);
            r->next = s;
            r = s;
            pa = pa->next;
        }
        else if (pa->exp < pb->exp) {
            s = new PolyNode(pb->coef, pb->exp);
            r->next = s;
            r = s;
            pb = pb->next;
        }
        else {
            c = pa->coef + pb->coef;
            if (c != 0) {
                s = new PolyNode(c, pa->exp);
                r->next = s;
                r = s;
            }
            pa = pa->next;
            pb = pb->next;
        }
    }
    if (pb != nullptr) {
        pa = pb;
    }
    while (pa != nullptr) {
        s = new PolyNode(pa->coef, pa->exp);
        r->next = s;
        r = s;
        pa = pa->next;
    }
    r->next = nullptr;
}

void PolySubstract(const PolyList& A, const PolyList& B, PolyList& C)
{
    PolyNode* pa = A.head->next;
    PolyNode* pb = B.head->next;
    PolyNode* s, * r;
    double c;
    r = C.head;
    while (pa != nullptr && pb != nullptr) {
        if (pa->exp > pb->exp) {
            s = new PolyNode(pa->coef, pa->exp);
            r->next = s;
            r = s;
            pa = pa->next;
        }
        else if (pa->exp < pb->exp) {
            s = new PolyNode(-pb->coef, pb->exp);
            r->next = s;
            r = s;
            pb = pb->next;
        }
        else {
            c = pa->coef - pb->coef;
            if (c != 0) {
                s = new PolyNode(c, pa->exp);
                r->next = s;
                r = s;
            }
            pa = pa->next;
            pb = pb->next;
        }
    }
    int k = 1;
    if (pb != nullptr) {
        pa = pb;
        k = -1;
    }
    while (pa != nullptr) {
        s = new PolyNode(k * pa->coef, pa->exp);
        r->next = s;
        r = s;
        pa = pa->next;
    }
    r->next = nullptr;
}

void PolyMultiply(const PolyList& A, const PolyList& B, PolyList& C)
{
    if (A.head->next == nullptr || B.head->next == nullptr) {
        return;
    }
    for (PolyNode* pa = A.head->next; pa != nullptr; pa = pa->next) {
        for (PolyNode* pb = B.head->next; pb != nullptr; pb = pb->next) {
            PolyNode* s = new PolyNode(pa->coef * pb->coef, pa->exp + pb->exp);
            C.insertOrder(s);
        }
    }
}

