#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "poker.h"
using namespace std;
int main() {
    Deck deck;
    srand(time(0));
    deck.shuffle();
    Card card;
    PokerHand player1;
    PokerHand player2;
    int  numCard,pos;
    cout<<"Welcome to Poker!\n";
    cout<<"The dealer will now deal player-1 five cards.\n";
    for(int i=0;i<5;i++){
        card=deck.dealCard();
        player1.addCard(card);
      }
      player1.sortHandByValue();
      cout<<"\nPlayer-1's Hand After Sorting:\n";
      cout<<setw(4)<<"Pos"<<setw(20)<<"Card"<<endl;
      for(int i=0;i<5;i++){
          card=player1.getCard(i);
          cout<<setw(4)<<i<<setw(20)<<card.toString()<<endl;
      }
      player1.evaluate();

      cout<<"\nHow many cards do you want to change player-1?";
      cin>>numCard;
      if(numCard>0 &&numCard<=5){
         cout<<"Enter card positions to change:";
         for(int i=0;i<numCard;i++){
           cin>>pos;
           player1.redraw(pos,deck);
         }
        player1.sortHandByValue();
       
       cout<<"\nPlayer 1's Hand After Redrawing:\n";
       for(int i=0;i<5;i++){
          card=player1.getCard(i);
          cout<<card.toString()<<endl;
         }
      }   
     player1.evaluate();

     cout<<"\nThe dealer will now deal player-2 five cards.\n";
     for(int i=0;i<5;i++){
         card=deck.dealCard();
         player2.addCard(card);
       }
       player2.sortHandByValue();
       cout<<"\nPlayer-2's Hand After Sorting:\n";
       cout<<setw(4)<<"Pos"<<setw(20)<<"Card"<<endl;
       for(int i=0;i<5;i++){
           card=player2.getCard(i);
           cout<<setw(4)<<i<<setw(20)<<card.toString()<<endl;
       }
       player2.evaluate();

       cout<<"\nHow many cards do you want to change player-2?";
       cin>>numCard;
       if(numCard>0 &&numCard<=5){
          cout<<"Enter card positions to change:";
          for(int i=0;i<numCard;i++){
            cin>>pos;
            player2.redraw(pos,deck);
          }
         player2.sortHandByValue();

        cout<<"\nPlayer 2's Hand After Redrawing:\n";
        for(int i=0;i<5;i++){
           card=player2.getCard(i);
           cout<<card.toString()<<endl;
          }
       }   
      player2.evaluate();
     int value1=player1.getHandRank();
     int value2=player2.getHandRank();
     if( value1>value2)
          cout<<"\nPlayer 1 wins!";
      else if(value1<value2)
          cout<<"\nPlayer 2 wins!";
      else{
          int v1,v2;
          switch(value1){
            case 1:v1=player1.getCard(4).getValue();
                   v2=player2.getCard(4).getValue();
                   break;
            case 2:v1=player1.pair();
                   v2=player2.pair();
                   break;
            case 3:v1=player1.twoPairs();
                   v2=player2.twoPairs();
                   break;
            case 4:v1=player1.triple();
                   v2=player2.triple();
                   break;
            case 5:v1=player1.straight();
                   v2=player2.straight();
                   break;
            case 6: v1=player1.flush();
                    v2=player2.flush();
                    break;
            case 7: v1=player1.fullHouse();
                    v2=player2.fullHouse();
                    break;
            case 8: v1=player1.fourOfaKind();
                    v2=player2.fourOfaKind();
                    break;
            case 9: v1=player1.straightFlush();
                    v2=player2.straightFlush();
                    break;
            case 10:v1=player1.royalFlush();
                    v2=player2.royalFlush();
                    break;
          }          
          if(v1>v2)
             cout<<"\nPlayer 1 wins!";
           else 
             cout<<"\nPlayer 2 wins!";

      }      
  return 0;
}  