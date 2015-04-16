#include <iostream>
#include "7-1.h"

using namespace std;

int main() {

  Card c(12, Card::DIAMONDS);
  BlackJackCard bjc(12, Card::DIAMONDS);
  cout << c.getPoint() << endl;
  cout << bjc.getPoint() << endl;
  return 0;
}
