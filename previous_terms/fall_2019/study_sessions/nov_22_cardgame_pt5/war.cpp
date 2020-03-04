#include <iostream>
#include <string>
#include <time.h>
#include "Card.h"
#include "TermGame.h"

namespace TG = TermGame;
namespace TP = TermPrint;

// getValue will determine what a card's worth is for this particular game
// the reason the card itself doesn't handle this is because this may vary from
// card game to card game. It may seem intuitive that 10 > 4, but what about
// A,K,Q,J,JOKER? Different games treat these very differently. So, our
// "war.cpp" will determine the scoring of each card for its' game.
float getValue(Card);
void print_game_screen(Deck, Deck, int p1Wins, int p2Wins);

int main()
{
    srand(time(NULL));
    Deck deck = Deck::std_deck();
    deck.shuffle();

    // Win counts
    int p1Wins = 0;
    int p2Wins = 0;

    // declare player decks
    Deck p1 = deck;
    Deck p2;
    for (int i = 0; i < 26; i++)
    {
        p2.push(p1.pop());
    }

    // Game logic for the 26 turns
    for (int i = 0; i < 26; i++)
    {
        std::string choice;
        print_game_screen(p1, p2, p1Wins, p2Wins);
        choice = TG::getkey();
        while (choice != "p")
        {
            if (choice == "s")
            {
                p1.shuffle();
                print_game_screen(p1, p2, p1Wins, p2Wins);
                choice = TG::getkey();
            }
        }
        // interpret cards at the top
        short score1 = getValue(p1.pop());
        short score2 = getValue(p2.pop());
        if (score1 > score2){
            // player got a point
            p1Wins++;
        } else{
            // enemy got a point
            p2Wins++;
        }
    }
    
    print_game_screen(p1, p2, p1Wins, p2Wins);
}

void print_game_screen(Deck p1, Deck p2, int p1Wins, int p2Wins)
{
    TP::clear();
    // Print the decks
    TP::print("[YOU]    [NOT YOU]\n");
    std::string padding = "";
    padding += "      \n";
    padding += "      \n";
    padding += "      \n";
    padding += "      \n";
    std::string decks = "";
    decks = TP::fuse(p1.toString(), padding);
    decks = TP::fuse(decks, p2.toString());
    TP::print( decks );
    TP::print( "  " + std::to_string(p1Wins) + "           " + std::to_string(p2Wins));
    TP::print("\nEnter [s] to shuffle.\nEnter [p] to play card.\n> ");
}

float getValue(Card card)
{
    float score = 0;
    if (card.getFace() >= '2' || card.getFace() >= '9')
    {
        score += card.getFace() - '0';
    }
    else
    {
        switch (card.getFace())
        {
        case 'T':
            score += 10;
            break;
        case 'J':
            score += 11;
            break;
        case 'Q':
            score += 12;
            break;
        case 'K':
            score += 13;
            break;
        case 'A':
            score += 14;
            break;
        default:
            score += -1;
        }
    }
    switch (card.getSuit())
    {
    case 's':
        score += .3;
        break;
    case 'h':
        score += .2;
        break;
    case 'c':
        score += .1;
        break;
    case 'd':
    default:
        score += 0;
    }
    return score;
}