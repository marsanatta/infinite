#include <iostream>
#define N 100000

using namespace std;

int binarySearchRecursive(int *a, int left, int right, int key){
  
  int middle;
  int len = right - left +1;
  int middleIdx = left + len/2;
  middle = a[middleIdx];

  /*if(len <= 2 && a[left] != key && a[right] != key)
    return -1;*/
  if(left > right)
    return -1;
  if (key > middle) {
    return binarySearchRecursive(a, middleIdx+1, right, key);
  }
  else if(key < middle){
    return binarySearchRecursive(a, left, middleIdx-1, key);
  }
  else if(key == middle){
    return middleIdx;
  }
}

int binarySearch(int *a, int len, int key){

  int left, right;
  //init
  left = 0;
  right = len - 1;
  
  while(left <= right){
    
    int middleIdx = left + (right - left + 1) / 2;
    int middle = a[middleIdx];

    if (key < middle) {
      right = middleIdx - 1;
    }
    else if (key > middle) {
      left = middleIdx + 1;
    }
    else if (key == middle){
      return middleIdx;
    }
  }
  return -1;

}

int main() {

  int n;
  int a[N];
  int key;
  //read input
  cout << "Enter #element in the array:" << endl;
  cin >> n;
  cout << "Enter array element:" << endl;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << "Enter the number you want to search:" << endl;
  //read the number you want to search
  cin >> key;
  //normal binary search
  cout << "= Binary Search  =" << endl;
  int pos = binarySearch(a, n, key);
  if(pos  != -1){
    cout << key << " is at the " << pos << endl;
  }
  else{
    cout << key << " is not in the array." << endl;
  }
  //recursive binary search
  cout << "= Recursive Binary Search  =" << endl;
  pos = binarySearchRecursive(a, 0, n-1, key);
  if(pos  != -1){
    cout << key << " is at the " << pos << endl;
  }
  else{
    cout << key << " is not in the array." << endl;
  }



  return 0;
}
