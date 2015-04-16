#include <iostream>
#include <cstdlib>

using namespace std;

void merge(int arr[], int low, int mid, int high) {
  int *tmp = new int[high - low + 1];
  int l = low, h = mid+1, tmpLen = 0;

  //merging
  while (l <= mid && h <= high) {
    if (arr[l] <= arr[h]) {
      tmp[tmpLen] = arr[l];
      l++;
    }
    else {
      tmp[tmpLen] = arr[h];
      h++;
    }
    tmpLen++;
  }
  //fill the rest to the tmp array
  if (l <= mid) {
    for (; l <= mid; l++) {
      tmp[tmpLen] = arr[l];
      tmpLen++;
    }
  }
  else if (h <= high) {
    for (; h <= high; h++) {
      tmp[tmpLen] = arr[h];
      tmpLen++;
    }
  }
  //copy the tmp array to the output array
  for (int i = low, j = 0; i <= high; i++, j++) {
    arr[i] = tmp[j];
  }
  delete[] tmp;
}


void mergeSort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    cout << "mid:" << mid <<  "low:" << low << "high:" << high << endl;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}
int* generateArray(int len) {
  int* arr = new int[len];
  srand(time(NULL));
  for (int i = 0; i < len; i++) {
    arr[i] = rand() % 100;
  }
  return arr;
}

void printArray(int arr[], int len) {
  cout << "array:" << endl;
  for(int i = 0; i < len; i++) {
    cout << arr[i] << endl;
  }
}

int main() {
  int len;
  cin >> len;

  int* arr = generateArray(len);
  printArray(arr, len);
  mergeSort(arr, 0, len - 1);
  cout << "after sorting the array..." << endl;
  printArray(arr, len);
  return 0;
}
