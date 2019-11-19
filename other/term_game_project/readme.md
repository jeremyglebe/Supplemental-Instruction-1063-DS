# This is **NOT** a real assignment. I am doing a write-up for a possible assignment. It is a draft at best and may not be used at all by the professor.

## Program X - Blackjack

### Overview

The card game Blackjack is a game in which players draw cards attempting to get
the sum total of their hand as close to 21 as possible. If the total of their
hand exceeds 21, they lose automatically. If neither player has a hand over 21
(a "bust") then the player closest to or at 21 is the winner. If both players
have the same sum, it is a tie. Face cards (jack, queen, king) are all worth
10 and the Ace can be treated as a 1 or an 11 at the player's discretion.

### Data Structure Representations
- Cards
  - Cards can be expressed as simple integers 0-51
  - You **could** put the integers in a Card class with methods to act on
    the ints (such as printing the integer to look like a card)
- Deck of Cards
  - Think of the deck as a stack of cards, you only "draw" (pop)
    off of the top of the stack
  - Each Node in the stack should hold a card. This would either be an int or,
    if you wrote one, the card class.
- Player Hand
  - The player's hand should be a doubly linked list
  - They can traverse forwards or backwards through to select a card
- Opponent Hand
  - The opponents hand can be a simple array or a list, it doesn't matter
  - Their hand does not require interaction

### Assignment

Create a visual game of Blackjack using the TermGame.h library. Cards will be
represented as integers 0-51. There is not exact correct or incorrect output,
but the structures above should be implemented and used in the game. In
addition, the game should (regardless of implmentation) demonstrate the
following features:
  - The player's hand is visible, the cards look at least somewhat
    like cards (not just numbers) and are colored based on suit
  - The opponent's hand is displayed but obscured so that the player can see
    how many cards they have, but not what the cards are.
    - Try something like this: 
    ```
    ┌────┐
    │■■■■│
    │■■■■│
    └────┘
    ```
  - The player should press a button to draw another card from the deck
  - The player should press a button to "fold" (choose to keep their current
    hand and not draw again)
  - The player can select Aces and change their value from 1 to 11
    or back again.
  - The opponent should randomly choose whether to draw again or fold.
  - The opponent should randomly choose which value an Ace uses.
  - Once the player and opponent have folded, the game should tell the user
    who won.

### Requirements

#### Bonus Requirement:

### Deliverables
