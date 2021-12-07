//Name: Jared Hazel
//Class: CSS501
//Purpose: to build a deque queue 

template <class Object>
Deque<Object>::Deque( ) {                          // the constructor
  front = back = NULL;
}

template <class Object>
Deque<Object>::Deque( const Deque &rhs ) {         // the copy constructor
  front = back = NULL;
  *this = rhs;
}

template <class Object>
Deque<Object>::~Deque( ) {                         // the destructor
  clear( );
}

template <class Object>
bool Deque<Object>::isEmpty( ) const {             // check if a deque is empty
  return front == NULL;
}

template <class Object>
int Deque<Object>::size( ) const {                 // retrieves # deque nodes
  int i = 0;
  for ( DequeNode *ptr = front; ptr != NULL; ptr = ptr->next ) // traverse que
    ++i;

  return i;
}

template <class Object>
const Object &Deque<Object>::getFront( ) const {   // retrieve the front node
  if ( isEmpty( ) )
    throw "empty queue";
  return front->item;
}

template <class Object>
const Object &Deque<Object>::getBack( ) const {    // retrieve the tail node
  if ( isEmpty( ) )
    throw "empty queue";
  return back->item;
}

template <class Object>
void Deque<Object>::clear( ) {          // clean up all entries.
  while ( !isEmpty( ) )                 // dequeue till the queue gets empty.
    removeFront( );
}
//This method adds a new front to the deque
//If it's the only node, then it's both back and front
template <class Object>
void Deque<Object>::addFront( const Object &obj ) {

  DequeNode *newNode = nullptr;
  newNode = new DequeNode;
  DequeNode *temp = front;

  if(newNode == NULL){
    throw "Error";
  }
  newNode->item = obj;
  newNode->prev = NULL;
  if(isEmpty()){
    back = newNode;
  }
  else{
    newNode->next = temp;
    temp->prev = newNode;
  }
  front = newNode;
}

//This method adds a new back to the deque
//If it's the only node, then it's both back and front
template <class Object>
void Deque<Object>::addBack( const Object &obj ) { 

  DequeNode *newNode = nullptr;
  newNode = new DequeNode;

  if(newNode == NULL){
    throw "Error";
  }
  newNode->item = obj;
  newNode->next = NULL;
  if(isEmpty()){
    front = newNode;
  }
  else{
    back->next = newNode;
    newNode->prev = back;
  }
  back = newNode;
}

//This method removes the front node and makes the next node the front
//If removing the only node, then both front and back become NULL
template <class Object>
Object Deque<Object>::removeFront( ) {  // remove the front node

Object returnValue = getFront();

DequeNode *old = front;
if(front == back){
  front = NULL;
  back = NULL;
}
else{
  front = front->next;
}
delete old;
return returnValue;
}

//This method removes the back node and makes the prev node the back
template <class Object>
Object Deque<Object>::removeBack( ) {   // remove the tail node

Object returnValue = getBack();

DequeNode *old = back;
if(front == back){
  front = NULL;
  back = NULL;
}
else{
  back = back->prev;
}
delete old;
return returnValue;
}

template <class Object>
const Deque<Object> &Deque<Object>::operator=( const Deque &rhs ) { // assign
  if ( this != &rhs ) { // avoid self assignment
    clear( );
    for ( DequeNode *rptr = rhs.front; rptr != NULL; rptr = rptr->next )
      addBack( rptr->item );
  }
  return *this;
}


