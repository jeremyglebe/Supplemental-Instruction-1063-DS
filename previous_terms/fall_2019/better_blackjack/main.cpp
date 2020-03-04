#include "TermGame.h"
#include "Card.h"
using namespace TermGame;
using namespace TermPrint;

int main(){
    Card AceOfSpades(39);
    print(AceOfSpades.cardString());
    AceOfSpades.changeAce();
    print(AceOfSpades.highlightedCardString());
}