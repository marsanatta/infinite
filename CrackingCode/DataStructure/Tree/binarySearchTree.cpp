#include <climits>
#include "binarySearchTree.h"
#include "stack.h"
#include "queue.h"

using namespace std;

void BinarySearchTree::insert(int value) {
  Node* cur = root;

  //empty tree
  if (cur == NULL) {
    root = new Node(value);
    cout << "root address: " << root << endl;
    return;
  }

  while(true) {
    if (cur->value > value) {
      if (cur->left == NULL) {
        cur->left = new Node(value);
        return;
      }
      cur = cur->left;
    }
    else {
      if (cur->right == NULL) {
        cur->right = new Node(value);
        return;
      }
      cur = cur->right;
    }
  }
}

void BinarySearchTree::dfsRecursive(int mode, Node* n) {
  if (n == NULL) {
    return;
  }
  if (mode == PREORDER) {
    cout << n->value << " addr: " << n << endl;
    if (n->left != NULL) {
      dfsRecursive(mode, n->left);
    }
    if (n->right != NULL) {
      dfsRecursive(mode, n->right);
    }
  }
  else if (mode == INORDER) {
    if (n->left != NULL) {
      dfsRecursive(mode, n->left);
    }
    cout << n->value << endl;
    if (n->right != NULL) {
      dfsRecursive(mode, n->right);
    }
  }
  else if (mode == POSTORDER) {
    if (n->left != NULL) {
      dfsRecursive(mode, n->left);
    }
    if (n->right != NULL) {
      dfsRecursive(mode, n->right);
    }
    cout << n->value << endl;
  }
}

void BinarySearchTree::dfs(int mode) {

  Stack<Node*> s;

  if (root == NULL) return;

  s.push(root);
  while(!s.isEmpty()) {
    if (mode == PREORDER) {
      Node* cur = s.pop();
      cout << cur->value << endl;
      if (cur->right != NULL) s.push(cur->right);
      if (cur->left != NULL) s.push(cur->left);

    }
    if (mode == POSTORDER) {

      Node* cur = s.peak();
      if (cur->left != NULL && !cur->left->isTraversed) {
        s.push(cur->left);
        cur = cur->left;
      }
      else if (cur->right != NULL && !cur->right->isTraversed) {
        s.push(cur->right);
        cur = cur->right;
      }
      else if ((cur->left == NULL && cur->right == NULL) ||
               (cur->left != NULL && cur->left->isTraversed && cur->right == NULL) ||
               (cur->right != NULL && cur->right->isTraversed && cur->left == NULL) ||
               (cur->left != NULL && cur->left->isTraversed && cur->right != NULL && cur->right->isTraversed)) {
        s.pop();
        cur->isTraversed = true;
        cout << cur->value << endl;
      }

    }
    if (mode == INORDER) {
      Node* cur = s.peak();
      if (cur->left != NULL && !cur->left->isTraversed) {
        s.push(cur->left);
      }
      else if(cur->left == NULL || (cur->left != NULL && cur->left->isTraversed)) {
        s.pop();
        cur->isTraversed = true;
        cout << cur->value << endl;

        if (cur->right != NULL && !cur->right->isTraversed) {
          s.push(cur->right);
        }
      }

    }
  }
}

Node* BinarySearchTree::dfsSearch(int value, Node** parent, Node* cur) {
  if (cur->value == value) {
    return cur;
  }
  if (cur->left != NULL){
    if (parent != NULL) *parent = cur;
    Node* find = dfsSearch(value, parent, cur->left);
    if (find != NULL) {
      return find;
    }
  }
  if (cur->right != NULL) {
    if (parent != NULL) *parent = cur;
    return dfsSearch(value, parent, cur->right);
  }
  return NULL;
}

Node* BinarySearchTree::search(int value, Node** parent) {
  return dfsSearch(value, parent, root);
}

Node* BinarySearchTree::findMin(Node* subRoot, Node** minParent) {
  
  int min = INT_MAX;
  subRoot = (subRoot == NULL) ? root : subRoot;

  //in BST min is at the left-most leaf
  Node* cur = subRoot;
  while (cur->left != NULL){
    *minParent = cur;
    cur = cur->left;
  }
  return cur;
  //bfs
  /*Queue<Node*> q;
  q.enqueue(subRoot);
  cout << "begin find min" << endl;
  while(!q.isEmpty()) {
    Node* cur = q.dequeue();
    cout << "checking min: " << cur->value << endl;
    if (cur->value < min) {
      ret = cur;
      min = cur->value;
      minParent = parent;
      cout << "found min" << endl;
    }
    if (cur->left != NULL) {
      q.enqueue(cur->left);
    }
    if (cur->right != NULL) {
      q.enqueue(cur->right);
    }
    parent = cur;
  }
  cout << "end find min" << endl;
  return ret;*/
}

