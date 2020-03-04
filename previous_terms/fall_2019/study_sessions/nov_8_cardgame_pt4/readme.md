# Card Game Part 4: Basic Game Setup
We are going to write a card game to be played in the terminal using concepts
and data structures that we learned about in class. At first, we are going to
make the game of "War".

## Concepts From Class
In the process of writing this card game program, we will end up using several
concepts that Dr. Griffin has gone over in class. Some of these concepts are:
* Stacks 
    * A deck of cards, used in almost every card game
* Queues 
    * A queue of players that determines who goes first, second, etc
* Doubly-Linked List 
    * Depending on the game, a player's hand may be represented this way

## Other "just cool to know" Concepts
We are going to be going over a few other neat tricks and concepts that were
not taught in class, but which will make this game project much more fun. There
will also be a few instances in which I just write a function to be used that
is too complicated to explain in this class. The idea is to make something fun
out of the things we've been learning! Some new concepts for this project:
* ANSI character encoding (colored text, screen clearing, etc)
* UNICODE character encoding (non-keyboard symbols, card suits, etc)
* Cross-platform method of input without the `ENTER` key
    * I will write this, the explanation will only be conceptual
* Cross-platform sleep using threads
    * I will write this, the explanation will only be conceptual

## Game: War
War's rules are simple (and kind of boring) but great to start with. We will
have a deck of cards which we deal into two other decks of cards. (one for each
player) Each turn, both players flips their top card. Whoever has the higher
card takes both and puts it in their discard pile. (also a deck) When their
decks are empty, whoever has the larger discard pile wins. In the event of
a tie, the suits take priority like so: Spades, Diamonds, Clubs, Hearts.
(Some rules vary depending on region and origin. We're going for "easy to
program")