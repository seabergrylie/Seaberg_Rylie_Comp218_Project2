//
// Created by Rylie  Seaberg  on 10/28/24.
//

#include <iostream>
#include "doublylinkedlist.h"
#include <stdexcept>
using namespace std;




template <typename T>
doublylinkedlist<T>::doublylinkedlist() {
    head = nullptr;
    tail = nullptr;
}

template <typename T>
doublylinkedlist<T>::~doublylinkedlist() {
    DLLNode<T>* temp;
    DLLNode<T>* current = this->head;

    while (current != nullptr) {
        temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

template <typename T>
doublylinkedlist<T>::doublylinkedlist(const doublylinkedlist& toCopy) {
    head = nullptr;
    DLLNode<T>* current = toCopy.head;
    DLLNode<T>* lastNode = nullptr;

    while (current != nullptr) {
        DLLNode<T>* newNode = new DLLNode<T>(current->data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            lastNode->next = newNode;
            newNode->prev = lastNode;
        }
        lastNode = newNode;
        current = current->next;
    }
}

template <typename T>
int doublylinkedlist<T>::size() const {
    DLLNode<T>* current = this->head;
    int size = 0;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}

template <typename T>
void doublylinkedlist<T>::display() {
    DLLNode<T>* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
void doublylinkedlist<T>::displayBackwards() {
    DLLNode<T>* current = tail;
    while (current) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

template <typename T>
void doublylinkedlist<T>::insert(T val) {
    DLLNode<T>* newNode = new DLLNode<T>(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        DLLNode<T>* curr = head;
        while (curr != nullptr) {
            if (newNode->data < curr->data) {
                newNode->next = curr;
                newNode->prev = curr->prev;
                if (curr->prev) {
                    curr->prev->next = newNode;
                } else {
                    head = newNode;
                }
                curr->prev = newNode;
                return;
            }
            curr = curr->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <typename T>
void doublylinkedlist<T>::insertAtHead(T value) {
    DLLNode<T>* newNode = new DLLNode<T>(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void doublylinkedlist<T>::insertAtTail(T value) {
    DLLNode<T>* newNode = new DLLNode<T>(value);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <typename T>
bool doublylinkedlist<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
T doublylinkedlist<T>::peekHead() const {
    if (this->head != nullptr) {
        return this->head->data;
    }
    throw runtime_error("DLL is empty");
}

template <typename T>
T doublylinkedlist<T>::peekTail() const {
    if (this->tail != nullptr) {
        return this->tail->data;
    }
    throw runtime_error("DLL is empty");
}

template <typename T>
T doublylinkedlist<T>::remove(T val) {
    DLLNode<T>* current = head;

    while (current != nullptr) {
        if (current->data == val) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            T removedValue = current->data;
            delete current;
            return removedValue;
        }
        current = current->next;
    }
    throw runtime_error("Value not in the list");
}

template <typename T>
T doublylinkedlist<T>::removeHead() {
    if (isEmpty()) {
        throw runtime_error("List is empty");
    }
    T val = head->data;
    DLLNode<T>* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    return val;
}

template <typename T>
T doublylinkedlist<T>::removeTail() {
    if (isEmpty()) {
        throw runtime_error("List is empty");
    }
    T val = tail->data;
    DLLNode<T>* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    return val;
}
