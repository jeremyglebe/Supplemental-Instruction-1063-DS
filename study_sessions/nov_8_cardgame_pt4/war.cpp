#include <iostream>
#include <string>
#include <time.h>
#include "Card.h"

// getValue will determine what a card's worth is for this particular game
// the reason the card itself doesn't handle this is because this may vary from
// card game to card game. It may seem intuitive that 10 > 4, but what about
// A,K,Q,J,JOKER? Different games treat these very differently. So, our
// "war.cpp" will determine the scoring of each card for its' game.
float getValue(Card);
void clr_screen();
void print_game_screen(Deck, Deck);

int main()
{
    srand(time(NULL));
    Deck deck = Deck::std_deck();
    deck.shuffle();

    // declare player decks
    Deck p1 = deck;
    Deck p2;
    for(int i = 0; i < 26; i++){
        p2.push(p1.pop());
    }

    // Game logic for the 26 turns
    for(int i = 0; i < 26; i++){
        char choice;
        print_game_screen(p1, p2);
        std::cin >> choice;
        while(choice != 'p'){
            if(choice == 's'){
                p1.shuffle();
                print_game_screen(p1, p2);
                std::cin >> choice;
            }
        }
        // interpret cards at the top
        short score1 = getValue(p1.pop());
        short score2 = getValue(p2.pop());
    }

}

void print_game_screen(Deck p1, Deck p2){
    clr_screen();
    std::cout << "[PLAYER]\n" << p1;
    std::cout << "[OPPONENT]\n" << p2;
    std::cout << "\nEnter [s] to shuffle.\nEnter [p] to play card.\n> ";
}

void clr_screen(){
    std::cout << std::string(40, '\n') << std::flush;
}