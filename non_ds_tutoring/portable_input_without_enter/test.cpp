#include <iostream>
#include <string>
#include "piwe.hpp"

int main()
{
    char in = ' ';
    while (in != 'q')
    {
        in = piwe::getkey();
        std::cout << "You pressed: " << in << " (" << int(in) << ')' << std::endl;
    }
    std::string e;
    std::cout << "Standard input test! Enter \"Goodbye\" to exit...\t";
    std::cin >> e;
    while(e != "Goodbye"){
        std::cin >> e;
    }
}