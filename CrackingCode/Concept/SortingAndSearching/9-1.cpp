#include <cstdlib>
#include <iostream>
#include "sort.h"

using namespace std;

void insert(int *arr, int &len, int pos, int val) {
  
  if (pos > len) {
    return;
  }

  for (int i = len; i > pos; i--) {
    arr[i] = arr[i-1];
  }
  arr[pos] = val;
  len++;
}

void merge(int *A, int *B, int alen, int blen) {
  int a = alen - 1;
  int b = blen - 1;
  int idx = alen + blen - 1;
  while (a >= 0 && b >= 0) {
    if (A[a] >= B[b]) {
      A[idx--] = A[a--];
    }
    else {
      A[idx--] = B[b--];
    }
  }
  //while (a >= 0)
    //A[idx--] = A[a--];
  while (b >= 0)
    A[idx--] = B[b--];
}

int main() {

  int alen, blen;
  cin >> alen >> blen;
  int *A = new int[alen + blen];
  int *B = new int[blen];
  srand(time(NULL));
  for (int i = 0; i < alen; i++) {
    A[i] = 1 + rand()%100;
  }
  for (int i = 0; i < blen; i++) {
    B[i] = 1 + rand()%100;
  }
  quickSort(A, 0, alen - 1);
  quickSort(B, 0, blen - 1);
  printArr(A, alen);
  printArr(B, blen);
  merge(A, B, alen, blen);
  printArr(A, alen + blen);

  return 0;
}
