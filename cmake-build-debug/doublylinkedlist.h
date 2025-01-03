//
// Created by Rylie  Seaberg  on 10/28/24.
//

#ifndef SEABERG_RYLIE_COMP218_PROJECT2_DOUBLYLINKEDLIST_H
#define SEABERG_RYLIE_COMP218_PROJECT2_DOUBLYLINKEDLIST_H


template <typename T>
class DLLNode {
public:
    T data;
    DLLNode* next;
    DLLNode* prev;

    DLLNode(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class doublylinkedlist {

    protected:
    doublylinkedlist(const doublylinkedlist &toCopy);

    DLLNode<T>* head;
    DLLNode<T>* tail;

    public:
        doublylinkedlist();
        doublylinkedlist(doublylinkedlist& toCopy);
        ~doublylinkedlist();
        int size() const;
        bool isEmpty() const;
        T peekHead() const;
        T peekTail() const;
        void insert(T val);
        void insertAtHead(T val);
        void insertAtTail(T val);
        T remove(T val);
        T removeHead();
        T removeTail();
        void display();
        void displayBackwards();
};



#endif //SEABERG_RYLIE_COMP218_PROJECT2_DOUBLYLINKEDLIST_H
