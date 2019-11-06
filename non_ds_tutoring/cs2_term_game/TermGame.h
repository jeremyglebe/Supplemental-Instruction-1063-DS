#pragma once

// Define whether we are using Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define WINDOWS true
#endif

// Included libraries
#include <stdexcept>
#include <string>
#if defined(WINDOWS)
// Libraries only used in Windows
#include <conio.h>
#else
// Libraries only used by non-Windows
#include <iostream>
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
