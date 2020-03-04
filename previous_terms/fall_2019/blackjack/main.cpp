#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include "TermGame.h"
#include "Stack.h"
#include "List.h"
using namespace std;

char FACES[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
string SUITS[] = {"♥", "♦", "♣", "♠"};
string card(int x, bool selected);
int score(List hand);
void print_screen(List player, List opponent, ListNode *selector);
void run_ai(List &opponent, Stack &deck, bool &ofolded);
bool play_again(bool victory);

string S1;
string S2;

int main()
{
    // Tracks whether the player wins a game. Needs to be declared above
    // the loop for use in the "play again?" screen.
    bool victory;

    // Play the game once, then keep playing while the user chooses to
    do
    {
        List player;
        List opponent;
        Stack deck;
        ListNode *selector;
        victory = false;

        // Doesn't make a standard deck, but making and shuffling a standard deck
        // may take extra effort. Bonus perhaps? The current deck may have
        // duplicate cards.
        srand(time(NULL));
        for (int i = 0; i < 52; i++)
        {
            deck.push(rand() % 52);
        }

        // Control variables for the game
        bool folded = false;
        bool ofolded = false;

        // Deal the first two cards
        player.FrontSert(deck.pop());
        opponent.FrontSert(deck.pop());
        selector = player.head;

        // Game loop
        while (!folded || !ofolded)
        {
            print_screen(player, opponent, selector);
            // USER CONTROLS
            if (!folded)
            {
                string key = TermGame::getkey();
                // use left or right arrow key to change card choice
                if (key == "ARROW_LEFT" && selector->prev)
                {
                    selector = selector->prev;
                }
                else if (key == "ARROW_RIGHT" && selector->next)
                {
                    selector = selector->next;
                }
                // hit 'D' to draw
                else if (key == "d")
                {
                    player.EndSert(deck.pop());
                    // if the user draws, the opponent should take a turn
                    run_ai(opponent, deck, ofolded);
                }
                // hit 'F' to fold
                else if (key == "f")
                {
                    folded = true;
                    // if the user draws, the opponent should take a turn
                    run_ai(opponent, deck, ofolded);
                }
                // hit 'A' to switch an ace's value
                else if (key == "a")
                {
                    // if its an ace...
                    if (abs(selector->data) % 13 == 12)
                    {
                        // positive aces represent a value of 1
                        // negative aces represent a value of 11
                        // flip positive or negative
                        selector->data = 0 - selector->data;
                    }
                }
            }
            else
            {

                // if the user does not take a turn because they have folded, but
                // the opponent has not, the opponent should take a turn
                run_ai(opponent, deck, ofolded);
            }
        }

        // DEBUGGING
        S1 = to_string(score(player));
        S2 = to_string(score(opponent));
        // if the opponent busted and you did not, you win
        if (score(player) <= 21 && score(opponent) > 21)
        {
            victory = true;
        }
        // if you did not bust and you have a higher score, you win
        // (or if you tied)
        else if (score(player) <= 21 && score(player) >= score(opponent))
        {
            victory = true;
        }

        // print final hands!!!
        TermPrint::clear();
        // Create a string of the opponents hand
        string opp = "";
        ListNode *temp = opponent.head;
        for (int i = 0; i < opponent.size; i++)
        {
            opp = TermPrint::fuse(opp, card(temp->data, false));
            temp = temp->next;
        }
        // Create a string of the player's hand
        string ply = "";
        temp = player.head;
        for (int i = 0; i < player.size; i++)
        {
            ply = TermPrint::fuse(ply, card(temp->data, false));
            temp = temp->next;
        }
        // Print the players hands
        TermPrint::print("[OPPONENT]\n");
        TermPrint::print(opp);
        TermPrint::print("[YOU]\n");
        TermPrint::print(ply);
        TermPrint::print("\n\n\n");

    } while (play_again(victory));
}

string card(int x, bool selected)
{
    int suit = abs(x) / 13;
    int face = abs(x) % 13;
    string color;
    if (suit < 2)
    {
        color = "&2";
    }
    else
    {
        color = "&1";
    }
    if (selected)
    {
        color += "6";
    }
    else
    {
        color += "8";
    }
    string c = "";
    c += color;
    c += "┌────┐\n";
    c += color;
    c += "│ ";
    c += FACES[face];
    c += "  │\n";
    c += color;
    c += "│  ";
    c += SUITS[suit];
    c += " │\n";
    c += color;
    if (face != 12)
    {
        c += "└────┘\n";
    }
    else
    {
        c += "└─";
        if (x < 0)
        {
            c += "11";
        }
        else
        {
            c += "01";
        }
        c += "─┘\n";
    }
    return c;
}

int score(List hand)
{
    char FACES[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    int sum = 0;
    ListNode *card_ptr = hand.head;
    for (int i = 0; i < hand.size; i++)
    {
        int card_num = abs(card_ptr->data) % 13;
        if (card_num < 9)
        {
            // if the number representation is 0 through 8, then its face is
            // somewhere between 2 and 10
            sum += card_num + 2;
        }
        else if (card_num != 12)
        {
            // if the number is not a 12, then its not an ace
            // non-ace, non-numeric cards are going to be a face card
            // face cards are worth 10
            sum += 10;
        }
        else
        {
            // if we're in this block we know its an ace
            // aces are either positive (value of 1) or negative (value of 11)
            if (card_ptr->data > 0)
            {
                sum += 1;
            }
            else
            {
                sum += 11;
            }
        }
        card_ptr = card_ptr->next;
    }
    return sum;
}

void print_screen(List player, List opponent, ListNode *selector)
{
    TermPrint::clear();

    // Create a string of a "hidden" card
    string hidden_card = "";
    hidden_card += "&58┌────┐\n";
    hidden_card += "&58│■■■■│\n";
    hidden_card += "&58│■■■■│\n";
    hidden_card += "&58└────┘\n";

    // Create a string of spaces the size of a card
    string spaces = "";
    spaces += "      \n";
    spaces += "      \n";
    spaces += "      \n";
    spaces += "      \n";

    // Create a string of the opponents hand
    string opp = "";
    for (int i = 0; i < opponent.size; i++)
    {
        opp = TermPrint::fuse(opp, hidden_card);
    }

    // Create a string of the player's hand
    string ply = "";
    ListNode *temp = player.head;
    for (int i = 0; i < player.size; i++)
    {
        if (temp == selector)
        {
            ply = TermPrint::fuse(ply, card(temp->data, true));
        }
        else
        {
            ply = TermPrint::fuse(ply, card(temp->data, false));
        }
        temp = temp->next;
    }

    // Create a string for the deck. It should be spaced a little.
    string deck = TermPrint::fuse(spaces, spaces);
    deck = TermPrint::fuse(deck, hidden_card);

    // Print everything
    TermPrint::print("[OPPONENT]\n");
    TermPrint::print(opp);
    TermPrint::print("\n\n            [DECK]\n");
    TermPrint::print(deck);
    TermPrint::print("\n\n");
    TermPrint::print("[YOU]\n");
    TermPrint::print(ply);
    string instructions = "[⇄] Select a card\n";
    instructions += "[A] Change value of selected ace\n";
    instructions += "[D] Draw another card\n";
    instructions += "[F] Fold, finish game\n";
    TermPrint::print(instructions);
}

void run_ai(List &opponent, Stack &deck, bool &ofolded)
{
    // OPPONENT AI
    if (!ofolded)
    {
        if (rand() % 3)
        {
            opponent.EndSert(deck.pop());
            // check the card that was just added, if it is an ace,
            // randomly choose its value
            if (opponent.tail->data % 13 == 12)
            {
                if (rand() % 2)
                {
                    opponent.tail->data = 0 - opponent.tail->data;
                }
            }
        }
        else
        {
            ofolded = true;
        }
    }
}

bool play_again(bool victory)
{
    string msg = "";
    if (victory)
    {
        msg += "&40 ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄       ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄  ▄ \n";
        msg += "&40▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌     ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░▌      ▐░▌▐░▌\n";
        msg += "&40▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌     ▐░▌       ▐░▌ ▀▀▀▀█░█▀▀▀▀ ▐░▌░▌     ▐░▌▐░▌\n";
        msg += "&40▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌       ▐░▌     ▐░▌     ▐░▌▐░▌    ▐░▌▐░▌\n";
        msg += "&40▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌   ▄   ▐░▌     ▐░▌     ▐░▌ ▐░▌   ▐░▌▐░▌\n";
        msg += "&40▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌  ▐░▌  ▐░▌     ▐░▌     ▐░▌  ▐░▌  ▐░▌▐░▌\n";
        msg += "&40 ▀▀▀▀█░█▀▀▀▀ ▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌ ▐░▌░▌ ▐░▌     ▐░▌     ▐░▌   ▐░▌ ▐░▌▐░▌\n";
        msg += "&40     ▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌▐░▌ ▐░▌▐░▌     ▐░▌     ▐░▌    ▐░▌▐░▌ ▀ \n";
        msg += "&40     ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌     ▐░▌░▌   ▐░▐░▌ ▄▄▄▄█░█▄▄▄▄ ▐░▌     ▐░▐░▌ ▄ \n";
        msg += "&40     ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░░▌     ▐░░▌▐░░░░░░░░░░░▌▐░▌      ▐░░▌▐░▌\n";
        msg += "&40      ▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀       ▀▀       ▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀  ▀ \n";
    }
    else
    {
        msg += "&20▓██   ██▓ ▒█████   █    ██     ██▓     ▒█████    ██████ ▓█████  ▐██▌ \n";
        msg += "&20 ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓██▒    ▒██▒  ██▒▒██    ▒ ▓█   ▀  ▐██▌ \n";
        msg += "&20  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒██░    ▒██░  ██▒░ ▓██▄   ▒███    ▐██▌ \n";
        msg += "&20  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ▒██░    ▒██   ██░  ▒   ██▒▒▓█  ▄  ▓██▒ \n";
        msg += "&20  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░██████▒░ ████▓▒░▒██████▒▒░▒████▒ ▒▄▄  \n";
        msg += "&20   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░░ ▒░ ░ ░▀▀▒ \n";
        msg += "&20 ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░    ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░ ░ ░  ░ ░  ░ \n";
        msg += "&20 ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░ ░   ░ ░ ░ ▒  ░  ░  ░     ░       ░ \n";
        msg += "&20 ░ ░         ░ ░     ░            ░  ░    ░ ░        ░     ░  ░ ░    \n";
        msg += "&20 ░ ░                                                                 \n";
    }
    TermPrint::print(msg);
    // DEBUGGING
    TermPrint::print("Player: " + S1 + "\nOpponent: " + S2 + "\n");
    TermPrint::print("Do you wish to play again? [Y/N]\n");
    char choice = ' ';
    while (choice != 'y' && choice != 'n')
    {
        choice = TermGame::getch();
    }
    if (choice == 'y')
    {
        return true;
    }
    return false;
}