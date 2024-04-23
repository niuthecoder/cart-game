#include "poker.h"
#include <iostream>
using namespace std;

PokerHand::PokerHand(){
  handRank=0;
}

int PokerHand::getHandRank(){
  return handRank;
}

// Functions for Poker Game
// evaluates the hand
void PokerHand::evaluate()
{
  if (royalFlush()){
      cout<<"You have a royal flush!";
      handRank=10;
  }
  else if (straightFlush()){
      cout<<"You have a straight flush!";
      handRank=9;
      }
  else if (fourOfaKind()){
      cout<<"You have four of a kind!";
      handRank=8;
      }
  else if (fullHouse()){
      cout<<"You have a full house!";
    handRank=7;
     }
  else if (flush()){
     cout<<"You have a flush!";
    handRank=6;
     }
  else if (straight()){
     cout<<"You have a straight!";
    handRank=5;
     }
  else if (triple()){
     cout<<"You have a triple!";
    handRank=4;
     }
  else if (twoPairs()){
      cout<<"You have two pairs!";
    handRank=3;
     }
  else if (pair()){
     cout<<"You have a pair!";
    handRank=2;
     }
  else
    {
    Card high = highCard();
    cout<<"Your highest card is "<<high.toString();
    handRank=1;
    }
}

// checks for a royal flush
//If there are 2 royal flushes in the running for High hand, then
//the ranking order from highest to lowest is Spades, Hearts, Diamonds and Clubs.
int PokerHand::royalFlush()
{
  if (cards[4].getValue() == 14 && cards[0].getValue() == 10 &&
      cards[1].getValue() == 11 &&  cards[2].getValue()== 12 && 
      cards[3].getValue() == 13 && flush())
      return cards[0].getSuit();
  else
     return 0;
}

// checks for a straight flush
//Between two straight flushes, the one containing the higher top card is higher.
int PokerHand::straightFlush()
{
  if(straight() && flush())
    return cards[4].getValue();
  else
    return 0;
}

// checks for four of a kind
// Between two fours of a kind, the one with the higher set of four cards is higher
int PokerHand::fourOfaKind()
{
  if (cards[0].getValue() != cards[3].getValue() && cards[1].getValue() != cards[4].getValue())
     return 0;
  else
     return cards[2].getValue();
}

// checks for full house
// When comparing full houses, the rank of the three cards determines
// which is higher. For example 9-9-9-4-4 beats 8-8-8-A-A.
int PokerHand::fullHouse()
{
  if(fourOfaKind())
       return 0;
  if(cards[0].getValue()==cards[1].getValue() && 
     cards[1].getValue()==cards[2].getValue() &&
     cards[3].getValue()==cards[4].getValue())
         return cards[0].getValue();

  if(cards[0].getValue()==cards[1].getValue() && 
     cards[2].getValue()==cards[3].getValue() &&
     cards[3].getValue()==cards[4].getValue())
         return cards[4].getValue();
  return 0;
}

// checks for flush
// When comparing two flushes, the highest card determines which is higher.
int PokerHand::flush()
{
  for (int counter = 1; counter < 5; counter++)
    if (cards[0].getSuit() != cards[counter].getSuit())
        return 0;
  return cards[4].getValue();
}

// check for straight
// When comparing two sequences, the one with the higher ranking top card is better. 
int PokerHand::straight()
{
  for (int counter2 = 1; counter2 < 5; counter2++)
    if (cards[counter2 - 1].getValue() != (cards[counter2].getValue() - 1))
      return 0;
  return cards[4].getValue();
}

// checks for triple
int PokerHand::triple()
{
  if (cards[0].getValue() == cards[2].getValue() || 
      cards[1].getValue() == cards[3].getValue() || 
      cards[2].getValue() == cards[4].getValue())
     return cards[2].getValue();
  return 0;
}

// checks for two pairs
int PokerHand::twoPairs()
{
  int check = 0;
  int cardValue=0;
  for(int counter = 1; counter < 5; counter++){
   if (cards[counter - 1].getValue() == cards[counter].getValue())
        check++;
        if(cardValue<cards[counter].getValue())
           cardValue = cards[counter].getValue();
    }

  if (check == 2)
      return cardValue;
  else
      return 0;

}

// check for pair
 int PokerHand::pair()
{
  int check = 0;
  int cardValue;
  for(int counter = 1; counter < 5; counter++)
     if (cards[counter - 1].getValue() == cards[counter].getValue()){
       check++;
       cardValue = cards[counter].getValue();
     }
  if (check == 1)
      return cardValue;
  else
      return 0;

}

// find highest card
Card PokerHand::highCard()
{
  return cards[4];
}

void PokerHand::redraw(int position, Deck &d){
  Card newcard=d.dealCard();
  cards[position]=newcard;
}
