#include <cstddef>
#include <new>


using namespace std;

template <class T>
struct LinkedNode {
  T value;
  LinkedNode* next;

  LinkedNode(T _value) {
    value = _value;
    next = NULL;
  }

};

template <class T>
struct Queue {

  LinkedNode<T> *front;
  LinkedNode<T> *back;

  Queue() {
    front = NULL;
    back = NULL;
  }

  void enqueue(T value){
    if (front == NULL) {
      front = new LinkedNode<T>(value);
      back = front;
      return;
    }
    back->next = new LinkedNode<T>(value);
    back = back->next;
  }
  T dequeue() {
    if (front == NULL) {
      cout << "Queue Underflow" << endl;
      return NULL;
    }
    T ret = front->value;
    front = front->next;
    return ret;
  }
  bool isEmpty() {
    return front == NULL ? true : false;
  }
};
