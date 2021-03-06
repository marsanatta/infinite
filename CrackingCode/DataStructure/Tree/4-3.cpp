#include <iostream>
#include <new>
#include "binarySearchTree.h"

using namespace std;

void buildTree(int* arr, int len, Node** n) {
  if (arr == NULL || len == 0) {
    return;
  }
  *n = new Node(arr[len/2]);
  int rightLen = (len%2 == 0) ? len/2 - 1 : len/2;
  int leftLen = len/2;
  buildTree(arr, leftLen, &(*n)->left);
  buildTree(arr+len/2+1, rightLen, &((*n)->right));
}

int main() {

  int n;
  cin >> n;
  int* arr= new int[n];
  for (int i = 0; i < n; i++) {
    arr[i] = i+1;
  }
  BinarySearchTree t;
  buildTree(arr, n, t.getRootPtrAddr());
  t.dfsRecursive(PREORDER, t.getRoot());

  return 0;
}
