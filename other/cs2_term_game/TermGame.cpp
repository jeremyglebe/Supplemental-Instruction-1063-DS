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
    std::string error_msg = "KeyPressError: Non-arrow key pressed in response ";
    error_msg += "to TermGame::getarrow()";
    throw KeyPressError(error_msg);
}

TermGame::KeyPressError::KeyPressError()
{
    what_message = "KeyPressError: Invalid key pressed!";
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

/**
     * Prints a string to stdout.
     * @param msg the string that the user wants to print
     */
void TermPrint::print(std::string msg){
    print(msg, RESET_COLOR, RESET_BACK_COLOR);
}
/**
     * Prints a string to stdout.
     * @param msg the string that the user wants to print
     * @param forecolor the color of the text in the string
     */
void TermPrint::print(std::string msg, unsigned short forecolor){
    print(msg, forecolor, RESET_BACK_COLOR);
}
/**
 * Prints a string to stdout.
 * @param msg the string that the user wants to print
 * @param forecolor the color of the text in the string
 * @param backcolor the color behind the text in the string
 */
static void print(std::string msg, unsigned short forecolor, unsigned short backcolor){

}
/**
 * Fuses two multi-line string together for printing side-by-side
 * @param left the string that will be on the left half of the fused string
 * @param right the string that will be on the right half of the fused string
 * @return a std::string, with both original strings side-by-side
 */
std::string TermPrint::fuse(std::string left, std::string right)
{
    return fuse(left, right, false);
}
/**
 * Fuses two multi-line string together for printing side-by-side
 * @param left the string that will be on the left half of the fused string
 * @param right the string that will be on the right half of the fused string
 * @param pad bool, whether to pad each line of the string to be the same width
 * @return a std::string, with both original strings side-by-side
 */
std::string TermPrint::fuse(std::string left, std::string right, bool pad)
{
    std::string result = "";
    // split the strings, create vectors
    std::vector<std::string> lv = TermPrint::splitstring(left, '\n');
    std::vector<std::string> rv = TermPrint::splitstring(right, '\n');
    // correct the number of lines in the strings so they match
    if (lv.size() > rv.size())
    {
        int diff = lv.size() - rv.size();
        for (int i = 0; i < diff; i++)
        {
            rv.push_back("");
        }
    }
    else if (lv.size() < rv.size())
    {

        int diff = rv.size() - lv.size();
        for (int i = 0; i < diff; i++)
        {
            lv.push_back("");
        }
    }
    if (pad)
    {
        // find the largest line out of any of the vectors
        int max = 0;
        for (int i = 0; i < lv.size(); i++)
        {
            if (lv[i].size() > max)
                max = lv[i].size();
            if (rv[i].size() > max)
                max = rv[i].size();
        }
        // for each line in both vectors, pad the line for max size
        for (int i = 0; i < lv.size(); i++)
        {
            if (lv[i].size() < max)
            {
                int diff = max - lv[i].size();
                lv[i] += std::string(diff, ' ');
            }
            if (rv[i].size() < max)
            {
                int diff = max - rv[i].size();
                rv[i] += std::string(diff, ' ');
            }
        }
    }
    // loop through the vectors and produce the new string
    for (int i = 0; i < lv.size(); i++)
    {
        result += lv[i] + rv[i] + '\n';
    }
    return result;
}
/**
 * Split a string and store each new substring in a vector.
 * @param text the original string
 * @param delim the delimiting character to split by
 */
std::vector<std::string> TermPrint::splitstring(std::string text, char delim)
{
    std::vector<std::string> strings;
    while (text.size() > 0)
    {
        int i = 0;
        while (text[i] != delim && i < text.size())
            i++;
        strings.push_back(text.substr(0, i));
        text.erase(0, i + 1);
    }
    return strings;
}