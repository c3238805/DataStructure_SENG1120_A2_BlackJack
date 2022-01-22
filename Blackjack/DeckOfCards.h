// DeckOfCards.h
// Written by : SENG1120 Student c3238805
// Written by : NI ZENG
// Modified   : 21/10/2020
// 
// This file should be used in conjunction with Assignment 2 for SENG1120.
#ifndef _DECK_H_
#define _DECK_H_

#include <vector>
#include "Card.h"
#include "Queue.h"

class DeckOfCards
{
public:
    DeckOfCards();  //CONSTRAUCTION
//    ~DeckOfCards(); //DESTRUCTOR

//-------------------------------------------------------------------------------

    void fillDeck();
    void shuffle();
    void print(std::ostream& out);
    Card draw();



private:
    Queue<Card>* deck;

};

std::ostream& operator << (std::ostream& cout, Queue<string>& q);

std::ostream& operator << (std::ostream& cout, DeckOfCards& d);
#endif

