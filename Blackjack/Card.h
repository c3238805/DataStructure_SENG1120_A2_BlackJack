// Card.h
// Written by : SENG1120 Student c3238805
// Written by : NI ZENG
// Modified   : 21/10/2020
// Define a class Card . 
// This file should be used in conjunction with Assignment 2 for SENG1120.

//macroguards

#ifndef _CARD_H_
#define _CARD_H_
#include <string>


class Card
{
public:

    typedef std::string value_type; // Name type 'std::string' to 'value_type'.

    //CONSTRAUCTION
    Card();
    Card(char cardValue, int cardSuite);
    Card(const Card&);
    //DESTRUCTOR
    ~Card();

    //-------------------------------------------------------------------------------
    int getValue() const;
    int getSuite()        const;
    value_type getName();    //string type e.g. ¡°10-H¡± (for 10 of hearts);
    void nameCard();
    char getCard() const;   //  'A' ,'2', '3', '4', '5', '6', '7', '8', '9','T', 'J', 'Q', 'k'

    void setFaceUp(bool x);
    bool getifFaceup() const;  //check if card is face up


private:
    char m_card;         //  'A'   ,'2', '3', '4', '5', '6', '7', '8', '9', 'T','J', 'Q', 'k'
    int value;   //1 or 11 , 2  , 3  ,  4,   5 ,  6 ,  7 ,  8 ,  9,  10, 10,  10
    int m_suite;             //0 spades, 1 clubs, 2 hearts, 3 diamonds
    value_type face; // face will store the string, e.g. 10-H (for 10 of hearts);

    bool faceUp; //Check if it's been wether faceUp or not.
    int assignValue();

};

//make a function for ostream so that we get <<string<< output.
std::ostream& operator << (std::ostream& out, const Card& l);
#endif
