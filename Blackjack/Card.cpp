// LinkedList.cpp
// Written by : SENG1120 
// Written by : NI ZENG
// Modified   : 13/09/2020
// 
// 
// This file should be used in conjunction with ASSISSMENT 1 for SENG1120


#include "Card.h"

#include <cstdlib>
#include <iostream>
#include <string>

int Card::assignValue()
{
	if (m_card == 'A')         return 11;
	if (m_card == '2')         return 2;
	if (m_card == '3')         return 3;
	if (m_card == '4')         return 4;
	if (m_card == '5')         return 5;
	if (m_card == '6')         return 6;
	if (m_card == '7')         return 7;
	if (m_card == '8')         return 8;
	if (m_card == '9')         return 9;

	// T = 10, assign 10 to char T.
	else if (m_card == 'T')         return 10;
	else if(m_card == 'J'	|| m_card == 'Q' ||  m_card == 'K')
		return 10;
	
}

Card::Card()
{
	m_card = ' ';
	value = 0;
	m_suite = 0;
	faceUp = false;
}
Card::Card(char cardValue, int cardSuite)
{

	m_card = cardValue;
	value = assignValue();
	m_suite = cardSuite;
	faceUp = false;
//	face = std::to_string(getCard()) ;
	
}

Card::Card(const Card& card)
{
	m_card = card.getCard();
	value = card.getValue();
	m_suite = card.getSuite();
//	face = card.getName();
	faceUp = card.getifFaceup();
}

Card::~Card()
{
	m_card = NULL;
	value = 0;
	m_suite = NULL;
	
	faceUp = false;

}

int Card::getValue() const
{
	return value;
}

int Card::getSuite() const
{
	return m_suite;
}

std::string Card::getName() 
{

	switch (m_suite)	//0 spades, 1 clubs, 2 hearts, 3 diamonds
	{
	case 0: face = "-S"; break;	// Spades;
	case 1: face = "-C"; break;	// Clubs;	
	case 2: face = "-H"; break;	// Hearts;
	case 3: face = "-D";		// Diamonds;
	}
	face = getCard()+face;

	return face;
}

bool Card::getifFaceup() const
{
	
	return faceUp;
}

char Card::getCard() const
{
	return m_card;
}

void Card::setFaceUp(bool x)
{
	faceUp = x;

	// card.setFaceUp(true); // turn the card up
	// card.setFaceUp(false); // turn the card down
}

void Card::nameCard()
{
	// name all the cards.
	if (m_card == 'A')       std::cout << "A";
	else if (m_card == 'T')	std::cout << "10";
	else if (m_card == 'J') std::cout << "J";
	else if (m_card == 'Q') std::cout << "Q";
	else if (m_card == 'K') std::cout << "K";
	else                    std::cout << value;

	switch (m_suite)	//0 spades, 1 clubs, 2 hearts, 3 diamonds
		{
		case 0: face = "S"; break;	// Spades;
		case 1: face = "C"; break;	// Clubs;	
		case 2: face = "H"; break;	// Hearts;
		case 3: face = "D";		// Diamonds;
		}
	std::cout << " - " << face << std::endl;
	
}

// overloaded cout << operator that outputs the value of the string.
std::ostream& operator << (std::ostream& out, const Card& c)
{
	
	out << c.getCard() << "-" << c.getSuite();
	return out;
}




