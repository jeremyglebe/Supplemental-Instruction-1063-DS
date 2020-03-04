#include <string>
using namespace std;

class Card
{
public:
    // Constructor to make a default card: A♥
    Card()
    {
        card = 0;
        score = 1;
    }

    // Constructor to make a card from an int.
    Card(int c)
    {
        // assign the card to the passed in card
        card = c;
        // this condition looks for cards A-9
        if (card % 13 < 10)
        {
            // add one b/c cards start at 0
            // so card 2, which is "3♥", will get a score of 3
            score = (card % 13) + 1;
        }
        else
        {
            // face cards all get a score of 10
            score = 10;
        }
    }

    // Get the card
    int getScore()
    {
        return score;
    }

    // Change the value of the card IF it's an Ace
    void changeAce()
    {
        // if the score is 1, make it 11
        if (score == 1)
            score = 11;
        // otherwise, if the score is 11, make it 1
        else if (score == 11)
            score = 1;
    }

    string cardString()
    {
        // This is how we get our card's face
        string f = FACES[card % 13];
        // This is how we get our suit character
        string s = SUITS[card / 13];

        // model is what our card should look like, we'll then replace
        // some characters in card to make it look right
        string model = "";
        model += "&C8┌────┐\n";
        model += "&C8│XX  │\n";
        model += "&C8│ FS │\n";
        model += "&C8│  XX│\n";
        model += "&C8└────┘\n";

        // c represents the foreground color of the card
        // the background color will be WHITE (code 8), seen above in the model
        string c;
        if (s == "♥" || s == "♦")
        {
            // 2 is the code for RED, diamonds and hearts should be red
            c = "2";
        }
        else
        {
            // 1 is the code for BLACK, clubs and spades should be black
            c = "1";
        }
        // The x's need to be replaced with the cards score
        string x = to_string(score);
        // If score is one digit, we still want to
        // print with two digits, add a 0 to the front
        if (x.size() < 2)
        {
            x = '0' + x;
        }

        // Make a new card based on the model, but replace the placeholders
        string card_string = "";
        for (int i = 0; i < model.size(); i++)
        {
            // if we find a 'C', we need to use our color we determined above
            if (model[i] == 'C')
            {
                card_string += c;
            }
            // if we find an 'X', we need to use our score
            else if (model[i] == 'X')
            {
                card_string += x;
                // the next character will also be an 'X' and we are replacing
                // both. so we don't want to read the second one separately.
                i++;
            }
            // if we find an 'F', we need to use our face
            else if (model[i] == 'F')
            {
                card_string += f;
            }
            // if we find an 'S', we need to use our suit
            else if (model[i] == 'S')
            {
                card_string += s;
            }
            // if the character we find is in no way special
            // (not a placeholder) then we just add that character
            else
            {
                card_string += model[i];
            }
        }

        return card_string;
    }

    // This does the EXACT same thing as cardString, but we use a different
    // background color to show that its highlighted
    string highlightedCardString()
    {
        string f = FACES[card % 13];
        string s = SUITS[card / 13];

        // model is what our card should look like
        // NOTE: That the color code has changed from C8 in the
        // cardString method to C4, this is because it should have
        // a green background to show it is highlighted
        string model = "";
        model += "&C4┌────┐\n";
        model += "&C4│XX  │\n";
        model += "&C4│ FS │\n";
        model += "&C4│  XX│\n";
        model += "&C4└────┘\n";

        string c;
        if (s == "♥" || s == "♦")
            c = "2";
        else
            c = "1";

        string x = to_string(score);
        // If score is one digit, we still want to
        // print with two digits, add a 0 to the front
        if (x.size() < 2)
        {
            x = '0' + x;
        }

        // Make a new card based on the model, but replace the placeholders
        string card_string = "";
        for (int i = 0; i < model.size(); i++)
        {
            if (model[i] == 'C')
                card_string += c;
            else if (model[i] == 'X')
            {
                card_string += x;
                i++;
            }
            else if (model[i] == 'F')
                card_string += f;
            else if (model[i] == 'S')
                card_string += s;
            else
                card_string += model[i];
        }

        return card_string;
    }

private:
    int card;
    int score;
    const string FACES[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
    const string SUITS[4] = {"♥", "♦", "♣", "♠"};
};