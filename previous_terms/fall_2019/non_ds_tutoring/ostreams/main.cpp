#include <iostream>
#include <fstream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> nums;
    srand(42);
    for (int i = 0; i < 10; i++)
    {
        nums.push(rand() % 100);
    }
    nums.print();

    ofstream outfile;
    outfile.open("output.txt");
    nums.print(outfile);
    outfile.close();
}