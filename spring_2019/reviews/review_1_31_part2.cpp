#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    //Arrays
    string students[2];
    students[0] = "Bob";
    students[1] = "Joe";
    //Can't do this
    //students[2] = "John";

    //Vectors
    vector<string> s;
    s.push_back("John");
    s.push_back("XXXXXXXXX");
    s.push_back("Jesse");
    s.push_back("Corey");
    s.push_back("Jeremy");
    s.push_back("Glebe");

    //array traversal
    for(int i = 0; i < 3; i++){
        cout << students[i] << endl;
    }

    //vector traversal
    for(int i = 0; i < s.size(); i++){
        cout << s[i] << endl;
    }

    //3D Arrays and random
    srand(time(NULL));
    int threeDArray[10][10][10];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < 10; k++){
                threeDArray[i][j][k] = rand() % 10;
                cout << threeDArray[i][j][k] << ' ';
            }
            cout << '\n';
        }
        cout << "------------------------------\n";
    }

    return 0;
}