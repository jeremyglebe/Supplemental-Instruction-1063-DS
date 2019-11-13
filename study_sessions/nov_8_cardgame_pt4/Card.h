#include <iostream>
#include <string>

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
    friend std::ostream &operator<<(std::ostream &, const Card &);
};

std::ostream &operator<<(std::ostream &out, const Card &card)
{
    const char *color = "";
    const char *rep = "♠";
    char face = ' ';
    face = card.face;
    // choose color and unicode representation based on the normal-character
    // suit (s for spades, c for clubs, etc...)
    switch (card.suit)
    {
    case 's':
        rep = "♠";
        // \033[ is the ansi escape sequence
        // 0m is the code for "default" (white)
        color = "\033[0m";
        break;
    case 'c':
        rep = "♣";
        color = "\033[0m";
        break;
    case 'h':
        rep = "♥";
        // \033[ is the ansi escape sequence
        // 31m is the code for "red"
        color = "\033[31m";
        break;
    case 'd':
        rep = "♦";
        color = "\033[31m";
        break;
    }
    // reset and set color output
    out << "\033[0m" << color;
    out << "┏━━┓\n";
    out << "┃" << rep << face << "┃\n";
    out << "┗━━┛\n";
    // reset color output again
    out << "\033[0m";
    // send back the stream
    return out;
}

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
    void printAll(std::ostream &wout)
    {
        Node *temp = top;
        while (temp != NULL)
        {
            wout << temp->card;
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
    friend std::ostream &operator<<(std::ostream &out, Deck deck);

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

std::ostream &operator<<(std::ostream &out, Deck deck)
{
    Card card = deck.top->card;
    const char *color = "";
    const char *rep = "♠";
    char face = ' ';
    face = card.getFace();
    // choose color and unicode representation based on the normal-character
    // suit (s for spades, c for clubs, etc...)
    switch (card.getSuit())
    {
    case 's':
        rep = "♠";
        // \033[ is the ansi escape sequence
        // 0m is the code for "default" (white)
        color = "\033[0m";
        break;
    case 'c':
        rep = "♣";
        color = "\033[0m";
        break;
    case 'h':
        rep = "♥";
        // \033[ is the ansi escape sequence
        // 31m is the code for "red"
        color = "\033[31m";
        break;
    case 'd':
        rep = "♦";
        color = "\033[31m";
        break;
    }
    // reset and set color output
    out << "\033[0m" << color;
    out << "┏━━┓\n";
    out << "┃" << rep << face << "┣┓\n";
    out << "┗┳━┛┃\n";
    out << " ┗━━┛\n";
    // reset color output again
    out << "\033[0m";
    // send back the stream
    return out;
}