#include <queue>
#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
private:
  int value;
  Node *left;
  Node *right;
public:
  Node(int value) : value(value), left(nullptr), right(nullptr) {
  
  }

  ~Node() {
    del();
  }
  
  void del() {
    queue<Node*> q;
    q.push(this);
    while(!q.empty()) {
      Node* cur = q.front();
      q.pop();
      if (cur->getLeft() != nullptr)
        q.push(cur->getLeft());
      if (cur->getRight() != nullptr)
        q.push(cur->getRight());
      delete cur;
    }
  }

  void setValue(int value) {
    this->value = value;
  }
  void setLeft(Node* left) {
    this->left = left;
  }
  void setRight(Node* right) {
    this->right = right;
  }
  Node* getLeft() const{
    return left;
  }
  Node* getRight() const{
    return right;
  }
  int getValue() const{
    return value;
  }
  
};

void dfs(const Node* n) {
  cout << n->getValue() << endl;
  if (n->getLeft() != nullptr)
    dfs(n->getLeft());
  if (n->getRight() != nullptr)
    dfs(n->getRight());
}

void copy(Node** origRoot, Node** genRoot, Node* orig, Node* gen) {
  if (*genRoot == nullptr) {
    *genRoot = new Node((*origRoot)->getValue());
    gen = *genRoot;
  }
  if (orig->getLeft() != nullptr) {
    gen->setLeft(new Node(orig->getLeft()->getValue()));
    copy(origRoot, genRoot, orig->getLeft(), gen->getLeft());
  }
  if (orig->getRight() != nullptr) {
    gen->setRight(new Node(orig->getRight()->getValue()));
    copy(origRoot, genRoot, orig->getRight(), gen->getRight());
  }
}


void randGenerate(Node** gen, Node* cur) {
  int hasLeft, hasRight;
  srand(time(NULL));
  if(*gen == nullptr) {
    *gen = new Node(1+rand()%100);
    cur = *gen;
  }
  
  hasLeft = rand()%100;
  hasRight = rand()%100;
  if (hasLeft < 10) {
    cout << "generating left..." << endl;
    cur->setLeft(new Node(1+rand()%100));
    randGenerate(gen, cur->getLeft());
  }
  if (hasRight < 10) {
    cout << "geenrating right..." << endl;
    cur->setRight(new Node(1+rand()%100));
    randGenerate(gen, cur->getRight());
  }

}

int main() {

  Node* root1 = new Node(3);
  root1->setLeft(new Node(2));
  root1->setRight(new Node(6));
  Node* tmp = root1->getLeft();
  tmp->setLeft(new Node(1));
  tmp->setRight(new Node(5));
  //randGenerate(&root1, nullptr);
  cout << "root1:" << endl;
  dfs(root1);

  Node* root2 = nullptr;
  copy(&root1, &root2, root1, root2);
  cout << "root2:" << endl;
  dfs(root2);

  return 0;
}
