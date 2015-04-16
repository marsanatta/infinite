#include <iostream>
#include <new>
#include <map>
#include <cstdlib>
#include "binarySearchTree.h"

using namespace std;

struct LinkedNode {
  int value;
  LinkedNode* next;
  LinkedNode(int _value) {
    value = _value;
  }
  void addNode(int value){
    LinkedNode* cur = this;
    while(cur->next != NULL)
      cur = cur->next;
    cur->next = new LinkedNode(value);
  }

  void print() {
    LinkedNode* cur = this;
    while(cur != NULL){
      cout << cur->value << " ";
      cur = cur->next;
    }
  }
};

void buildDepthLinkedLists(Node* cur, int depth, map<int, LinkedNode*> &linkedLists) {
  map<int, LinkedNode*>::iterator it = linkedLists.find(depth);
  if (it != linkedLists.end()) {
    it->second->addNode(cur->value);
  }
  else {
    linkedLists.insert(make_pair(depth, new LinkedNode(cur->value)));
  }
  depth++;
  if (cur->left != NULL) {
    buildDepthLinkedLists(cur->left, depth, linkedLists);
  }
  if (cur->right != NULL) {
    buildDepthLinkedLists(cur->right, depth, linkedLists);
  }
}


int main() {

  int n;
  BinarySearchTree t;
  cin >> n;
  srand(time(NULL));
  for (int i = 0; i < n; i ++) {
    t.insert(1 + rand()%100 );
  }
  t.dfsRecursive(PREORDER, t.getRoot());

  map<int, LinkedNode*> linkedLists;
  buildDepthLinkedLists(t.getRoot(), 0, linkedLists);
  for (map<int, LinkedNode*>::iterator it = linkedLists.begin(); it != linkedLists.end(); ++it) {
    cout << "depth:" << it->first << " ";
    it->second->print();
    cout << endl;
  }

  return 0;
}
