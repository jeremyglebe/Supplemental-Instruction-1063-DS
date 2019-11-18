#include <iostream>
#include <string>
#include "TermGame.h"
using namespace std;
namespace TP = TermPrint;
namespace TG = TermGame;

string card(int);
void shuffle(int[], int);
void printhand(int[], int);

int main() {
    srand(time(NULL));
    const int SIZE = 5;
    int hand[5];


    // shuffle(hand, SIZE);
    // TP::clear();
    // cout << "Press [Q] to quit, press [N] for new hand.\n\n";
    // printhand(hand, SIZE);

    char button = 'n';
    do{
        TG::sleep(100);
        if(button == 'n'){
            shuffle(hand, SIZE);
            TP::clear();
            cout << "Press [Q] to quit, press [N] for new hand.\n\n";
            printhand(hand, SIZE);
        }
        button = TG::getch();
        //cin >> button;
    }while(button != 'q');

}

string card(int x){

    char faces[] = {'A', '2', '3', '4', '5', '6', '7','8','9', 'T', 'J', 'Q', 'K'};
    string suits[] = {"♥", "♦","♣", "♠"};

    int suit = x / 13;
    int face = x % 13;
    string color;
    if (suit < 2){
        color = "&28";
    }else{
        color = "&18";
    }

    string c = "";
    c+=color;
    c += "┌──┐\n";
    c+=color;
    c += "│";
    c += faces[face];
    c += suits[suit];
    c += "│\n";
    c+=color;
    c += "└──┘\n";

    return c;
}


void shuffle(int hand[], int size){

    // add random cards
    for(int i = 0; i < size; i++){
        hand[i] = rand() % 52;
    }
}


void printhand(int hand[], int size){
    // print a hand of cards
    string hand_string = "";
    for(int i = 0; i < size; i++){
        hand_string = TP::fuse(hand_string, card(hand[i]));
    }
    TP::print(hand_string);
}