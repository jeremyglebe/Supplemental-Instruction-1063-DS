#include <iostream>
#include <string>
#include "TermGame.h"
using namespace std;

int main()
{
    cout << "Press any key:\n";
    cout << TermGame::getch() << endl;
    cout << "Press 4 Arrow Keys:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << TermGame::getarrow() << endl;
    }
}