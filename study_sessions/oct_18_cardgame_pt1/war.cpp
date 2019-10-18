#include <fcntl.h>
#include <iostream>
#include <string>
#include "Card.h"

int getValue(Card);

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    Card card('d', 'K');
    std::wcout << card << '\n';
    Card card2('s', 'A');
    std::wcout << card2 << '\n';
}