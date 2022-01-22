#include <iostream>
#include <cstdlib>
//macroguards
#ifndef _NIZENG_NODE_H 
#define _NIZENG_NODE_H 

template <class value_type>
class Node
{
public:
	// CONSTRAUCTOR
	Node(const value_type& value);

	// DESTRUCTOR
	~Node();
	//-----------------------MODIFICATION MEMBER FUNCTION---------------------------------------------------------		

	void set_data(const value_type& new_data);		//set card data into node;
	void set_next(Node* next_link);				//set next card data into node;
	void set_previous(Node* previous_link);			//set previous data into node ;
	void set_current(Node* current_link);	//set current card data as data;

	//CONSIANT MEMBER FUNCTION		
	value_type get_data() const;
	const Node* get_previous() const;
	const Node* get_next() const;
	const Node* get_current() const;

	//NON CONSIANT MEMBER FUNCTION		
	Node* get_next();
	Node* get_current();

	//private:
	value_type data; // member variables (should be private) 
	Node* next;
	Node* previous;
	Node* current;
};

//------------------------------------------------------------------------------------------------
#include "Node.hpp"

#endif //End macroguards.
