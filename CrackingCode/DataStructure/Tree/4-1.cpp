#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "binarySearchTree.h"

using namespace std;

vector<Node*> leafs;

void countDepthRecursive(Node* cur, int depth) {
  if (cur == NULL) {
    return;
  }
  cur->depth = depth;
  //add to leafs
  if (cur->left == NULL && cur->right == NULL) {
    leafs.push_back(cur);
  }
  depth++;
  //traverse left and right
  if (cur->left != NULL) {
    countDepthRecursive(cur->left, depth);
  }
  if (cur->right != NULL) {
    countDepthRecursive(cur->right, depth);
  }
}

bool isBalanced(BinarySearchTree &t){
  countDepthRecursive(t.getRoot(), 0);
  Node* checker = leafs.front();
  for (vector<Node*>::iterator it = leafs.begin()+1; it != leafs.end(); ++it) {
    if (abs(checker->depth - (*it)->depth) > 1) {
      cout << "node " << checker->value << " depth " << checker->depth << " node " << (*it)->value << " depth " << (*it)->depth << endl;
      return false;
    }
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  BinarySearchTree t;
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    int randNum = 1 + rand() % 100;
    t.insert(randNum);
  }
  t.dfsRecursive(PREORDER, t.getRoot());
  cout << "is balanced: " << isBalanced(t) << endl;

  return 0;
}
