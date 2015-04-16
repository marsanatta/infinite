#include <iostream>
#include "BitManipulation.h"

using namespace std;

int findNextSmallest(int val) {
  bool findOne = false;
  int idx = 0;
  int countOnes = 0;
  while(true) {
    if (getBit(val, idx)) {
      findOne = true;
      countOnes++;
    }
    if (!getBit(val, idx) && findOne == true) {
      break;
    }
    idx++;
  }
  //big at idx is now 0
  int fixOne = idx;
  setBit(val, fixOne, true);//set to 1
  setBit(val, fixOne-1, false);
  countOnes--;
  for (int i = 0; i < countOnes; i++) {
    setBit(val, i, true);
  }
  for (int i = countOnes; i <= fixOne-2; i++) {
    setBit(val, i, false);
  }
  return val;
}

int findNextBiggest(int val) {
  bool findZero = false;
  int idx = 0;
  int countOnes = 0;
  while(true) {
    if (!getBit(val, idx)) {
      findZero = true;
    }
    else
      countOnes++;
    if (getBit(val, idx) && findZero == true) {
      break;
    }
    idx++;
  }
  countOnes--;
  //now idx stop at 1
  setBit(val, idx, false);
  setBit(val, idx-1, true);
  for (int i = 0; i < idx - 1 - countOnes; i++) {
    setBit(val, i, false);
  }
  for (int i = idx - 1 - countOnes; i < idx -1; i++) {
    setBit(val, i, true);
  }
  return val;
}

int main() {

  int n;
  cin >> n;
  cout << "n:" << intToBinaryString(n) << endl;
  int nextSmallest = findNextSmallest(n);
  cout << "find next smallest: " << nextSmallest << "  " << intToBinaryString(nextSmallest) << endl;
  int nextBiggest = findNextBiggest(n);
  cout << "find next biggest: " << nextBiggest << " " << intToBinaryString(nextBiggest) << endl;

  return 0;
}
