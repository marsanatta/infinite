#include <iostream>
#include <cstdlib>
#include "sort.h"

#define MAX 5
#define MIN 1

using namespace std;

int main() {

  int *arr = NULL;
  int len;
  cin >> len;
  arr = new int[len];
  srand(time(NULL));
  for (int i = 0; i < len; i++) {
    int r = MIN + rand()%MAX;
    arr[i] = r;
  }
  printArr(arr, len);
  bucketSort(arr, len, MIN, MAX);
  printArr(arr, len);


  return 0;
}
