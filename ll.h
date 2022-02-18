#include <iostream>

struct Node{
  int data;
  Node* next = nullptr;
  Node() = delete;
  Node(int d, Node*n):data(d), next(n){};
  Node(int d):data(d), next(nullptr){};
};

class LL{
  private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;

  public:
    Node* gethead(){return head;};
    Node* gettail(){return tail;};
    
    void addFront(int d);
    void addBack(int d);

    void deleteFront();
    void deleteBack();
    void deleteAt(int i);

    void print();
    void printLength();
};