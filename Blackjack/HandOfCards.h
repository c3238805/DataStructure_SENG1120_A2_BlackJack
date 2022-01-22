
// HandOfCards.h
// Written by : SENG1120 Student c3238805
// Written by : NI ZENG
// Modified   : 21/10/2020
// 
// This file should be used in conjunction with Assignment 2 for SENG1120.
#include "Card.h"
#include "Queue.h"

#ifndef _HANDOFCARDS_H_
#define _HANDOFCARDS_H_


class HandOfCards
{
public:
    HandOfCards();  //Constructor
//  ~HandOfCards(); //DESTRUCTOR

//-------------------------------------------------------------------------------
    int count();    // counts the value of the hand stored in the list (but only the cards facing up). 
    int countAll(); //counts the value of the hand stored in the list (all cards facing both up and down)

    string value(); //Face-down cards must be displayed with ?-??symbol.
    void faceUp();  //makes all cards in the hand face-up.
    void add(Card, bool faceUp);    //takes a single Card and a boolean arguments and adds the card in HandOfCards, either facing - up(true) or down(false).

    void print(std::ostream& out);// For overload << to print out.




private:

    Queue<Card>* hand;


};

std::ostream& operator << (std::ostream& cout, Queue<string>& q);

std::ostream& operator << (std::ostream& cout, HandOfCards& d);

#endif