Node* BinarySearchTree::removeRecursive(int value, Node* cur, Node* parent) {
  
  if (cur == NULL) {
    return NULL;
  }
  if (value < cur->value) {
    return removeRecursive(value, cur->left, cur);
  }
  else if (value > cur->value) {
    return removeRecursive(value, cur->right, cur);
  }
  else {
    if (parent == NULL) {
      //delete root
      cout << "delete root" << endl;
      BinarySearchTree auxT;
      auxT.insert(cur->value + 1);
      auxT.getRoot()->left = cur;
      auxT.removeRecursive(value, auxT.getRoot(), NULL);
      root = auxT.getRoot()->left;
      return cur;
    }
    //delete other
    
    //two child
    if (cur->left != NULL && cur->right != NULL) {
      Node* rightMin = findMin(cur->right, NULL);
      cur->value = rightMin->value;
      removeRecursive(rightMin->value, cur->right, cur);
    }
    else if (parent->left == cur) {
      parent->left = cur->left != NULL ? cur->left : cur->right;
    }
    else if (parent->right == cur) {
      parent->right = cur->right != NULL ? cur->right : cur->left;
    }
    return cur;
  }
}

Node* BinarySearchTree::remove(int value) {
  //find the value
  Node* delParent = NULL;
  Node* del = search(value, &delParent);
  bool isLeft = false;
  if (del == NULL) {
    cout << value << "doesn't exist. Delete failed." << endl;
    return NULL;
  }
  if (delParent == NULL) {
    cout << "You remove the root." << endl;
    BinarySearchTree auxT;
    auxT.insert(root->value+1);
    auxT.getRoot()->left = root;
    auxT.remove(value);
    root = auxT.getRoot()->left;
    return del;
  }
  if (delParent->left == del) isLeft = true;
  if (delParent->right == del) isLeft = false;
  //cout << "find del: " << del->value << " isLeft: " << isLeft << " Parent value "<< delParent->value << " Parent address: " << delParent << endl;
  //No child
  if (del->left == NULL && del->right == NULL) {
      if (isLeft) {
        delParent->left = NULL;
      }
      else {
        delParent->right = NULL;
      }
      return del;
  }
  //One child
  else if ((del->left == NULL && del->right != NULL) ||
      (del->left != NULL && del->right == NULL)) {
    //save remain sub-tree
    Node* remain = NULL;
    if (del->right != NULL) remain = del->right;
    else if (del->left != NULL) remain = del->left;
    //connect to the sub-tree, return delete
    if (isLeft) delParent->left = remain;
    else delParent->right = remain;
    return del;
  }
  //Two children
  else if (del->left != NULL && del->right != NULL) {
    //find min at right
    Node* minParent = NULL;
    Node* min = findMin(del->right, &minParent);
    cout << "find min: " << min->value << endl;
    //copy min value to delete node
    del->value = min->value;
    //cout << "setting the del->value = "
    //delete duplicate
    if (minParent == NULL) {
      //in this case, del is the parent of min
      //there must be no left child (if there is, then del won't be the
      //parent of min)
      //we directly pull up the right child of min
      del->right = min->right;
      delete min;
    }
    else if (minParent->left == min) {
      delete minParent->left;
      minParent->left = NULL;
    }
  }

}

void BinarySearchTree::bfs() {
  Queue<Node*> q;
  q.enqueue(root);
  while(!q.isEmpty()) {
    Node* cur = q.dequeue();
    cout << cur->value << endl;
    if (cur->left != NULL) {
      q.enqueue(cur->left);
    }
    if (cur->right != NULL) {
      q.enqueue(cur->right);
    }
  }
}

Node** BinarySearchTree::getRootPtrAddr() {
  return &root;
}

Node* BinarySearchTree::getRoot() {
  return root;
}

void BinarySearchTree::setRoot(Node* _root) {
  root = _root;
}

BinarySearchTree BinarySearchTree::copy(Node* subRoot) {
  Queue<Node*> q;
  q.enqueue(subRoot);
  BinarySearchTree out;

  while (!q.isEmpty()) {
    Node* cur = q.dequeue();
    out.insert(cur->value);
    if (cur->left != NULL) {
      q.enqueue(cur->left);
    }
    if (cur->right != NULL) {
      q.enqueue(cur->right);
    }

  }
  return out;
}

BinarySearchTree generateRandomTree(int num, int min, int max) {
  srand(time(NULL));
  BinarySearchTree t;
  int range = max - min;
  for (int i = 0; i < num; i++) {
    int randNum = min + rand() % range;
    t.insert(randNum);
    cout << "inserting " << randNum << endl;
  }
  return t;
}
