#include <iostream>
#include "BitManipulation.h"

using namespace std;

int countChanges(int n1, int n2) {
  int difference = n1 ^ n2;
  int oneCounts = 0;
  /*for (int i = 0; i < 32; i++) {
    if (getBit(difference, i)) 
      oneCounts++;
      }*/
  while(difference != 0) {
    if ((difference & 1) == 1) {
      oneCounts++;
    }
    difference >>= 1;
  }
  return oneCounts;
}

int main() {

  int n1, n2;
  cin >> n1;
  cin >> n2;
  cout << "n1:" << intToBinaryString(n1) << endl;
  cout << "n2:" << intToBinaryString(n2) << endl;
  cout << "#bit to change:" << countChanges(n1, n2) << endl;
  return 0;
}
