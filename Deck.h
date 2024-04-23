#include "card.h"
#ifndef DECK_H
#define DECK_H

#define DECK_SIZE  52
class Deck {
private:
       Card *deck; 
       int cardsUsed; 
public:
       Deck();
       void  shuffle();
       int cardsLeft();
       Card dealCard();
};
#endif
