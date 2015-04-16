#include <iostream>
#include <cstring>
#include <new>

#define STACK_SIZE 10

using namespace std;

struct FixedOneArrayStack {

  int stackTop[3];
  int* buffer[3 * STACK_SIZE];

  FixedOneArrayStack() {
    for (int i = 0; i < 3; i++) {
      stackTop[i] = -1;
    }
    for (int i = 0; i < 3 * STACK_SIZE; i++) {
      buffer[i] = NULL;
    }
  }

  void push(int stackNo, int value) {


    if (stackTop[stackNo] + 1 == STACK_SIZE) {
      cout << "Stack Overflow" << endl;
      return;
    }
    if (stackTop[stackNo] == -1) {
      stackTop[stackNo] = 0;
      int index = stackNo * STACK_SIZE;
      buffer[index] = new int(value);
    }
    else {
      stackTop[stackNo]++;
      int index = stackNo * STACK_SIZE + stackTop[stackNo];
      buffer[index] = new int(value);
    }
    cout << "push value: " << value << " to stack " << stackNo << endl;
    return;
  }

  int* pop(int stackNo) {
    
    if (stackTop[stackNo] == -1) {
      cout << "Stack Underflow" << endl;
      return NULL;
    }
    else {
      int index = stackTop[stackNo] + STACK_SIZE * stackNo;
      int* ret = buffer[index];
      buffer[index] = NULL;
      stackTop[stackNo]--;
      cout << "pop from stack " << stackNo << " value: " << *ret << endl;
      return ret;
    }
  }

};

struct Node {
  int value;
  int prev;

  Node(int _value, int _prev) {
    value = _value;
    prev = _prev;
  }
};


struct DynamicOneArrayStack {
  
  int stackTop[3];
  int bufferUsed;
  Node* buffer[3 * STACK_SIZE];

  DynamicOneArrayStack() {
    bufferUsed = 0;
    memset(stackTop, -1, sizeof(int) * 3);
  }

  void push(int stackNo, int value) {

    if (stackTop[stackNo] + 1 > STACK_SIZE) {
      cout << "Stack Overflow" << endl;
      return;
    }

    stackTop[stackNo] = bufferUsed;
    if (stackTop[stackNo] == -1) {
      buffer[bufferUsed] = new Node(value, -1);
    }
    else {
      int prev = stackTop[stackNo];
      buffer[bufferUsed] = new Node(value, prev);
    }
    bufferUsed++;
  }

  int* pop(int stackNo) {
    if (stackTop[stackNo] == -1) {
      cout << "Stack Underflow" << endl;
      return NULL;
    }
    else {
      int* ret = &(buffer[stackTop[stackNo]]->value);
      stackTop[stackNo] = buffer[stackTop[stackNo]]->prev;
      buffer[stackTop[stackNo]] = NULL;
      bufferUsed--;
      return ret;
    }
  }
};


int main() {
  
  FixedOneArrayStack s;
  for (int i = 0; i < 3; i++) {
    for (int j = i*10; j < i*10 + 5; j++) {
      s.push(i, j);
    }
  }
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      s.pop(i);
    }
  }
  

  for (int i = 0; i < STACK_SIZE+5; i++) {
    s.push(0, i);
  }
  for (int i = 0; i < STACK_SIZE+5; i++) {
    s.pop(0);
  }

  return 0;
}
