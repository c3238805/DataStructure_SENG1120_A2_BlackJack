
    template <class value_type>
    LinkedList<value_type>::LinkedList()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
        list_length = 0;
    }

    template <class value_type>
    LinkedList<value_type>::~LinkedList()
    {
        while (head != NULL)
            remove_from_head();
        tail = NULL;

    }
    template <class value_type>
    void  LinkedList<value_type>::add_to_tail(value_type& data)
    {
        Node<value_type>* newNode = new Node<value_type>(data); // very important to add <value_type>
        if (list_length == 0)
        {
            // list is empty
            newNode->next = newNode;
            head = newNode;
            tail = newNode;
            list_length = 1;
        }
        else {



            tail->set_next(newNode);
            newNode->set_previous(tail);

            //set the head_ptr to the new Node
            tail = newNode;

            //add 1 list to the list length 
            list_length++;

            //set to NULL
            newNode = NULL;
        }
    }
    template <class value_type>
    value_type  LinkedList<value_type>::remove_from_head()
    {

        //no action for empty list
        if (list_length == 0)
        {
            cout << "Queue is empty. Queue size: 0" << endl;
            exit(EXIT_FAILURE);
        }
        else if (list_length == 1)
        {

            head = NULL;
            tail = NULL;
            current = NULL;
            list_length--;
            //   exit(EXIT_FAILURE);
        }
        else
        {
            //make a temp_head_ptr and sent it as the current head_ptr
            Node<value_type>* temp_head_ptr = head;

            //rearrange the head_ptr for the list
            head = temp_head_ptr->get_next();

            //remove temp_head_ptr
            //delete temp_head_ptr;

            //remove the list length
            list_length--;

            //set temp_head back to NULL;
            temp_head_ptr = NULL;

            move_to_head();
            return current->get_data();
        }
    }


    template <class value_type>
    void  LinkedList<value_type>::move_to_head()
    {
        current = head;
    }

    template <class value_type>
    value_type  LinkedList<value_type>::get_current()
    {
        return current->get_data();
    }



