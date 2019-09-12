#pragma once
#include "Node.h"

template <class T>
class Stack
{
public:
    Stack();
    T pop();
    void push(T);
    int size();

private:
    Node<T> *_top;
    int _size;
};

#include "Stack.cpp"