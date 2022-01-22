
//macroguards
#ifndef _NIZENG_LinkedList_H 
#define _NIZENG_LinkedList_H 

#include <iostream>
#include "Node.h"


using namespace std;

template <class value_type>
class LinkedList
{
public:
    LinkedList();

    ~LinkedList();

    void add_to_tail(value_type& data);
    value_type remove_from_head();
   
    void move_to_head();

    value_type get_current();

    size_t list_length;
    //private:
    Node<value_type>* head;         // and here too - very important to add <value_type>
    Node<value_type>* tail;
    Node<value_type>* current;
};

template <typename value_type>
ostream& operator << (ostream& out, const LinkedList<value_type>& ll)
{
    Node<value_type>* current = ll.head;
    while (current != NULL) { // traverses the linked list until the last element
        out << current->data << "  "; // prints the content of node pointed to by current
        current = current->next; // goes to the next node
    }
    
    return out;
}
#include "LinkedList.hpp"
#endif //End macroguards.