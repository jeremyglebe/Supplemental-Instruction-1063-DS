#pragma once

// Define whether we are using Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define WINDOWS true
#endif

// Included libraries
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#if defined(WINDOWS)
// Libraries only used in Windows
#include <conio.h>
#else
// Libraries only used by non-Windows
#endif

class TermGame
{
public:
    /**
     * Gets a single character from stdin without need for a newline buffer.
     * (No need to press enter/return to finish input)
     * @return char  the character entered
     */
    static char getch();

    /**
     * Gets an arrow key, unbuffered, from stdin. Expects 2-3 characters
     * depending on the user's platform.
     * @return std::string  a string containing one of four values that
     * represent which arrow key was pressed. "ARROW_UP", "ARROW_DOWN",
     * "ARROW_LEFT", "ARROW_RIGHT"
     * @exception KeyPressError  exception is thrown any time a non-arrow key
     * is pressed in response to this function
     */
    static std::string getarrow();

    /**
     * Exception for incorrect key pressed in input functions from TermGame.
     */
    class KeyPressError : public std::exception
    {
        std::string what_message;

    public:
        KeyPressError();
        KeyPressError(std::string what_message);
        /**
         * Get the error message associated with the KeyPressError exception.
         */
        virtual const char *what() const throw();
    };
};

class TermPrint
{
public:
    /**
     * Prints a string to stdout.
     * @param msg the string that the user wants to print
     */
    static void print(std::string msg);
    /**
     * Prints a string to stdout.
     * @param msg the string that the user wants to print
     * @param forecolor the color of the text in the string
     */
    static void print(std::string msg, unsigned short forecolor);
    /**
     * Prints a string to stdout.
     * @param msg the string that the user wants to print
     * @param forecolor the color of the text in the string
     * @param backcolor the color behind the text in the string
     */
    static void print(std::string msg, unsigned short forecolor, unsigned short backcolor);
    /**
     * Fuses two multi-line string together for printing side-by-side
     * @param left the string that will be on the left half of the fused string
     * @param right the string that will be on the right half of the fused string
     */
    static std::string fuse(std::string left, std::string right);
    /**
     * Fuses two multi-line string together for printing side-by-side
     * @param left the string that will be on the left half of the fused string
     * @param right the string that will be on the right half of the fused string
     * @param pad bool, whether to pad each line of the string to be the same width
     */
    static std::string fuse(std::string left, std::string right, bool pad);
    /**
     * Split a string and store each new substring in a vector.
     * @param text the original string
     * @param delim the delimiting character to split by
     */
    static std::vector<std::string> splitstring(std::string text, char delim);
private:
#if defined(WINDOWS)
    // Windows fix bool.
    static bool _winFix;
#endif
#if defined(WINDOWS)
    // Color code definitions depending on platform
    static const unsigned short BLACK = 0;
    static const unsigned short BLUE = 1;
    static const unsigned short GREEN = 2;
    static const unsigned short CYAN = 3;
    static const unsigned short RED = 4;
    static const unsigned short MAGENTA = 5;
    static const unsigned short YELLOW = 6;
    static const unsigned short WHITE = 7;
    static const unsigned short RESET_COLOR = 7;
    static const unsigned short RESET_BACK_COLOR = 0;
#else
    static const unsigned short BLACK = 30;
    static const unsigned short RED = 31;
    static const unsigned short GREEN = 32;
    static const unsigned short YELLOW = 33;
    static const unsigned short BLUE = 34;
    static const unsigned short MAGENTA = 35;
    static const unsigned short CYAN = 36;
    static const unsigned short WHITE = 37;
    static const unsigned short RESET_COLOR = 39;
    static const unsigned short RESET_BACK_COLOR = 49;
#endif
};