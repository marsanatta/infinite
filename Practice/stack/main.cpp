#include <iostream>
#include "stack.h"

int main() {

  Stack s(10);
  s.push(1);
  s.push(45);
  s.push(70);
  s.print();
  s.pop();
  s.print();
  s.pop();
  s.print();
  s.pop();
  s.print();
  s.pop();
  return 0;
}
