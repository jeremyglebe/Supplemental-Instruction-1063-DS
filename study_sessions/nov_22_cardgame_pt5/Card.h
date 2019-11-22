#include <iostream>
#include <string>
#include "TermGame.h"
namespace TP = TermPrint;

class Card
{
private:
    char suit;
    char face;

public:
    Card(char suit = 's', char face = 'A')
    {
        this->suit = suit;
        this->face = face;
    }
    char getSuit() { return suit; }
    char getFace() { return face; }

    void print()
    {
        std::string rep = "♠";
        char face = ' ';
        // select unicode representation of suit
        switch (suit)
        {
        case 's':
            rep = "♠";
            break;
        case 'c':
            rep = "♣";
            break;
        case 'h':
            rep = "♥";
            break;
        case 'd':
            rep = "♦";
            break;
        }
        // create a string out of the card
        std::string card_string = "";
        card_string += "┏━━┓\n";
        card_string += "┃" + rep + face + "┃\n";
        card_string += "┗━━┛\n";
        // print using the correct color
        if (suit == 's' || suit == 'c')
        {
            TP::print(card_string, TP::WHITE);
        }
        else
        {
            TP::print(card_string, TP::RED);
        }
    }
};

class Deck
{
public:
    Deck()
    {
        top = NULL;
        size = 0;
    }
    void push(Card c)
    {
        size++;
        top = new Node(c, top);
    }
    Card pop()
    {
        Card top_card = top->card;
        size--;
        Node *going_to_delete = top;
        top = top->next;
        delete going_to_delete;
        return top_card;
    }
    void print()
    {
        Card card = top->card;
        std::string rep = "♠";
        // get unicode character
        switch (card.getSuit())
        {
        case 's':
            rep = "♠";
            break;
        case 'c':
            rep = "♣";
            break;
        case 'h':
            rep = "♥";
            break;
        case 'd':
            rep = "♦";
            break;
        }
        std::string deck_string;
        deck_string += "┏━━┓\n";
        deck_string += "┃" + rep + card.getFace() + "┣┓\n";
        deck_string += "┗┳━┛┃\n";
        deck_string += " ┗━━┛\n";
        if (card.getSuit() == 's' || card.getSuit() == 'c')
        {
            TP::print(deck_string, TP::WHITE);
        }
        else
        {
            TP::print(deck_string, TP::RED);
        }
    }
    void printAll()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            temp->card.print();
            temp = temp->next;
        }
    }
    void shuffle()
    {
        Node *shuffled_top = NULL;
        Node *temp = top;
        Node *placer = NULL;
        Node *trailer = NULL;
        int pos = 0;
        int current_size = 0;

        // make a new shuffled list
        while (temp)
        {
            // how many places forward should we move
            pos = rand() % (current_size + 1);
            // if we're inserting at the front
            if (pos == 0)
            {
                placer = new Node(temp->card, shuffled_top);
                shuffled_top = placer;
                current_size++;
            }
            else
            {
                // initialize placer and trailer 1 over (since we know its
                // going to be greater than 0)
                placer = shuffled_top;
                trailer = placer;
                // loop sets up pointers for placement
                for (int i = 0; i < pos - 1; i++)
                {
                    placer = placer->next;
                    trailer = placer;
                }
                // create a new node that points to placer->next, then make
                // placer equal to that node
                placer = new Node(temp->card, placer->next);
                // fix list connections
                trailer->next = placer;
                current_size++;
            }

            // continue traversal and delete parts of old list
            temp = temp->next;
            delete top;
            top = temp;
        }

        // assign stack top to the shuffled list
        top = shuffled_top;
    }
    static Deck std_deck()
    {
        Deck deck;
        char faces[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        char suits[] = {'s', 'h', 'c', 'd'};
        for (int i = 0; i < 52; i++)
        {
            char face = faces[i % 13];
            char suit = suits[i / 13];
            deck.push(Card(suit, face));
        }
        return deck;
    }
    std::string toString(){
        Card card = top->card;
        std::string rep = "♠";
        std::string color = "&00";
        // get unicode character
        switch (card.getSuit())
        {
        case 's':
            rep = "♠";
            break;
        case 'c':
            rep = "♣";
            break;
        case 'h':
            rep = "♥";
            color = "&20";
            break;
        case 'd':
            rep = "♦";
            color = "&20";
            break;
        }
        std::string deck_string;
        deck_string += color + "┏━━┓ \n";
        deck_string += color + "┃" + rep + card.getFace() + "┣┓\n";
        deck_string += color + "┗┳━┛┃\n";
        deck_string += color + " ┗━━┛\n";

        return deck_string;
    }

private:
    struct Node;
    Node *top;
    int size;
    struct Node
    {
        Card card;
        Node *next;
        Node(Card card, Node *next = NULL)
        {
            this->card = card;
            this->next = next;
        }
    };
};
