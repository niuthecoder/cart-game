#include "Hand.h"
#include "Deck.h"
class PokerHand : public Hand {
private:
    int handRank;
public:
PokerHand();
int getHandRank();
void evaluate();
int royalFlush();
int straightFlush();
int fourOfaKind();
int fullHouse();
int flush();
int straight();
int triple();
int twoPairs();
int pair();
Card highCard();
void redraw(int position,Deck &d);
};
