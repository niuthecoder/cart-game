#include "Hand.h"
#include <iostream>
using namespace std;
Hand::Hand() {
     cards= new Card[HAND_SIZE];
     numCards=0;
}
Hand::Hand(int num) {
     cards= new Card[num];
     numCards=0;
}

/**
 * Remove all cards from the hand, leaving it empty.
 */
void Hand::clear() {
      numCards=0;
}

/**
 * Add a card to the hand.  
 * @param c the non-null card to be added.
 */
void Hand::addCard(Card c) {
  if(getCardCount()==HAND_SIZE){
    cout<<"\nHand is full.";
    exit(1);
  }
  cards[numCards]=c;
  numCards++;
}

/**
 * Remove a card from the hand, if present.
 * @param c the card to be removed.  If c is null or if the card is not in 
 * the hand, then nothing is done.
 */
void Hand::removeCard(Card c) {
    for(int i=0;i<numCards;i++)
        if(cards[i].cardcmp(c)) {
            for(int j=i;j<numCards-1;j++)
                cards[j]=cards[j+1];
            numCards--;
            return;
        } 
    cout<< c.toString()<< " is not in the hand.";
}


/**
 * Remove the card in a specified position from the hand.
 * @param position the position of the card that is to be removed, where
 * positions are numbered starting from zero.
 * print an error message and terminates the program if the position does not exist in 
 * the hand, that is if the position is less than 0 or greater than
 * or equal to the number of cards in the hand.
 */
void Hand::removeCard(int position) {
   if (position < 0 || position >=numCards){
     printf("Position is out of range");
     exit(1);
   }
   for(int i=position;i<numCards-1;i++)
        cards[i]=cards[i+1];
   numCards--;
}
/**
 * Returns the number of cards in the hand.
 */
int Hand::getCardCount() {
  return numCards;
}

/**
 * Gets the card in a specified position in the hand.  (Note that this card
 * is not removed from the hand!)
 * @param position the position of the card that is to be returned
 * @throws IllegalArgumentException if position does not exist in the hand
 */
Card Hand::getCard(int position) {
    if (position < 0 || position >= numCards){
        printf("\nPosition %d does not exist in hand",position);
        exit(1);
    }
    return cards[position];
}  
  

/**
 * Sorts the cards in the hand so that cards of the same suit are
 * grouped together, and within a suit the cards are sorted by value.
 * Note that aces are considered to have the lowest value, 1.
 */
void Hand::sortHandBySuit() {
    if( getCardCount()!=HAND_SIZE)
      cout<<"\nYour hand is not completed! You cannot sort it now!";
    else{
        Card tmp;
        for(int i=0;i<HAND_SIZE-1;i++)
         for(int j=i+1;j<HAND_SIZE;j++){
              if( 
                (cards[i].getSuit()> cards[j].getSuit())
                ||
                (cards[i].getSuit()== cards[j].getSuit() && cards[i].getValue()> cards[j].getValue())
                ){
                tmp=cards[i];
                cards[i]=cards[j];
                cards[j]=tmp; 
                } 
         }
      }
   }

/**
 * Sorts the cards in the hand so that cards of the same value are
 * grouped together.  Cards with the same value are sorted by suit.
 * Note that aces are considered to have the lowest value, 1.
 */
void Hand::sortHandByValue() {
  if( getCardCount()!=HAND_SIZE)
      cout<<"\nYour hand is not completed! You cannot sort it now!";
    else{
        Card tmp;
        for(int i=0;i<HAND_SIZE-1;i++)
         for(int j=i+1;j<HAND_SIZE;j++){
              if( 
                (cards[i].getValue()> cards[j].getValue())
                  ||
                  (cards[i].getValue()== cards[j].getValue() &&       
                   cards[i].getSuit()> cards[j].getSuit())
                ){
                tmp=cards[i];
                cards[i]=cards[j];
                cards[j]=tmp; 
                } 
         }
      }
   }
//-----------------------------------------------------