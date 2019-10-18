#include <iostream>
#include <string>

class Card
{
private:
    char suit;
    char face;

public:
    Card(char suit, char face){
        this->suit = suit;
        this->face = face;
    }
    friend std::wostream &operator<<(std::wostream &, const Card &);
};

std::wostream &operator<<(std::wostream &out, const Card &card)
{
    auto color = L"";
    auto rep = L'♠';
    auto face = L' ';
    face = card.face;
    // choose color and unicode representation
    switch (card.suit)
    {
    case 's':
        rep = L'♠';
        color = L"\033[0m";
        break;
    case 'c':
        rep = L'♣';
        color = L"\033[0m";
        break;
    case 'h':
        rep = L'♥';
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

class Deck{

};