//
// Created by Rylie  Seaberg  on 10/28/24.
//

#include "stack.h"
#include <iostream>
#include <stdexcept>
using namespace std;


template <typename T>
Stack<T>::Stack() {
    head = nullptr;
    tail = nullptr;
    count=0;
}


template <typename T>
Stack<T>::~Stack() {
    clear();
}


template <typename T>
Stack<T>::Stack(const Stack<T>& other) : head(nullptr), tail(nullptr), count(0) {
    Node* current = other.head;
    while (current) {
        push(current->data);
        current = current->next;
    }
}


template <typename T>
bool Stack<T>::empty() const {
    return count == 0;
}


template <typename T>
void Stack<T>::clear() {
    while (!empty()) {
        pop();
    }
}


template <typename T>
void Stack<T>::push(const T& x) {
    Node* newNode = new Node(x);
    if (empty()) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    ++count;
}

template <typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw runtime_error ("Stack is empty");
    }
    Node* toDelete = tail;
    if (tail->prev) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        head = tail = nullptr;
    }
    delete toDelete;
    --count;
}

template <typename T>
T& Stack<T>::top() {
    if (empty()) {
        throw runtime_error ("Stack is empty");
    }
    return tail->data;
}


template <typename T>
const T& Stack<T>::top() const {
    if (empty()) {
        throw runtime_error ("Stack is empty");
    }
    return tail->data;
}


template <typename T>
int Stack<T>::size() const {
    return count;
}


template <typename T>
void Stack<T>::print(ostream& os, char ofc) const {
    Node* current = head;
    while (current) {
        os << current->data;
        if (current->next) {
            os << ofc;
        }
        current = current->next;
    }
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& a) {
    a.print(os);
    return os;
}


template <typename T>
bool operator==(const Stack<T>& a, const Stack<T>& b) {
    if (a.size() != b.size()) return false;

    Stack<T> copyA = a;
    Stack<T> copyB = b;

    while (!copyA.empty() && !copyB.empty()) {
        if (copyA.top() != copyB.top()) {
            return false;
        }
        copyA.pop();
        copyB.pop();
    }
    return true;
}


template <typename T>
bool operator!=(const Stack<T>& a, const Stack<T>& b) {
    return !(a == b);
}


template <typename T>
bool operator<=(const Stack<T>& a, const Stack<T>& b) {
    if (a.size() > b.size()) return false;

    Stack<T> copyA = a;
    Stack<T> copyB = b;

    while (!copyA.empty()) {
        if (copyA.top() > copyB.top()) {
            return false;
        }
        copyA.pop();
        copyB.pop();
    }
    return true;
}
