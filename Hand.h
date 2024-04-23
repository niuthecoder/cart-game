#include "card.h"
#define HAND_SIZE  5
class Hand {
  protected:       
       Card *cards;   // The cards in the hand.
       int numCards;  // The number of cards in the hand.
  public:
       Hand();
       Hand(int);
       Card getCard(int);
       int getCardCount();
       void clear();
       void removeCard(Card);
       void removeCard(int);
       void addCard(Card);
       void sortHandBySuit();
       void sortHandByValue();
};
