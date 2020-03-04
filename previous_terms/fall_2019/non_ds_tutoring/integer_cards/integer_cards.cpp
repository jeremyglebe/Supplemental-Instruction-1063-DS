#include <iostream>
using namespace std;

int main()
{

    for (int i = 0; i < 52; i++)
    {
        cout << i << ' ' << i % 13 << ' ' << i / 13 << '\n';
        cout << "id: " << i << ' ';
        switch (i / 13)
        {
        case 0:
            cout << "suit: diamonds" << ' ';
            break;
        case 1:
            cout << "suit: hearts" << ' ';
            break;
        case 2:
            cout << "suit: clubs" << ' ';
            break;
        case 3:
        default:
            cout << "suit: spades" << ' ';
        }
        if (i % 13 <= 9)
        {
            cout << i % 13 + 1 << endl;
        }
        else if (i % 13 == 10)
        {
            cout << "J" << endl;
        }
        else if (i % 13 == 11)
        {
            cout << "Q" << endl;
        }
        else if (i % 13 == 12)
        {
            cout << "K" << endl;
        }
    }
}