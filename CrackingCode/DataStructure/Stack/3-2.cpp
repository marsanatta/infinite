#include <iostream>
#include <cstring>
#include <new>

#define STACK_SIZE 10

using namespace std;

class Stack {

public:
  int top;
  int* buffer[STACK_SIZE];

  Stack() {
    top = -1;
    memset(buffer, 0, STACK_SIZE * sizeof(int*));
  }

  void push(int value) {
    if (top + 1 + 1 > STACK_SIZE) {
      cout << "Stack Overflow" << endl;
      return;
    }

    if (top == -1) {
      top = 0;
    }
    else {
      top++;
    }
    buffer[top] = new int(value);
    cout << "push " << value << endl;
    return;
  }

  int* pop() {
    if (top == -1) {
      cout << "Stack Underflow" << endl;
      return NULL;
    }
    int* ret = buffer[top];
    top--;
    cout << "pop " << *ret << endl;
    return ret;
  }

  int peak() {
    if (top == -1) {
      cout << "Empty Stack" << endl;
      return top;
    }
    else {
      return *buffer[top];
    }
  }

};

class minStack : private Stack {

private:
  Stack minStack;

public:
  void push(int value) {
    if (top == -1) {
      minStack.push(value);
      Stack::push(value);
      return;
    }
    
    if (value < min()) {
      minStack.push(value);
    }
    Stack::push(value);
  }

  int* pop() {
    if (peak() == min() && top != -1) {
      minStack.pop();
    }
    int* ret = Stack::pop();
    return ret;
  }

  int min() {
    if (top == - 1) {
      cout << "Empty Stack No Min" << endl;
      return -1;
    }
    return minStack.peak();
  }
};

int main() {

  minStack s;
  s.push(10);
  cout << "min: " << s.min() << endl;
  s.push(3);
  cout << "min: " << s.min() << endl;
  s.push(12);
  cout << "min: " << s.min() << endl;
  s.push(2);
  cout << "min: " << s.min() << endl;
  s.push(5);
  cout << "min: " << s.min() << endl;
  s.push(7);
  cout << "min: " << s.min() << endl;

  for (int i = 0; i < 6; i++) {
    s.pop();
    cout << "min: " << s.min() << endl;
  }

  return 0;
}
