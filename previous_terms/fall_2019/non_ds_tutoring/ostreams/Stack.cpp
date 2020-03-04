#include "Stack.h"
#include <iomanip>

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
bool Stack<T>::empty()
{
    if (!_top)
        return true;
    return false;
}

template <class T>
T Stack<T>::pop()
{
    T top_obj = _top->data;
    Node<T> *to_delete = _top;
    _top = _top->next;
    delete to_delete;
    _size--;
    return top_obj;
}

template <class T>
T Stack<T>::peek()
{
    return _top->data;
}

template <class T>
int Stack<T>::size()
{
    return _size;
}

template <class T>
void Stack<T>::print()
{
    print(std::cout);
}

template <class T>
void Stack<T>::print(std::ostream &out)
{
    Node<T> *temp = _top;
    out << "**********\n";
    while (temp != NULL)
    {
        out << std::left << '*' << std::setw(8) << temp->data
            << "*\n**********\n";
        temp = temp->next;
    }
    out << '\n';
}