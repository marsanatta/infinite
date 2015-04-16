#include <iostream>
#include "BitManipulation.h"

using namespace std;

int main() {

  int n1 = 1;
  cout << intToBinaryString(n1) << endl;
  

  /*for (int i = 0; i <= 32; i++) {
    cout << "shifting " << i << " bit" << endl;
    n1 = n1 << i;
    cout << "value " << n1 << endl;
    cout << findIntFirstOnePos(n1) << " is the position of first one" << endl;
  }*/

  return 0;
}
