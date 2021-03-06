#include <iostream>
#include "BitManipulation.h"

bool fetch(const int *A, int i, int j) {
  return getBit(A[i], j);
}

int findMissing1(const int *A, int size) {
  bool lastBit = fetch(A, 0, 0);
  //cout << "lastBit:" << lastBit << endl;
  for (int i = 1; i < size; i++) {
    bool curBit = fetch(A, i, 0);
    //cout << "lastBit:" << lastBit << endl;
    if (curBit == lastBit) {
      return A[i] - 1;
    }
    lastBit = curBit;
  }

  if (A[0] != 0) {
    return 0;
  }
  else
    return size;
}

int findMissing2(const int *A, int col, int size) {

  int *odds = new int[size];
  int oddIdx = -1;
  int *evens = new int[size];
  int evenIdx = -1;

  if (col == 32) {
    return 0;
  }
  cout << "==================== AT COL: " << col << endl;
  for (int i = 0; i < size; i++) {
    if (fetch(A, i, col) == false) {
      evenIdx++;
      evens[evenIdx] = A[i];
      cout << "find an even:" << evens[evenIdx] << endl;
    }
    else {
      oddIdx++;
      odds[oddIdx] = A[i];
      cout << "find an odd:" << odds[oddIdx] << endl;
    }
  }
  int oddsSize = oddIdx + 1;
  int evensSize = evenIdx + 1;
  cout << "oddsSize: " << oddsSize << " evensSize: " << evensSize << endl;
  if (oddsSize >= evensSize) {
    cout << "col: " << col << " is 0" << endl;
    return (findMissing2(evens, col + 1, evensSize) << 1 | 0);
  }
  else {
    cout << "col: " << col << " is 1" << endl;
    return (findMissing2(odds, col + 1, oddsSize) << 1 | 1);
  }
}

using namespace std;

int main() {
  int size;
  cout << "Enter size:" << endl;
  cin >> size;
  int missing;
  cout << "Enter missing:" << endl;
  cin >> missing;

  int* A = new int[size];
  for (int i = 0; i < missing ; i++) {
    A[i] = i;
  }

  for (int i = missing; i < size; i++) {
    A[i] = i+1;
  }
  cout << "find missing:" << findMissing2(A, 0, size) << endl;
  return 0;
}
