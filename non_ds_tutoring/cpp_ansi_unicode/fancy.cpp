// Define whether we are using Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <fcntl.h>
const bool WINDOWS = true;
#else
const bool WINDOWS = false;
#endif

#include <iostream>
#include <string>
// used for portable sleep function
#include <chrono>
#include <thread>
using namespace std;

void sleep(int ms);

int main()
{
    // if windows, change the console mode to support unicode and stuff
    if (WINDOWS)
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
    }
    sleep(2000);
    wcout << L"\033[0m♠♣\033[31m♥♦\033[0m\n";
}

void sleep(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}