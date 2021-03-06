#include <iostream>
#include <cstdlib>

using namespace std;

int* generateArray(int len) {
  int* arr = new int[len];
  srand(time(NULL));
  //arr[0] = 77;
  for (int i = 0; i < len; i++) {
    arr[i] = rand() % 100;
  }
  //arr[len - 1] = 77;
  return arr;
}

void printArray(int arr[], int len) {
  cout << "array:" << endl;
  for(int i = 0; i < len; i++) {
    cout << arr[i] << endl;
  }
}

void swap(int &a, int &b) {
  cout << "swapping " << a << " and " << b << endl;
  int tmp = b;
  b = a;
  a = tmp;
}

void quickSort(int *arr, int low, int high) {
  int i = low, j = high;
  int pivot = arr[low + (high - low) / 2];

  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    cout << "i:" << i << "j:" << j << endl;
    if (i <= j) {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }
  //not a good algortihm: the element will be re-sorted
  //but easy to remember
  if (low < j)
    quickSort(arr, low, j);
  if (i < high)
    quickSort(arr, i, high);
}

int main() {
  int len;
  cin >> len;
  int* arr = generateArray(len);
  printArray(arr, len);
  quickSort(arr, 0, len - 1);
  printArray(arr, len);
}
