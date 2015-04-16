#include <iostream>

using namespace std;

int ReadNumber() {
  cout << "please enter a number:";
  int input;
  cin >> input;
  return input;
}

void WriteAnswer(int x) {
  cout << "the anser is " << x << endl;
}
