#pragma once
#include "Node.h"
#include <iostream>

template <class T>
class Stack
{
public:
    Stack();
    bool empty();
    T peek();
    T pop();
    void push(T);
    int size();
    void print();
    void print(std::ostream &);

private:
    Node<T> *_top;
    int _size;
};

#include "Stack.cpp"