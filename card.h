#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;
const int SPADES = 3;   // Codes for the 4 suits.
const int HEARTS = 2;
const int CLUBS = 0;
const int DIAMONDS = 1;

const int ACE = 14;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;

class Card{
private:
        int suit;  
        int value; 
public:
      Card();
      Card(int, int);
      int getValue();
      int getSuit();
      string getSuitAsString();
      string getValueAsString();
      string toString();
      bool cardcmp(Card);
};
#endif