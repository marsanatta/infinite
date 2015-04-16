#include <iostream>
#include <cstdlib>
#include "binarySearchTree.h"
#include "queue.h"

using namespace std;

bool isSame(Node* n1, Node* n2) {

  bool ret;
  if (n1 == NULL || n2 == NULL) {
    return false;
  }
  //cout << "is " << n1->value << " and " << n2->value << " the same?" << endl;
  if (n1->value != n2->value) {
    return false;
  }
  else {
    ret = true;
  }
  if (n2->left != NULL) {
    ret = ret && isSame(n1->left, n2->left);
  }
  if (n2->right != NULL) {
    ret = ret && isSame(n1->right, n2->right);
  }
  return ret;
}

bool isSub(Node* t1, Node* t2) {
  if (t1 == NULL || t2 == NULL) {
    return false;
  }
  Queue<Node*> q;
  q.enqueue(t1);
  while(!q.isEmpty()) {
    Node* cur = q.dequeue();

    if (cur->value == t2->value) {
      cout << "find the value " << cur->value << endl;
      if (isSame(cur, t2)) {
        return true;
      }
    }

    if (cur->left != NULL) {
      q.enqueue(cur->left);
    }
    if (cur->right != NULL) {
      q.enqueue(cur->right);
    }
  }
  return false;
}

int main() {

  int n;
  cin >> n;
  BinarySearchTree t = generateRandomTree(n);
  t.dfsRecursive(PREORDER, t.getRoot());

  while(true) {
    cout << "Enter a node of t1 to generate sub-tree:" << endl;
    int subRootValue;
    cin >> subRootValue;
    //Node* subRootParent = NULL;
    Node* subRoot = t.search(subRootValue, NULL);
    if (subRoot == NULL) {
      cout << "Not exists. " << endl;
      continue;
    }
    BinarySearchTree t2 = t.copy(subRoot);
    cout << "Sub-tree is generated" << endl;
    t2.dfsRecursive(PREORDER, t2.getRoot());
    cout << "isSub before changing the sub-tree: " << isSub(t.getRoot(), t2.getRoot()) << endl;
    t2.insert(100);
    t2.dfsRecursive(PREORDER, t2.getRoot());
    cout << "isSub after adding 100 to the sub-tree: " << isSub(t.getRoot(), t2.getRoot()) << endl;
    t2.remove(100);
    t2.dfsRecursive(PREORDER, t2.getRoot());
    cout << "isSub after removing 100 from the sub-tree: " << isSub(t.getRoot(), t2.getRoot()) << endl;

  }

  return 0;
}
