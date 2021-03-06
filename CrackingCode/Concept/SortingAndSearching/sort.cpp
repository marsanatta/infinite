#include "sort.h"

using std::cout;
using std::endl;

void printArr(int *arr, int len) {
  cout << "array:" << endl;
  for (int i = 0; i < len; i++) {
    cout << arr[i] << endl;
  }
  cout << endl;
}

int findMinPos(int const *arr, int len) {

  int min = INT_MAX;
  int pos = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] < min) {
      min = arr[i];
      pos = i;
    }
  }
  return pos;
}

template <typename T>
void swap(T &n1, T &n2) {
  cout << "swapping " << n1 << " " << n2 << endl;
  T temp = n2;
  n2 = n1;
  n1 = temp;
  return;
}

void bubbleSort(int *arr, int len) {
  int checkLen = len;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
      }
    }
  }
}

void selectionSort(int *arr, int len) {
  
  for (int i = 0; i < len-1; i++) {
    int minPos = findMinPos(arr+i, len-i);
    cout << "minPos:" << minPos << endl;
    swap(arr[i], arr[i+minPos]);
  }
}

void merge(int *arr, int left_s, int left_e, int right_s, int right_e) {
  
  int leftLen = left_e - left_s + 1;
  int rightLen = right_e - right_s + 1;
  int* left = new int[leftLen];
  int* right = new int[rightLen];

  //copy the content into temp left and right array
  cout << "left:" << endl;
  for (int i = 0; i < leftLen; i++) {
    left[i] = arr[left_s + i];
    cout << left[i] << " ";
  }
  cout << endl;
  cout << "right:" << endl;
  for (int i = 0; i < rightLen; i++) {
    right[i] = arr[right_s + i];
    cout << right[i] << " ";
  }
  cout << endl;
  //merge
  int r = 0;
  int l = 0;
  int i = 0;
  for (i = left_s, r = 0, l = 0; r < rightLen && l < leftLen; i++) {
    if (left[l] > right[r])
      arr[i] = right[r++];
    else
      arr[i] = left[l++];
  }
  //copy the leftover
  for (; r < rightLen; r++, i++) {
    arr[i] = right[r];
  }
  for (; l < leftLen; l++, i++) {
    arr[i] = left[l];
  }

}

void mergeSort(int *arr, int left, int right) {
  
  if (right <= left) {
    return;
  }

  int mid = (left+right)/2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid+1, right);
  merge(arr, left, mid, mid+1, right);
}

void quickSort2(int *arr, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = (left+right)/2;
  int pivot = arr[mid];
  swap(arr[left], arr[mid]);
  int i = left + 1;
  int j = right;
  while(i <= j) {
    while(arr[j] > pivot)
      j--;
    while(i <= j && arr[i] <= pivot)
      i++;
    if (i <= j) {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }
  swap(arr[left], arr[j]);
  quickSort2(arr, left, j-1);
  quickSort2(arr, j+1, right);
}

void quickSort(int *arr, int left, int right) {
  
  if (left > right) {
    return;
  }
  
  int pivot = arr[(left+right)/2];
  cout << "pivot:" << pivot << endl;
  int i = left;
  int j = right;
  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    //cout << "arr[i]:" << arr[i] << "arr[j]:" << arr[j] << endl;
    cout << "stop at i:" << i << "j:" << j << endl;
    if (i <= j) {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }
  cout << "stop at i:" << i << "j:" << j << endl;
  //if (left < j) {
    //cout << "quick sort left:" << left << "right:" << j << endl;
    quickSort(arr, left, j);
  //}
  //if (right > i) {
    //cout << "quick sort left:" << i << "right:" << right << endl;
    quickSort(arr, i, right);
  //}

}

void bucketSort(int *arr, int len, int min, int max) {
  int *buckets;
  int range = max - min + 1;
  buckets = new int[range];
  memset(buckets, 0, sizeof(int) * range);
  for (int i = 0; i < len; i++) {
    buckets[arr[i] - min]++;
  }
  int idx = 0;
  for (int i = 0; i < range; i++) {
    if (buckets[i] != 0) {
      for (int j = 0; j < buckets[i]; j++) {
        arr[idx++] = i + min;
      }
    }
  }
}
