#include "Queue.hpp"

template<typename T>
Queue<T>::Queue()
{
    rear = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    if (rear == nullptr) return;
    LinkNode<T>* curr = rear->next;
    while (curr != rear) {
        LinkNode<T>* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
    delete rear;
}

template<typename T>
bool Queue<T>::empty() const
{
    return rear == nullptr;
}

template<typename T>
bool Queue<T>::push(T e)
{
    LinkNode<T>* p = new LinkNode<T>(e);
    if (rear == nullptr) {
        rear = p;
        rear->next = p;
    }
    else {
        p->next = rear->next;
        rear->next = p;
        rear = p;
    }
    return true;
}

template<typename T>
bool Queue<T>::pop(T& e)
{
    if (rear == nullptr) {
        return false;
    }
    LinkNode<T>* head = rear->next;
    e = head->data;
    if (head == rear) {
        delete rear;
        rear = nullptr;
    }
    else {
        rear->next = head->next;
        delete head;
    }
    return true;
}

template<typename T>
bool Queue<T>::gethead(T& e)
{
    if (rear == nullptr) {
        return false;
    }
    e = rear->next->data;
    return true;
}

template<typename T>
bool Queue<T>::getbottom(T& e)
{
    if (rear == nullptr) {
        return false;
    }
    e = rear->data;
    return true;
}

template<typename T>
bool Queue<T>::display() const
{
    if (rear == nullptr) {
        return false;
    }
    LinkNode<T>* curr = rear->next;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != rear->next);
    cout << endl;
    return true;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other)
{
    if (other.empty()) return;
    LinkNode<T>* curr = other.rear->next;
    do {
        push(curr->data);
        curr = curr->next;
    } while (curr != other.rear->next);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if (this != &other) {
        this->~Queue();
        rear = nullptr;
        if (!other.empty()) {
            LinkNode<T>* curr = other.rear->next;
            do {
                push(curr->data);
                curr = curr->next;
            } while (curr != other.rear->next);
        }
    }
    return *this;
}
