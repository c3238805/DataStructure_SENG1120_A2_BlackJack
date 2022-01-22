#include "DeckOfCards.h"
#include "Card.h"
#include "Queue.h"

#include <iostream>
#include <cstdlib>

#include <string>
#include "DeckOfCards.h"



DeckOfCards::DeckOfCards()
{
    //Initialize the deck: 
    deck = new Queue<Card>();
    fillDeck();
    shuffle();
}

void DeckOfCards::fillDeck()
{
    
    for (int i = 1; i <= 13; ++i)
    {
        char c;
        switch (i) {
        case 1:  c = 'A'; break;
        case 2:  c = '2'; break;
        case 3:  c = '3'; break;
        case 4:  c = '4'; break;
        case 5:  c = '5'; break;
        case 6:  c = '6'; break;
        case 7:  c = '7'; break;
        case 8:  c = '8'; break;
        case 9:  c = '9'; break;
        case 10:  c = 'T'; break;
        case 11:  c = 'J'; break;
        case 12:  c = 'Q'; break;
        case 13:  c = 'K';
        }
               
        for (int n = 0; n <= 3; n++)
        {
            Card* poker_card = new Card(c, n);  // create all 52 cards.

            deck->enqueue(*poker_card);     // input all cards into deck queue.
        }
        
    }        
}

void DeckOfCards::shuffle()
{

	Queue<Card>* group1 = new Queue<Card>();
	Queue<Card>* group2 = new Queue<Card>();
	Queue<Card>* group3 = new Queue<Card>();
	Queue<Card>* group4 = new Queue<Card>();

	for (int i=0; i<=12; i++)
	{
	   
    group1->enqueue(deck->front());
    deck->dequeue();
    
	}
    
    for (int i = 0; i <= 12; i++)
    {

        group2->enqueue(deck->front());
        deck->dequeue();

    }
    
    for (int i = 0; i <= 12; i++)
    {

        group3->enqueue(deck->front());
        deck->dequeue();

    }
     
    for (int i = 0; i <= 12; i++)
    {

        group4->enqueue(deck->front());
        deck->dequeue();

    }

    for (int i = 0; i <= 1000; i++) {
        int group = rand() % 4 + 1;
        switch (group)
        {
        case 1:
            if (group1->size() > 1)
            {
                group3->enqueue(group1->front());
                group1->dequeue();
                break;
            }
            else
                break;
        case 2:
            if (group2->size() > 1) 
            {
                group4->enqueue(group2->front());
                            group2->dequeue();
                            break;
            }
            else
                break;
        case 3:
            if (group3->size() > 1) 
            {
                group1->enqueue(group3->front());
                group3->dequeue();
                break;
            }
            else
                break;
        case 4:
            if (group4->size() > 1) 
            {
                group2->enqueue(group4->front());
                group4->dequeue();
                break;
            }
            else
                break;
        }
    }

   while (group1->size()>0)
   {
    deck->enqueue(group1->front());
    group1->dequeue();
   }
   
   while (group2->size() > 0)
   {
       deck->enqueue(group2->front());
       group2->dequeue();
   }
   while (group3->size() > 0)
   {
       deck->enqueue(group3->front());
       group3->dequeue();
   }
   while (group4->size() > 0)
   {
       deck->enqueue(group4->front());
       group4->dequeue();
   }

}



Card DeckOfCards::draw()
{             
        return deck->dequeue();

}


ostream& operator << (ostream& out, DeckOfCards& d )
{
    d.print(out);
    return out;
}


void DeckOfCards::print(std::ostream& out)
{

    out << *deck;

}