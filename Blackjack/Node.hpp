

template <class value_type>
Node<value_type>::Node(const value_type& value)
{
	data = value; next = NULL;
}

template <class value_type>
Node<value_type>::~Node()
{
	data = NULL;
	next = NULL;
	previous = NULL;
	current = NULL;
}

template <class value_type>
void Node<value_type>::set_data(const value_type& new_data) { data = new_data; }		//set card data into node;

template <class value_type>
void Node<value_type>::set_next(Node* next_link) { next = next_link; }					//set next card data into node;

template <class value_type>
void Node<value_type>::set_previous(Node* previous_link) { previous = previous_link; }			//set previous data into node ;

template <class value_type>
void Node<value_type>::set_current(Node* current_link) { current = current_link; }			//set current card data as data;

template <class value_type>
value_type Node<value_type>::get_data() const { return data; }



template<class value_type>
const Node<value_type>* Node<value_type>::get_previous() const { return previous; }

template<class value_type>
const Node<value_type>* Node<value_type>::get_next() const { return next; }

template<class value_type>
const Node<value_type>* Node<value_type>::get_current() const { return current; }


//NON CONSIANT MEMBER FUNCTION	
template<class value_type>
Node<value_type>* Node<value_type>::get_next() { return next; }

template<class value_type>
Node<value_type>* Node<value_type>::get_current() { return current; }

