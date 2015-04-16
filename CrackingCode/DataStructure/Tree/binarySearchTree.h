#include <cstddef>
#include <cstdlib>

#define PREORDER 1
#define INORDER 2
#define POSTORDER 3

using namespace std;

struct Node {

  int value;
  bool isTraversed;
  Node* left;
  Node* right;
  int depth;
  Node* parent;

  Node(int _value) {
    left = NULL;
    right = NULL;
    value = _value;
    isTraversed = false;
    depth = 0;
    parent = NULL;
  }
};

class BinarySearchTree {
private:
  Node* root;
  Node* dfsSearch(int value, Node** parent, Node* cur);
public:
  BinarySearchTree() { root = NULL; }
  void insert(int value);
  Node* removeRecursive(int value, Node* cur, Node* parent);
  Node* remove(int value);
  void dfs(int mode);
  void dfsRecursive(int mode, Node* n);
  void bfs();
  Node** getRootPtrAddr();
  Node* getRoot();
  void setRoot(Node* _root);
  Node* search(int value, Node** parent);
  Node* findMin(Node* subRoot, Node** minParent);
  BinarySearchTree copy(Node* subRoot);
};

BinarySearchTree generateRandomTree(int num, int min, int max);
