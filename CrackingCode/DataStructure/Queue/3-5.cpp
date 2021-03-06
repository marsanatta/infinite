#include <iostream>
#include <vector>

using namespace std;

struct Stack{
  
  vector<int*> buffer;

  void push(int value) {
    buffer.push_back(new int(value));
  }

  int* pop() {
    if (buffer.size() == 0) {
      cout << "Stack Underflow" << endl;
      return NULL;
    }
    int* ret = buffer.back();
    buffer.pop_back();
    return ret;
  }

  
  void print() {
    cout << "print stack:" << endl;
    for (int i = buffer.size() - 1; i >= 0; i--) {
      cout << *buffer[i] << endl;
    }
    cout << "============" << endl;
  }

  int size(){
    return buffer.size();
  }
};

struct TwoStackQueue{
  
  Stack inStack;
  Stack outStack;

  void enqueue(int value) {
    inStack.push(value);
    cout << "eneuque " << value << endl;
  }

  int* dequeue() {

    if (outStack.size() == 0) {
      while(inStack.size() != 0) {
        int* temp = inStack.pop();
        outStack.push(*temp);
      }
    }
    if (outStack.size() == 0) {
      cout << "Queue Underflow" << endl;
      return NULL;
    }
    return outStack.pop();
  }
};

int main() {

  TwoStackQueue q;
  
  for (int i = 0; i < 5; i++) {
    q.enqueue(i);
  }
  for (int i = 0; i < 3; i++) {
    int* ret = q.dequeue();
    if(ret != NULL)
      cout << *ret << endl;
  }
  q.enqueue(200);
  q.enqueue(300);
  for (int i = 0; i < 5; i++) {
    int* ret = q.dequeue();
    if(ret != NULL)
      cout << *ret << endl;
  }
 

  return 0;
}
