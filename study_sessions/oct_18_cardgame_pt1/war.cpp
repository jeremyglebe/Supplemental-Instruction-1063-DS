// fnctl.h is being used to fix windows, we'll make this cross-platform later
// by checking if we're using windows before including it
#include <fcntl.h>
#include <iostream>
#include <string>
#include "Card.h"

// getValue will determine what a card's worth is for this particular game
// the reason the card itself doesn't handle this is because this may vary from
// card game to card game. It may seem intuitive that 10 > 4, but what about
// A,K,Q,J,JOKER? Different games treat these very differently. So, our
// "war.cpp" will determine the scoring of each card for its' game.
float getValue(Card);

int main()
{
    // _setmode is being used to fix windows, we'll make this cross-platform
    // later by checking if we're using windows before including it
    _setmode(_fileno(stdout), _O_U16TEXT);
    // We're going to instantiate two cards and test printing their special
    // characters and colors
    Card card('d', 'K');
    // wcout, or Wide Cout, is capable of printing characters larger than 8-bit
    // such as unicode and ansi
    // We overloaded operator<< to work with wcout and cards in the Card.h file
    std::wcout << card << '\n';
    Card card2('s', 'A');
    std::wcout << card2 << '\n';
}