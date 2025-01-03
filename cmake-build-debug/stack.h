//
// Created by Rylie  Seaberg  on 10/28/24.
//

#ifndef SEABERG_RYLIE_COMP218_PROJECT2_STACK_H
#define SEABERG_RYLIE_COMP218_PROJECT2_STACK_H

#include <iostream>

#ifndef STACK_H
#define STACK_H
using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    Stack(); // Zero-argument constructor
    ~Stack(); // Destructor
    Stack(const Stack<T>& other); // Copy constructor
    Stack<T>& operator=(const Stack<T>& other); // Copy assignment operator

    bool empty() const; // Returns true if the Stack contains no elements
    void clear(); // Deletes all elements from the stack
    void push(const T& x); // Adds x to the Stack
    void pop(); // Removes the most recently added element
    T& top(); // Returns a reference to the most recently added element
    const T& top() const; // Accessor for the most recently added element
    int size() const; // Returns the number of elements stored in the Stack
    void print(ostream& os, char ofc = ' ') const; // Prints elements of Stack
};


// Non-member functions
template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& a); // Print stack

template <typename T>
bool operator==(const Stack<T>& a, const Stack<T>& b); // Equality operator
template <typename T>
bool operator!=(const Stack<T>& a, const Stack<T>& b); // Inequality operator
template <typename T>
bool operator<=(const Stack<T>& a, const Stack<T>& b); // Less than or equal operator

#include "Stack.cpp"

#endif // STACK_H



#endif //SEABERG_RYLIE_COMP218_PROJECT2_STACK_H
