#include <iostream>
#define ARRAY_SIZE 10

using namespace std;

void shallowCopy (int **arr1, int **arr2) {
  *arr2 = *arr1;
}

void deepCopy(int *arr1, int *arr2) {
  for (int i = 0; i < ARRAY_SIZE; i++)
    arr2[i] = arr1[i];
}

void printArr(int *arr, int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] <<  " addr:" << (arr+i) <<endl;
}

int main() {

  int *arr1 = new int[ARRAY_SIZE];
  int *arr2 = new int[ARRAY_SIZE];

  for (int i = 0; i < ARRAY_SIZE; i++) {
    arr1[i] = i;
    arr2[i] = i * 10;
  }
  //deepCopy(arr1, arr2);
  shallowCopy(&arr1, &arr2);
  printArr(arr1, ARRAY_SIZE);
  printArr(arr2, ARRAY_SIZE);


  return 0;
}
