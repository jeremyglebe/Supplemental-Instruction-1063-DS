// Define whether we are using Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define WINDOWS true
#include <conio.h>
#endif

// Included libraries
#include <iostream>
#if defined(WINDOWS)
#include <conio.h>
#else
#include <stdio.h>
#endif

namespace piwe
{

char getkey()
{
#if defined(WINDOWS)
    return getch();
#else
    char key;
    system("stty -brkint -ignpar -istrip -icrnl -ixon -opost -isig -icanon -echo");
    key = getchar();
    system("stty cooked echo");
    return key;
#endif
}

} // namespace piwe