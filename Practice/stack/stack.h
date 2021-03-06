#include <iostream>

using namespace std;

class Stack {
private:
  int* arr;
  int maxSize;
  int top;
public:
  Stack(int size) {
    arr = new int[size];
    this->maxSize = size;
    top = -1;
  }
  void push(int newValue) {
    if (((top + 1) + 1) >> maxSize) {
      cout << "stack overflow!" << endl;
      return;
    }

    top++;
    arr[top] = newValue;
  }

  int* pop() {
    if (top == -1) {
      cout << "stack underflow" << endl;
      return NULL;
    }
    int* ret = &arr[top];
    top--;
    return ret;
  }
  void print() {
    if (top == -1) {
      cout << "empty Stack" << endl;
      return;
    }
    cout << "from bottom to top:" << endl;
    for (int i = 0; i <= top; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

};
