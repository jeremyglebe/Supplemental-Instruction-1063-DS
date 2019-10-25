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
    // wostream is a "wide" ostream, it can be used to print characters larger
    // than 8-bits.
    friend std::wostream &operator<<(std::wostream &, const Card &);
};

std::wostream &operator<<(std::wostream &out, const Card &card)
{
    // auto will decide on a type for you based on the first value you give to
    // the variable. In this case we will be getting variables of a type called
    // wchar_t. That stands for "wide character type", it represents characters
    // that will be bigger than 8-bits.
    // The 'L' in front of our chars and strings means "literal" and ensures
    // that C++ won't truncate the wide characters. You can manually name your
    // types things like wchar_t and wstring if you would rather do that. This
    // was just a good opportunity to show the auto keyword.
    auto color = L"";
    auto rep = L'♠';
    // we declare it equal to the ' ' character first, before assigning it to
    // card.face, to ensure that it automatically is treated as a wide
    // character. If we assigned it to face first, it would be treated as a
    // normal character because that is what card.face is
    auto face = L' ';
    face = card.face;
    // choose color and unicode representation based on the normal-character
    // suit (s for spades, c for clubs, etc...)
    switch (card.suit)
    {
    case 's':
        rep = L'♠';
        // \033[ is the ansi escape sequence
        // 0m is the code for "default" (white)
        color = L"\033[0m";
        break;
    case 'c':
        rep = L'♣';
        color = L"\033[0m";
        break;
    case 'h':
        rep = L'♥';
        // \033[ is the ansi escape sequence
        // 31m is the code for "red"
        color = L"\033[31m";
        break;
    case 'd':
        rep = L'♦';
        color = L"\033[31m";
        break;
    }
    // reset and set color output
    out << "\033[0m" << color;
    out << L"┏━━┓\n";
    out << L"┃" << rep << face << L"┃\n";
    out << L"┗━━┛\n";
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
    void printAll(std::wostream &wout)
    {
        Node *temp = top;
        while (temp != NULL)
        {
            wout << temp->card;
            temp = temp->next;
        }
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