#include <iostream>
#include <new>

using namespace std;

template <class T>
struct Node {
  
  T value;
  Node* next;

  Node(T _value) {
    value = _value;
    next = NULL;
  }

};

template <class T>
struct Queue {

  Node<T>* front;
  Node<T>* back;

  Queue() {
    front = NULL;
    back = NULL;
  }

  Node<T>* dequeue() {
    if (front != NULL) {
      Node<T>* ret = front;
      front = front->next;
      return ret;
    }
    else{
      return NULL;
    }
  }

  void enqueue(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (front != NULL) {
      back->next = newNode;
    }
    else {
      front = newNode;
    }
    back = newNode;
  }

};

int main() {

  Queue<int> queue;
  
  int n = 5;
  
  for (int i = 0; i < n; i++) {
    queue.enqueue(i);
  }

  for (int i = 0; i < n; i++) {
    cout << queue.dequeue()->value << endl;
  }
  Node<int>* node = queue.dequeue();
  if (node == NULL) {
    cout << "already empty!" << endl;
  }
  node = queue.dequeue();
  if (node == NULL) {
    cout << "already empty!" << endl;
  }


  return 0;
}
