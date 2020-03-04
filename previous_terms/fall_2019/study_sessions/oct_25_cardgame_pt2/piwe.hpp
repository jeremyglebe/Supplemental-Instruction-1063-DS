// Portable Input Without Enter: P.I.W.E.
// I wrote this, you don't have to know how it works.
// Just use piwe::getkey() to get the next key the user presses.

// Define whether we are using Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <conio.h>
const bool WINDOWS = true;
#else
#include <stdio.h>
const bool WINDOWS = false;
int getch();
#endif

#include <iostream>

namespace piwe
{

char getkey()
{
    if (WINDOWS)
    {
        return getch();
    }
    else
    {
        char key;
        system("stty raw -echo");
        key = getchar();
        system("stty cooked echo");
        return key;
    }
}

} // namespace piwe