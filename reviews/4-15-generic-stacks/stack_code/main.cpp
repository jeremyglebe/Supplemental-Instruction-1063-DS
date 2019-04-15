#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;
int main()
{
    Stack<int> intStack(5);
    for (int i = 0; i < 5; i++)
    {
        intStack.push(i);
    }
    intStack.push(999);
    for (int i = 0; i < 6; i++)
    {
        cout << intStack.pop() << ' ';
    }

    Stack<string> strStack(5);
    for (int i = 0; i < 5; i++)
    {
        strStack.push(string(i * 2 + 1, '*'));
    }
    strStack.push("X");
    for (int i = 0; i < 6; i++)
    {
        cout << strStack.pop() << ' ';
    }
}