#include <iostream>
#include <vector>
#include <new>

using namespace std;

struct GraphNode {
  int value;
  vector<GraphNode*> adjecents;

  GraphNode(int _value) {
    value = _value;
  }
};

bool dfsSearch(GraphNode* n, GraphNode* key) {

  if (n == key) {
    return true;
  }
  for (vector<GraphNode*>::iterator it = n->adjecents.begin(); it != n->adjecents.end(); ++it) {
    //cout << "checking " << n->value << " adjecent " << (*it)->value << endl;
    bool ret = dfsSearch(*it, key);
    if (ret == true) {
      return true;
    }
  }
  return false;
}

int main() {

  GraphNode head(1);
  GraphNode n1(2);
  GraphNode n2(3);
  GraphNode n3(4);
  head.adjecents.push_back(&n1);
  head.adjecents.push_back(&n2);
  n2.adjecents.push_back(&n3);
  cout << dfsSearch(&head, &n1) << endl;
  cout << dfsSearch(&head, &n2) << endl;
  cout << dfsSearch(&head, &n3) << endl;
  GraphNode n4(5);
  cout << dfsSearch(&head, &n4) << endl;
  n3.adjecents.push_back(&n4);
  cout << dfsSearch(&head, &n4) << endl;
  

  return 0;
}
