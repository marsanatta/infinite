#include <iostream>
#include <cstring>
#include <new>
#include <vector>

#define STACK_SIZE 2

using namespace std;

class Stack {

private:
  int top;
  int* buffer[STACK_SIZE];

public:
  Stack() {
    top = -1;
    for (int i = 0; i < STACK_SIZE; i++) {
      buffer[i] = NULL;
    }
  }

  void push(int value) {
    if (top + 1 + 1 > STACK_SIZE) {
      cout << "Stack Overflow" << endl;
      return;
    }
    top++;
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
    buffer[top] = NULL;
    top--;
    return ret;
  }
  
  int* pop_back() {
    if (top == -1) {
      cout << "Stack Underflow" << endl;
      return NULL;
    }
    int* ret = buffer[0];
    for (int i = 0; i < top; i++) {
      buffer[i] = buffer[i+1];
    }
    buffer[top] = NULL;
    top--;
    return ret;
  }

  int getTop() {
    return top;
  }
  void setTop(int _top) {
    top = _top;
  }
};

struct SetOfStacks {
  
  vector<Stack*> stacks;

  SetOfStacks() {
    stacks.push_back(new Stack);
  }

  Stack* getLastStack() {
    if (stacks.size() == 0) {
      return NULL;
    }
    return stacks.back();
  }

  void push(int value) {
    
    Stack *s = getLastStack();

    if (s->getTop() + 1 + 1 > STACK_SIZE) {
      Stack *newS = new Stack;
      cout << "creating new stack " << newS << endl;
      newS->push(value);
      stacks.push_back(newS);
      return;
    }
    s->push(value);
  }

  int* pop() {
  
    Stack *s = getLastStack();

    if (s->getTop() == -1) {
      //already last empty stack
      if (stacks.size() == 1) {
        cout << "Stack Underflow" << endl;
        return NULL;
      }
      stacks.pop_back();
      s = getLastStack();
    }
    cout << "pop from " << s << " " << endl;
    return s->pop();
  }

  int* popAt(int no) {
    if (no + 1 > stacks.size()) {
      return NULL;
    }
  
    if (no + 1 == stacks.size()) {
      return pop();
    }
    int* ret = stacks[no]->pop();
    cout << "pop at " << no << " :" << *ret << endl;
    //push bottom of next stack to current stack
    while(no + 1 < stacks.size()){
      int* bot = stacks[no+1]->pop_back();
      if (bot == NULL) {
        stacks.erase(stacks.begin()+no+1);
        break;//it means there's nothing left
      }
      stacks[no]->push(*bot);
      cout << "shifiting " << *bot << " from " << no+1 << "'s bot to " << no << "'s top" << endl;
      no++;
    }
    return ret;
  }

};

int main() {

  SetOfStacks s;

  for(int i = 0; i < 6; i++) {
    s.push(i);
  }
  s.popAt(0);
  s.popAt(1);
  s.popAt(0);
  for(int i = 0; i < 7; i++) {
    int* ret = s.pop();
    if(ret != NULL)
      cout << *ret << endl;
  }

  return 0;
}
