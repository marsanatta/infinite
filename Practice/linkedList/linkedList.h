#include <cstddef>
#include <iostream>

class Node {
private:
  int value;
  Node *next;
public:

  Node(int value) :
  value(value), next(NULL)
  {

  }

  int getValue() const {
    return value;
  }
  Node* getNext() const {
    return next;
  }
  void setValue(int value) {
    this->value = value;
  }
  void setNext(Node* next) {
    this->next = next;
  }
};

class LinkedList {

private:
  Node* head;
public:
  LinkedList():
  head(NULL)
  {
  }

  void add(int newValue) {
    if (head == NULL)
      head = new Node(newValue);
    else {
      Node* cur = head;
      while (cur->getNext() != NULL) {
        cur = cur->getNext();
      }
      cur->setNext(new Node(newValue));
    }
  }

  bool del(int delValue) {
    Node* cur = head;
    while(cur->getNext() != NULL) {
      if(cur->getNext()->getValue() == delValue) {
        Node* delNode = cur->getNext();
        cur->setNext(cur->getNext()->getNext());
        delete delNode;
        return true;
      }
      cur = cur->getNext();
    }
    return false;
  }

  void print() {
    Node* cur = head;
    while (cur != NULL) {
      std::cout << cur->getValue() << " ";
      cur = cur->getNext();
    }
    std::cout << std::endl;
  }

};
