#include <iostream>
#include <ctime>
#include <cstdlib>
#include "binarySearchTree.h"
#include "queue.h"

using namespace std;

int main() {

  int N;
  //enter the number of node
  cout << "Enter the number of tree node:";
  cin >> N;

  BinarySearchTree t;
  srand(time(NULL));
  /*for (int i = 0; i < N; i++) {
    int num = 1 + rand() % 100;
    //int num;
    //cin >> num;
    t.insert(num);
    cout << "inserting " << num << endl;
  }*/
  t.insert(87);
  t.insert(48);
  t.insert(7);
  t.insert(62);
  t.insert(91);
  t.insert(93);
  
  //cout << "pre-order" << endl;
  //t.dfs(PREORDER);
  cout << "pre-order dfs recursive" << endl;
  t.dfsRecursive(PREORDER, t.getRoot());
  cout << "post-order dfs recursive" << endl;
  t.dfsRecursive(POSTORDER, t.getRoot());
  while(true) {
    int delValue;
    cout << "Enter a node to remove:";
    cin >> delValue;
    t.removeRecursive(delValue, t.getRoot(), NULL);
    cout << "pre-order dfs recursive" << endl;
    t.dfsRecursive(PREORDER, t.getRoot());
    cout << "post-order dfs recursive" << endl;
    t.dfsRecursive(POSTORDER, t.getRoot());
   
  }

  //cout << "in-order" << endl;
  //t.dfs(INORDER);
  //cout << "in-order recursive" << endl;
  //t.dfsRecursive(INORDER, t.getRoot());
  //cout << "post-order" << endl;
  //t.dfs(POSTORDER);
  //cout << "post-order recursive" << endl;
  //t.dfsRecursive(POSTORDER, t.getRoot());

  /*Stack s;
  s.push(0);
  s.push(1);
  s.push(2);
  for (int i = 0; i < 3; i++) {
    int* ret = s.pop();
    if(ret != NULL)
      cout << "pop out " << *ret << endl;
  }*/

  /*Queue<int*> q;
  for (int i = 0; i < 3; i++) {
    int *newInt = new int(i);
    q.enqueue(newInt);
    cout << "enqueue " << *newInt << endl;
  }
  
  for (int i = 0; i < 5; i++) {
    int* ret = q.dequeue();
    if (ret != NULL) {
      cout << "dequeue " << *ret << endl;
    }
  }*/
  
  return 0;
}
