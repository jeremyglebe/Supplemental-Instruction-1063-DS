#include <iostream>
#include <string>
#include "TermGame.h"
using namespace std;

int main()
{
    // test getting a single character from stdin
    cout << "Press any key:\n";
    cout << TermGame::getch() << endl;
    // test getting arrow keys
    cout << "Press 4 Arrow Keys:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << TermGame::getarrow() << endl;
    }
    // test splitting strings
    std::string mystring = "Hello+World+Please+Say+Hi";
    std::vector<std::string> myvec;
    myvec = TermPrint::splitstring(mystring, '+');
    cout << myvec[0];
    for (int i = 1; i < myvec.size(); i++)
    {
        cout << ", " << myvec[i];
    }
    // test fusing strings
    std::string car = "\n";
    car += "     .--.\n";
    car += ".----'   '--.\n";
    car += "'-()-----()-'\n";
    std::string atm = "";
    atm += " ___\n";
    atm += "[ATM]\n";
    atm += "  |\n";
    atm += "  |\n";
    cout << '\n'
         << TermPrint::fuse(car, atm);
    cout << '\n'
         << TermPrint::fuse(car, atm, false);
    cout << '\n'
         << TermPrint::fuse(car, atm, true);
}