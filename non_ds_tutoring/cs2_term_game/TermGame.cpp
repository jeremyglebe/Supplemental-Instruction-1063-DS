#include "TermGame.h"

/**
 * Gets a single character from stdin without need for a newline buffer.
 * (No need to press enter/return to finish input)
 * @return char  the character entered
 */
char TermGame::getch()
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

/**
 * Gets an arrow key, unbuffered, from stdin. Expects 2-3 characters
 * depending on the user's platform.
 * @return std::string  a string containing one of four values that
 * represent which arrow key was pressed. "ARROW_UP", "ARROW_DOWN",
 * "ARROW_LEFT", "ARROW_RIGHT"
 * @exception std::runtime_error  exception is thrown any time a non-arrow
 * key is pressed in response to this function
 */
std::string TermGame::getarrow()
{
    char key;
#if defined(WINDOWS)
    // On windows, arrow keys start with a char, value 0
    if (getch() == 0)
    {
        // The follow-up character determines which arrow key was pressed
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
    // *nix systems work like the Windows version above, only arrow keys here
    // start with 2 characters, values 27 and 91, followed by a character to
    // distinguish between arrows.
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
    // If a proper arrow key isn't pressed, throw an exception
    std::string error_msg = "Non-arrow key pressed in response to TermGame::g";
    error_msg += "etarrow()";
    throw KeyPressError(error_msg);
}

TermGame::KeyPressError::KeyPressError()
{
    what_message = "Invalid key pressed!";
}
TermGame::KeyPressError::KeyPressError(std::string what_message)
{
    this->what_message = what_message;
}
/**
 * Get the error message associated with the KeyPressError exception.
 */
const char *TermGame::KeyPressError::what() const throw()
{
    return what_message.c_str();
}