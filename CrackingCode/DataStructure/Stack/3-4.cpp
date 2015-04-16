#include <iostream>
#include <new>
#include <cstring>
#include <vector>


using namespace std;

struct Stack {

  vector<int*> buffer;

  void push(int value) {
    buffer.push_back(new int(value));
    cout << "push " << value << endl;
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
    cout << "Tower: " << this << endl;
    for (int i = buffer.size() - 1; i >= 0; i--) {
      cout << *buffer[i] << endl;
    }
    cout << "=====" << endl;
  }
};

void move(Stack *source, Stack *dest){
  int* temp = source->pop();
  dest->push(*temp);
  cout << "move " << *temp << " from " << source << " to " << dest << endl;
}

void honoi(int N, Stack *source, Stack *temp, Stack *dest) {
  if (N == 1) {
    move(source, dest);
    return;
  }
  honoi(N-1, source, dest, temp);
  move(source, dest);
  honoi(N-1, temp, source, dest);
}

int main() {

  /*Stack s;
  for (int i = 0; i < 5; i++) {
    s.push(i);
  }
  for (int i = 0; i < 6; i++) {
    int* ret = s.pop();
    if (ret != NULL) {
      cout << "pop out " << *ret << endl;
    }
    }*/
  int N;
  cin >> N;

  Stack source, dest, temp;
  for (int i = N; i > 0; i--) {
    source.push(i);
  }
  source.print();
  honoi(N, &source, &temp, &dest);
  source.print();
  dest.print();

  return 0;
}
