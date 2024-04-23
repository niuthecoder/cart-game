#include "card.h"
#include <iostream>
#include <string>
using namespace std;

Card::Card(){
  value=1;
  suit=0;
}
 Card::Card (int theValue, int theSuit) {
        if (theSuit != SPADES   && theSuit != HEARTS &&
            theSuit != DIAMONDS && theSuit != CLUBS ){
            cout<< "Illegal playing card suit"<<endl;
            exit(1);
        }
        if (theValue < 2 || theValue > 14){
            cout<<"Illegal playing card value";
            exit(1);
        }
        value = theValue;
        suit = theSuit;
    }

    /**------------------------------------------------------------
     * Returns the suit of this card.
     * @returns the suit, which is one of the constants Card.SPADES, 
     * Card.HEARTS, Card.DIAMONDS, Card.CLUBS, or Card.JOKER
     */
    int Card::getSuit() {
        return suit;
    }

 /**------------------------------------------------------------
     * Returns the value of this card.
     * @return the value, which is one of the numbers 1 through 13, inclusive for
     * a regular card, and which can be any value for a Joker.
     */
    int Card::getValue() {
        return value;
    }

    /**------------------------------------------------------------
     * Returns a String representation of the card's suit.
     * @return one of the strings "Spades", "Hearts", "Diamonds", "Clubs"
     * or "Joker".
     */
    string Card::getSuitAsString() {
        switch ( suit ) {
        case SPADES:   return "Spades";
        case HEARTS:   return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS:    return "Clubs";
        }
      return "";
    }

    /**------------------------------------------------------------
     * Returns a String representation of the card's value.
     * @return for a regular card, one of the strings "Ace", "2",
     * "3", ..., "10", "Jack", "Queen", or "King".  For a Joker, the 
     * string is always numerical.
     */
    string Card::getValueAsString() {
            switch ( value ) {
              case 2:   return "2";
              case 3:   return "3";
              case 4:   return "4";
              case 5:   return "5";
              case 6:   return "6";
              case 7:   return "7";
              case 8:   return "8";
              case 9:   return "9";
              case 10:  return "10";
              case 11:  return "Jack";
              case 12:  return "Queen";
              case 13:  return "King";
              case 14:  return "Ace";
            }
        return "";
        }
     /**------------------------------------------------------------
     * Returns a string representation of this card, including both
     * its suit and its value (except that for a Joker with value 1,
     * the return value is just "Joker").  Sample return values
     * are: "Queen of Hearts", "10 of Diamonds", "Ace of Spades",
     * "Joker", "Joker #2"
     */
    string Card::toString() {
        string output;
        output=getValueAsString()+ " of "+ getSuitAsString();
        return output; 
    }
    /**------------------------------------------------------------
     * Compares 2 cards and return true if they are equal
     */
   bool Card::cardcmp(Card card2){
     if(value==card2.value && suit==card2.suit)
       return true;
     else
       return false;
   }

//--------------------------------------------------------------