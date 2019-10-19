// Define whether we are using Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <conio.h>
const bool WINDOWS = true;
#else
#include <stdio.h>
const bool WINDOWS = false;
#endif

#include <iostream>

namespace piwe
{

char getkey()
{
    static bool unix_raw = false;
    if (WINDOWS)
    {
        return getch();
    }
    else if (unix_raw)
    {
        return getchar();
    }
    else
    {
        system("stty cooked");
        unix_raw = true;
        return getchar();
    }
}

} // namespace piwe