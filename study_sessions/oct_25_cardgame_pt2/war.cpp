// Define whether we are using Windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
// fnctl.h is being used to fix windows
#include <fcntl.h>
const bool WINDOWS = true;
#else
const bool WINDOWS = false;
int _setmode(int, int);
#endif

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
    if (WINDOWS)
    {
        // _setmode is being used to fix windows
        _setmode(_fileno(stdout), _O_U16TEXT);
    }

    Deck deck;
    // populate it with cards 1-9 semi-random color
    srand(42);
    for (char i = '1'; i <= '9'; i++)
    {
        if (rand() % 2)
        {
            deck.push(Card('s', i));
        }
        else
        {
            deck.push(Card('h', i));
        }
    }
    // print that deck, before any pops
    deck.printAll(std::wcout);
    // pop a few items and then push a king
    for (int i = 0; i < 4; i++)
    {
        deck.pop();
    }
    deck.push(Card('d', 'K'));
    // print the new deck
    std::wcout << "\n\n";
    deck.printAll(std::wcout);
}