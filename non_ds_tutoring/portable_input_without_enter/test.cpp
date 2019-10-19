#include <iostream>
#include "piwe.hpp"

int main()
{
    char in = ' ';
    while (in != 'q')
    {
        in = piwe::getkey();
        std::cout << "You pressed: " << in << " (" << int(in) << ')' << std::endl;
    }
}