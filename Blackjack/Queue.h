
//macroguards
#ifndef _NIZENG_Queue_H 
#define _NIZENG_Queue_H 

#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

// define default capacity of the queue


template <class value_type>
class Queue
{
public:
    Queue();
    // Utility function to check if the queue is empty or not

    bool isEmpty();
    // Utility function to check if the queue is full or not

    bool isFull();

    ~Queue();


    void enqueue(value_type entry);    // Add obj to the rear of the queue
    value_type  dequeue(); // Remove and return the object at the head of the queue, error if the queue is empty.

    int size() const;
    value_type front(); //   Return a reference to the object at the front of
                        //   the queue, NULL if the queue is empty
    void print(std::ostream& out);

private:
    LinkedList<value_type> list;
    int count;      // current size of the queue
};
#include "Queue.hpp"

#endif //End macroguards.