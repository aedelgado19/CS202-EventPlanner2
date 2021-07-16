/* Author: Allison Delgado
   Class: CS202 Spring 2021
   This file contains the member functions for the
   data structure classes (A_Node, C_Node, Array, and CLL).
   These data structures are meant to hold the different 
   Event types. The Beach class is represented in a vector,
   the Shopping class is an array of LLL's, and the Restaurant
   class is a CLL.

   Last updated: July 13, 2021
*/

#include "Nodes.h"

// ********************* A_NODE FUNCTIONS *******************

//constructor
A_Node::A_Node(){
  next = nullptr;
}

//constructor to copy over the Shopping data
A_Node::A_Node(const Shopping & source) {
  next = nullptr;
}

//move through the array of LL
A_Node *& A_Node::go_next(){
  return next;
}

//set the next node
void A_Node::set_next(A_Node* node){
  next = node;
}

//hash based on size of items and stores in vector and name of event
int A_Node::hash(int size){
  return (int) pow((stores.size() + what_to_buy.size()), strlen(name)) % size;
}

// ********************* ARRAY FUNCTIONS *******************

//constructor with args
Array::Array(int s){
  size = s;
  head = new A_Node*[size];
  for(int i = 0; i < size; i++){
    head[i] = nullptr;
  }
}

//copy constructor
Array::Array(const Array & source){
  size = source.size;
  head = new A_Node*[size];
  
  for(int i = 0; i < size; i++){
    head[i] = new A_Node(*(source.head[i]));
    A_Node * cur = head[i];
    A_Node * ptr = source.head[i];
    while(ptr){
      cur = new A_Node(*ptr);
      cur = cur->go_next();
      ptr = ptr->go_next();
    }
  }
}

//destructor
Array::~Array(){
  for(int i = 0; i < size; i++){
    A_Node * cur = head[i];
    while(cur->go_next()){
      A_Node * temp = cur->go_next();
      delete cur;
      cur = temp;
    }
    delete head[i];
    head[i] = nullptr;
  }
  delete [] head;
  head = nullptr;
}

//insert node wrapper
void Array::insert(A_Node *& to_add){
  int index = to_add->hash(size);
  insert(head[index], to_add);
}

//recursive insert
void Array::insert(A_Node *& current, A_Node *& to_add){
  if(!current){
    current = to_add;
    to_add->set_next(nullptr);
    return;
  }
  if(current->go_next()){
    insert(current->go_next(), to_add);
  } else {
    current->set_next(to_add);
    to_add->set_next(nullptr);
  }
}
  
//wrapper to remove a node
void Array::remove(A_Node *& to_remove){
  int index = to_remove->hash(size);
  if(!head[index]) return;
  remove(head[index], to_remove);
}

//recursive removal
void Array::remove(A_Node *& current, A_Node *& to_remove){
  if(current == to_remove){
    A_Node * temp = current->go_next();
    delete to_remove;
    current = temp;
  }
  else {
    remove(current->go_next(), to_remove);
  }
}


//wrapper to display the array of LLL
void Array::display(){
  display(0);
}

//recursive display
void Array::display(int index){
  if(head[index]){
    head[index]->Shopping::display();
    A_Node * temp = head[index]->go_next();
    while(temp){
      temp->Shopping::display();
      temp = temp->go_next();
    }
  }
  display(index + 1);
}


//wrapper to remove all nodes
void Array::remove_all(){
  A_Node * current = nullptr;
  for(int i = 0; i < size; i++){
    current = head[i];
    remove_all(current);
  }
}

//recursive remove all
void Array::remove_all(A_Node * current){
  if(!current) return;
  A_Node * hold = current->go_next();
  delete current;
  current = hold;
  remove_all(current);
}

// ******************* C_NODE FUNCTIONS **************

//constructor
C_Node::C_Node(){
  next = nullptr;
}

//constructor to copy restaurant details
C_Node::C_Node(const Restaurant & source) : Restaurant(source){
  next = nullptr;
}

//move through CLL
C_Node *& C_Node::go_next(){
  return next;
}

void C_Node::set_next(C_Node *& to_add){
  next = to_add;
}

// ********************** CLL FUNCTIONS *********************

//constructor
CLL::CLL(){
  rear = NULL;
}

//copy constructor
CLL::CLL(const CLL & source){
  cp(rear, source.rear, source.rear);
}

//recursive copy for copy constructor
void CLL::cp(C_Node *& cur, C_Node * source, C_Node * s_rear){
  if(source->go_next() == s_rear){ //last node
    cur = new C_Node(*source);
    cur->set_next(rear);
  } else { //all other nodes
    cur = new C_Node(*source);
    cp(cur->go_next(), source->go_next(), s_rear);
  }
}

//destructor
CLL::~CLL(){
  C_Node* cur = rear;
  while(cur->go_next() != rear){
    C_Node* temp = cur->go_next();
    delete cur;
    cur = temp;
  }
  delete rear;
  rear = nullptr;
}

//insert a node
void CLL::insert(Restaurant & to_add){
  C_Node * a = new C_Node(to_add);
  if(!rear){
    rear = a;
    a->set_next(rear);
  } else {
    C_Node * temp = rear->go_next()->go_next();
    rear->set_next(a);
    a->set_next(temp);
  }
}

//wrapper to remove a node
void CLL::remove(char* to_remove){
  std::string name = to_remove;
  remove(rear, name);
}

//remove the node whose name matches the one passed in
void CLL::remove(C_Node *& cur, std::string name){
  if(cur->go_next() != rear){
    if(cur->compare(name)){
      delete cur;
    }
  }
}

//wrapper to display all nodes
void CLL::display(){
  display(rear);
}

//recursive display
void CLL::display(C_Node* cur){
  if(cur->go_next() != rear){
    cur->Restaurant::display();
    display(cur->go_next());
  }
  cur->Restaurant::display();
}

//wrapper to remove all nodes
void CLL::remove_all(){
  remove_all(rear);
}

//remove all nodes
void CLL::remove_all(C_Node * cur){
  if(cur->go_next() != rear){
    C_Node * temp = cur->go_next();
    delete cur;
    cur = temp;
  }
}

