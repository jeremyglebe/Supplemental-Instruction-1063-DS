#include <iostream>
#include <string>
#include <vector>
using namespace std;

void header();
int square(int);
void counter();
void scramble(string&);

double MYGLOBAL = 3.14;

int main() {
  header();

  int var_from_main = square(5);
  //Can't access result from main
  //cout << result << endl;
  //Can access variable declared in main
  cout << var_from_main << '\n';
  cout << "GLOBAL VAR (IN MAIN) IS " << MYGLOBAL << '\n';

  for(int i = 0; i < 15; i++){
      counter();
  }

  //Can't access counter's variable
  //cout << current_count << endl;

  //Passing by reference
  string myName = "Jeremy";
  scramble(myName);
  cout << myName << endl;


  //Lets make an array of names
  //These are the names of cool people
  string names[5] = {"Jeremy", "Garrett", "Chad", "Dr. Griffin", "Dr. Colmenares"};
  //OH NO! WE FORGOT SOMEONE. BETTER ADD THEM TO THE LIST
  //names[5] = "Mr. E"; Wait, this shouldn't work.
  //Lets try Vectors
  vector<string> better_names;
  better_names.push_back("Glebe");
  better_names.push_back("Johnson");
  cout <<better_names[0] << '\n';
  //cout << better_names[2]; bad
  better_names.push_back("Eduardo");
  cout << better_names[2] << '\n';
  for(int i = 0; i < better_names.size(); i++){
      cout << "THIS GUY IS AWESOME: " << better_names[i] << endl;
  }


  return 0;
}

void scramble(string& word){
    string scrambled = "";
    for(int i = 0; scrambled.length() < word.length(); i = (i + 5) % word.length()){
        scrambled += word[i];
    }
    word = scrambled;
}

void counter(){
    static int current_count = 0;
    cout << "COUNT IS: " << ++current_count << '\n';
}

int square(int x){
    int result = x * x;
    cout << "\nGLOBAL VAR (IN SQUARE) IS " << MYGLOBAL << '\n';
    MYGLOBAL = result + .0217;
    cout << "CHANGED GLOBAL VAR (IN SQUARE): " << MYGLOBAL << '\n';
    return result;
}

void header(){
    cout << "\033[31;47m"
        << "╔══════════════════════════════════════╗\n"
        << "║   Topics To Cover (Review 1/29/19)   ║\n"
        << "╚══════════════════════════════════════╝\n"
        << "\033[0;32m"
        << "\t- Local/Global\n"
        << "\t- Static\n"
        << "\t- References\n"
        << "\t- Arrays\n"
        << "\t- Vectors\n\n"
        << "Join this session: "
        << "https://repl.it/live/3uOeinoXALkomA";
}
