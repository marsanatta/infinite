#include <iostream>
#include "sort.h"

using namespace std;

int findPivot(int const *arr, int low, int high) {
  if (high <= low) return -1;
  //if (high == low) return low;

  int mid = low + (high - low)/2;
  if (mid < high && arr[mid] > arr[mid+1])
    return mid;
  if (mid > low && arr[mid] < arr[mid-1])
    return mid - 1;
  if (arr[low] >= arr[mid])
    return findPivot(arr, low, mid - 1);
  else
    return findPivot(arr, mid + 1, high);
}

void rotate(int *arr, int len, int shift) {
  int *temp = new int[shift];
  for (int i = 0; i < shift; i++) {
    temp[i] = arr[len - shift + i];
  }
  for (int i = len - 1; i >= shift; i--) {
    arr[i] = arr[i - shift];
  }

  for (int i = 0; i < shift; i++) {
    arr[i] = temp[i];
  }
}

int binarySearch(int const *arr, int low, int high, int item) {
  
  if (low > high) return - 1;
  int mid = low + (high - low) / 2;
  if (item == arr[mid]) return mid;
  if (item > arr[mid]) return binarySearch(arr, mid + 1, high, item);
  if (item < arr[mid]) return binarySearch(arr, low, mid - 1, item);
}

int pivotBinarySearch(int const *arr, int low, int high, int item) {
  int pivot = findPivot(arr, low, high);
  cout << "pivot:" << pivot << endl;
  if (pivot == -1) {
    return binarySearch(arr, low, high, item);
  }
  
  if (item == arr[pivot]) return pivot;
  if (item < arr[0])
    return binarySearch(arr, pivot + 1, high, item);
  else
    return binarySearch(arr, low, pivot - 1, item);
}

int main() {

  int n;
  cin >> n;

  int *arr = new int[n];

  for (int i = 0; i < n; i++) {
    arr[i] = 1;
  }

  int r;
  cin >> r;

  printArr(arr, n);

  rotate(arr, n, r);

  cout << "rotated:" << endl;
  printArr(arr, n);

  //int find = findPivot(arr, 0, n - 1);
  //cout << "find:" << find << endl;

  int item;
  cin >> item;
  cout << "item is at:" << pivotBinarySearch(arr, 0, n - 1, item) << endl;

  return 0;
}
