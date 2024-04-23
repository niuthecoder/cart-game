#include "Deck.h"
#include <iostream>
using namespace std;


  Deck::Deck() {
    int cardCt = 0; // How many cards have been created so far.
    deck=new Card[52];
    for ( int suit = 0; suit <= 3; suit++ ) {
        for ( int value = 2; value <= 14; value++ ) {
            deck[cardCt] = Card(value,suit);
            cardCt++;
        }
    }
    cardsUsed = 0;
  }

/**
 * Put all the used cards back into the deck (if any), and
 * shuffle the deck into a random order.
 */
void  Deck::shuffle() {
    for ( int i = 51; i > 0; i-- ) {
        int rnd = rand()%(i+1);
        Card temp = deck[i];
        deck[i] = deck[rnd];
        deck[rnd] = temp;
    }
    cardsUsed = 0;
}

/**
 * As cards are dealt from the deck, the number of cards left
 * decreases.  This function returns the number of cards that
 * are still left in the deck.  The return value would be
 * 52 when the deck is first created or after the deck has been
 * shuffled.  It decreases by 1 each time the dealCard() method
 * is called.
 */
int Deck::cardsLeft() {
    return 52 - cardsUsed;
}

/**
 * Removes the next card from the deck and return it.  It is illegal
 * to call this method if there are no more cards in the deck.  You can
 * check the number of cards remaining by calling the cardsLeft() function.
 * @return the card which is removed from the deck.
 * @throws IllegalStateException if there are no cards left in the deck
 */
Card Deck::dealCard() {
    if (cardsUsed == 52){
        cout<<"No cards are left in the deck.";
        exit(1);
    }
    cardsUsed++;
    return deck[cardsUsed - 1];
    // Programming note:  Cards are not literally removed from the array
    // that represents the deck.  We just keep track of how many cards
    // have been used.
}

