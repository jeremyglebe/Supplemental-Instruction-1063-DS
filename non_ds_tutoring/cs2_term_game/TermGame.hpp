// Define whether we are using Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define WINDOWS true
#endif

// Included libraries
#include <string>
#if defined(WINDOWS)
// Libraries only used in Windows
#include <conio.h>
#else
// Libraries only used by non-Windows
#include <iostream>
#endif

namespace TermGame
{

char getch()
{
#if defined(WINDOWS)
    // just use conio's getch
    return _getch();
#else
    char key;
    // turn off echo and get the input without a buffer
    system("stty -brkint -ignpar -istrip -icrnl -ixon -opost -isig -icanon -echo");
    // get the next stdin character
    //key = getchar();
    std::cin >> key;
    // set the terminal back to buffered input and echo
    system("stty cooked echo");
    return key;
#endif
}

std::string getarrow()
{
    char key;
#if defined(WINDOWS)
    if (getch() == 0)
    {
        key = getch();
        if (key == 77)
            return "ARROW_RIGHT";
        else if (key == 72)
        {
            return "ARROW_UP";
        }
        else if (key == 75)
        {
            return "ARROW_LEFT";
        }
        else if (key == 80)
        {
            return "ARROW_DOWN";
        }
    }
#else
    if (getch() == 27)
    {
        if (getch() == 91)
        {
            key = getch();
            if (key == 67)
                return "ARROW_RIGHT";
            else if (key == 65)
            {
                return "ARROW_UP";
            }
            else if (key == 68)
            {
                return "ARROW_LEFT";
            }
            else if (key == 66)
            {
                return "ARROW_DOWN";
            }
        }
    }
#endif
    return "NONE";
}

} // namespace TermGame