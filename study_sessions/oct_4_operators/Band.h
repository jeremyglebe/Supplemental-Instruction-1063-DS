#include <iostream>
#include <string>
#include <vector>

class Band
{
public:
    // Default constructor, the band starts with no information
    Band();
    // Parameterized constructor, start the band off with a name and logo
    Band(std::string, char);
    void add_member(std::string);
    /** Prints each member of the band as well as their name and logo.
     * A "friend" is not technically a method of the class. Friends have
     * access to private data members, just like the class's methods. They are
     * made using the "friend" keyword.
     */
    friend std::ostream &operator<<(std::ostream &, Band);
    // Adds members from the passed in Band to the current Band
    Band operator+(Band);

private:
    // The band's full name
    std::string band_name;
    // A character used as the bands logo (it would be stylized on the
    // t-shirts, of course)
    char logo;
    // number of band members, somewhat redundant given that we can call
    // members.size()
    int num;
    // vector containing the names of band members
    std::vector<std::string> members;
};