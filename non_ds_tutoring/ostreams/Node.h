#pragma once

template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T);
    Node(T, Node<T> *);
};

#include "Node.cpp"