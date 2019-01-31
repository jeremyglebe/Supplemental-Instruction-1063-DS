#include <iostream>
#include <string>
using namespace std;

void header();
void other_function();
void counter();
void counter(int change);
void counter(string counter_name);
//global scope
int x = 150;

int main() {
    header();
    //local variable is used instead
    int x = 5;
    cout << "X in main is " << x << '\n';
    //Even more localized
    for(int x = 0; x < 4; x++){
        cout << "X in for loop is " << x << '\n';
    }
    other_function();
    for(int i = 0; i < 3; i++){
        counter();
    }
    for(int i = 0; i < 3; i++){
        counter(6);
    }
    for(int i = 0; i < 3; i++){
        counter("my counter");
    }
    string students[] = {"John Doe", "Jane Doe", "Bob Gray", "Frank Johnson"};
    cout << "List of students: ";
    for (int i = 0; i < 4; i++){
        cout << "\n\t" << students[i];
    }
}

void header(){
    cout << "\033[31;47m"
        << "╔══════════════════════════════════════╗\n"
        << "║   Topics To Cover (Review 1/24/19)   ║\n"
        << "╚══════════════════════════════════════╝\n"
        << "\033[0;32m"
        << "\t- Scoping\n"
        << "\t- Static Variables\n"
        << "\t- Overloading (Functions w/ same name)\n"
        << "\t- Array Usage\n"
        << "\t- Increment/Decrement\n\n"
        << "Join this session: "
        << "https://repl.it/live/cg-1IgFOD_Gp4A\n\n";
}

void other_function(){
    cout << "X in other_function is " << x << '\n';
}

void counter(){
    static int number = 0;
    cout << "Negative Counter: " << --number << '\n';
}

void counter(int change){
    static int number = 0;
    number += change;
    cout << "Variable Counter: " << number << '\n';
}

void counter(string counter_name){
    static int number = 0;
    cout << counter_name << ": " << ++number << '\n';
}