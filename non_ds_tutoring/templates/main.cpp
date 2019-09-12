#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> num_stack;

    srand(42);
    std::cout << "size: " << num_stack.size() << '\n';
    for (int i = 0; i < 10; i++)
    {
        num_stack.push(rand() % 100 + 1);
        std::cout << "size: " << num_stack.size() << '\n';
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << "pop! " << num_stack.pop() << '\n';
        std::cout << "size: " << num_stack.size() << '\n';
    }
}