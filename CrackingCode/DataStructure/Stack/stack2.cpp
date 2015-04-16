#include <iostream>
#include <cstdlib>
#include <new>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

template <class T>
struct Node {
  T value;
  Node* next;

  Node(T _value){
    value = _value;
    next = NULL;
  }

  
  void addNode(T newValue){
    Node *cur = this;
    Node *newNode = new Node(newValue);

    while(cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = newNode;
    cout << "add " << newValue << endl;
    return;
  }


  void print(){

    cout << value << " addr: " << this << endl; 
    Node* ptr = next;
    while(ptr != NULL)
    {
      cout << ptr->value << " addr: " << ptr << endl;
      ptr = ptr->next;
    }
    cout << endl;
  }

};


int main() {

  Node<char>* head = new Node<char>('0');
  head->addNode('1');
  head->addNode('2');
  head->addNode('3');
  head->addNode('4');

  head->print();

  return 0;
}
