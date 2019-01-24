#include <iostream>
#include <string>
using namespace std;

void print_header();
int mult10(int);
string redText(string);
void counter();

int main() {
    print_header();
    mult10(6);
    cout << '\n' << 9 + mult10(5) << endl;
    cout << redText("Some red text") << endl;

    for (int i = 0; i < 10; i++){
        counter();
    }

}

void print_header(){
    string shadow = "Other string";

    cout << "\033[31;47m"
        << "╔══════════════════════════════════════╗\n"
        << "║   Topics To Cover (Review 1/22/19)   ║\n"
        << "╚══════════════════════════════════════╝\n"
        << "\033[0;32m"
        << "\t- Functions (usage, returns)\n"
        << "\t- Headers/Prototypes\n"
        << "\t- Promotion/Demotion\n"
        << "\t- Scoping & Shadowing\n"
        << "\t- Static Variables\n\n"
        << "Join this session: "
        << "https://repl.it/live/lKdx7K1B-C_nXg\n";
}

int mult10(int num){
    int answer = num * 10;
    return answer;
    //return 'x';
}

string redText(string myMessage){
    return "\033[31m" + myMessage + "\033[0m";
}

void counter(){
    static int myCount = 1;
    cout << myCount++ << endl;
}

/* References
    Colored Text in Linux:
        https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
*/