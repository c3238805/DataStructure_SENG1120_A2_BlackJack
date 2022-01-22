template <class value_type>
Queue<value_type>::Queue()
{
    list = LinkedList<value_type>();        // call linkedlist construtor.
    count = 0;
}


// Utility function to check if the queue is empty or not

template <class value_type>
bool Queue<value_type>::isEmpty()
{
    if (count == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Utility function to check if the queue is full or not

template <class value_type>
bool Queue<value_type>::isFull()
{
    if (count == 52) {
        return true;
    }
    else {
        return false;
    }
}

template <class value_type>
Queue<value_type>::~Queue()     // delete the queue
{
    // check if the queue empty
    if (isEmpty())
    {
        cout << "Queue is empty, nothing to be deleted";
        exit(EXIT_FAILURE);
    }
    while (list.current != NULL)
    {
        list.remove_from_head();
        --count;
    }

}


template <class value_type>
void Queue<value_type>::enqueue(value_type entry)     // Add obj to the rear of the queue
{
    // check for queue overflow
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        list.add_to_tail(entry);
        count++;
    }

}

template <class value_type>
value_type Queue<value_type>::dequeue()  // Remove and return the object at the head of the queue, error if the queue is empty.
{

    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        exit(EXIT_FAILURE);
    }
    else {
        --count;
        return list.remove_from_head();

    }

}


template <class value_type>
int Queue<value_type>::size() const
{

    return count;


}
template <class value_type>
value_type Queue<value_type>::front() //   Return a reference to the object at the front of
                    //   the queue, NULL if the queue is empty
{
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        exit(EXIT_FAILURE);
    }
    list.move_to_head();

    return list.get_current();

}

template <class value_type>
ostream& operator << (ostream& out, Queue<value_type>& q)
{
    q.print(out);
    return out;
}

template <class value_type>
void Queue<value_type>::print(std::ostream& out)
{

    out << list;

}
