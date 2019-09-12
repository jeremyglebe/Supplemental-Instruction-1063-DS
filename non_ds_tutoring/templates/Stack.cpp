#include "Stack.h"

template <class T>
Stack<T>::Stack()
{
    _top = NULL;
    _size = 0;
}

template <class T>
void Stack<T>::push(T obj)
{
    _top = new Node<T>(obj, _top);
    _size++;
}

template <class T>
T Stack<T>::pop()
{
    T top_obj = _top->data;
    Node<T>* to_delete = _top;
    _top = _top->next;
    delete to_delete;
    _size--;
    return top_obj;
}

template <class T>
int Stack<T>::size()
{
    return _size;
}