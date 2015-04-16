#include <iostream>
#include <new>
#include <cstdlib>
#include "binarySearchTree.h"

using namespace std;

int covers(Node* root, Node* p, Node* q) {
  int ret = 0;
  if (root == NULL || p == NULL || q == NULL) {
    return ret;
  }
  if (root == p || root == q) {
    ret++;
    if (p == q) {
      ret++;
    }
  }
  ret += covers(root->left, p, q);
  if (ret == 2) {
    return ret;
  }
  return ret += covers(root->right, p, q);
}

Node* findCommonAnsc(Node* root, Node* p, Node* q) {
  if (root == NULL || p == NULL || q == NULL) {
    return NULL;
  }
  if ((p == q) && (root->left == p || root->right == p)) {
    return root;
  }
  int leftCovers = covers(root->left, p, q);
  cout << "find left covers of " << root->value << " is " << leftCovers << endl;
  if (leftCovers == 2) {
    if (root->left == p || root->left == q) {
      return root->left;
    }
    else 
      return findCommonAnsc(root->left, p, q);
  }
  int rightCovers = covers(root->right, p, q);
  cout << "find right covers of " << root->value << " is " << rightCovers << endl;
  if (rightCovers == 2) {
    if (root->right == p || root->right == q) {
      return root->right;
    }
    else
      return findCommonAnsc(root->right, p, q);
  }
  return root;
  
}

int main() {

  int n;
  cin >> n;
  BinarySearchTree t;
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    t.insert(1+rand()%100);
  }
  cout << "preorder" << endl;
  t.dfsRecursive(PREORDER, t.getRoot());

  while(true) {
    int value1, value2;
    cout << "Enter two node:" << endl;
    cin >> value1;
    cin >> value2;
    Node* f1;
    Node* f2;
    Node* f1p;
    Node* f2p;
    f1 = t.search(value1, &f1p);
    f2 = t.search(value2, &f2p);
    if (f1 == NULL || f2 == NULL) {
      cout << "Not exists." << endl;
      continue;
    }
    Node* ansc = findCommonAnsc(t.getRoot(), f1, f2);
    if (ansc != NULL) {
      cout << "Ansc is " << ansc->value << endl;
    }
    else
      cout << "Ansc doe not exist." << endl;
  }

  return 0;
}
