
#include "HandOfCards.h"
#include "DeckOfCards.h"
#include "Queue.h"
#include "Card.h"

HandOfCards::HandOfCards()
{
	hand = new Queue<Card>();


}
// ~HandOfCards() //DESTRUCTOR
//{

//}

//-------------------------------------------------------------------------------

int HandOfCards::count()   // counts the value of the hand stored in the list (but only the cards facing up).
{
	int count = 0;

	for (int i = 0; i < hand->size(); i++)
	{
		Card temp = hand->front();
		Card hold = hand->dequeue();
		if (temp.getifFaceup() == true)
		{
			count += temp.getValue();

		}
		hand->enqueue(temp);
	}
	return count;

}


int HandOfCards::countAll() //counts the value of the hand stored in the list (all cards facing both up and down)
{
	int count = 0;

	for (int i = 0; i < hand->size(); i++)
	{
		Card temp = hand->front();
		Card hold = hand->dequeue();
		
		count += temp.getValue();
							
		hand->enqueue(temp);
	}
	return count;
}

string HandOfCards::value() //Face-down cards must be displayed with ?-??symbol.
{
	std::string sequence;
	std::string points;
	int count = 0;

	for (int i=0; i< hand->size();i++)
	{
		Card temp = hand->front();
		Card hold = hand->dequeue();
		if (temp.getifFaceup() == true)
		{
			sequence += temp.getName() +" ";
			count += temp.getValue();
			points = "("+to_string(count)+" points"+")";
		}
		else if (temp.getifFaceup() == false)
		{
			
			sequence += "?-? ";
		}

		hand->enqueue(temp);
	}
	
	return sequence + points;
}

void HandOfCards::faceUp()  //makes all cards in the hand face-up.
{
	for (int i = 0; i < hand->size(); i++)
	{
		Card temp = hand->front();
		Card hold = hand->dequeue();

		temp.setFaceUp(true);
		hand->enqueue(temp);
	}
}


void HandOfCards::add(Card c, bool x)
{

	c.setFaceUp(x);	
	hand->enqueue(c);
	
}



ostream& operator << (ostream& out, HandOfCards& d)
{
	
	d.print(out);
	return out;
}


void HandOfCards::print(std::ostream& out)
{
	
	out << value()  ;
	
	
}


