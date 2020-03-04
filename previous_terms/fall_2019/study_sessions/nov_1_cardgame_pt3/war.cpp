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

int main()
{
    Deck deck = Deck::std_deck();
    deck.shuffle();
    deck.printAll(std::cout);
}