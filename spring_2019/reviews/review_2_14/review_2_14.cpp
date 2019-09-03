#include <iostream>
#include "Student.h"
using namespace std;

void header();

int main() {
    header();

    Student john("M11111111", "John", "Doe", 4.0);
    cout << john.fname << john.lname << endl;

    Student sally("M11111111", "Sally", "May", 4.0);
    cout << sally.fname << sally.lname << endl;

    sally.marry(john);
    cout << sally.fname << sally.lname << endl;

}

void header(){
    cout << "\033[31;47m"
        << "╔══════════════════════════════════════╗\n"
        << "║   Topics To Cover (Review 2/14/19)   ║\n"
        << "╚══════════════════════════════════════╝\n"
        << "\033[0;32m"
        << "\t- Classes\n"
        << "\t- Usage\n"
        << "\t- Access\n"
        << "\t- Domain/Constraints\n"
        << "\t- Destructors\n"
        << "\t- Definition & Implementation\n\n"
        << "Join this session: "
        << "https://repl.it/live/jqnVcQ1m5nqR4A\n";
    return;
}
