#include "ll.h"

// ADD FUNCTIONS
void LL::addFront(int d){
 Node* newNode = new Node(d, head);
 if (head == nullptr)
 {
   head=newNode;
   tail=newNode;
   newNode->next = nullptr;
 }
 else
 {
   head = newNode;
 }
 length++;
};

void LL::addBack(int d){
  Node* newNode = new Node(d, nullptr);
  if (head == nullptr)
  {
    head=newNode;
    tail=newNode;
    newNode->next = nullptr;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }
  length++;
};

// DELETE FUNCTIONS
void LL::deleteFront(){
  if (head==nullptr) return;
  if (head->next==nullptr){ // only 1 item
    delete head;
    head=nullptr;
    tail=nullptr;
    length = 0;
    return;
  }

  Node* tmpptr = head->next;
  delete head;
  head = tmpptr;
  length--;
};

void LL::deleteBack(){
  if (head==nullptr)return;
  if (head->next == nullptr){ // only 1 item
    delete head;
    head = nullptr;
    tail = nullptr;
    length = 0;
    return;
  }

  Node* tmpptr = head;
  while (tmpptr->next!=tail)
    tmpptr = tmpptr->next;
  delete tail;
  tail = tmpptr;
  tail->next = nullptr;
  length--;
};

void LL::deleteAt(int i){
  if (head == nullptr) return;
  if (i >= length) return;
  if (i == 0) return deleteFront(); 
  if (i == length-1) return deleteBack();
  
  Node* curr = head;
  for (int j=0; j<i-1; j++){
    curr = curr->next;
  }

  Node* tmpnext = curr->next;
  Node* tmpafter = tmpnext->next;
  delete tmpnext;
  curr->next = tmpafter;

  length --;
};

// PRINT FUNCTIONS
void LL::print(){
  if (head == nullptr) return;
  
  std::cout <<'\n';
  std::cout << "Print from head: " << '\n';
  
  Node*curr = head;
  while (curr!=nullptr){
    
    std::cout << curr->data << '\n';
    curr=curr->next;
  }
};

void LL::printLength(){
  int len = 0;
  Node* curr = head;
  while (curr!=nullptr){
    len ++;
    curr=curr->next;
  }
  std::cout << '\n' << "Actual length of list: " << len << '\n' ;
  std::cout << "Length Value in list: " << length << '\n';
};