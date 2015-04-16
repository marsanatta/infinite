#include <iostream>
#include <new>

using namespace std;

struct Node {
  int val;
  Node* next;
  Node (int _val) : val(_val), next(NULL){}
  
  void insert(int newVal) {
    Node* cur = this;
    while(cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = new Node(newVal);
  }
  void print() {
    Node* cur = this;
    while (cur != NULL) {
      cout << cur->val << " addr:" << cur << endl;
      cur = cur->next;
    }
  }

};

void reverseLinkedList(Node** head, Node* prev, Node* cur) {
  if (cur->next == NULL) {
    *head = cur;
    cur->next = prev;
    return;
  }
  reverseLinkedList(head, cur, cur->next);
  cur->next = prev;
  return;
}


int main() {

  int n;
  cin >> n;
  Node *head = new Node(0);
  for (int i = 1; i < n; i++ ) {
    head->insert(i);
  }
  head->print();
  cout << "reversing..." << endl;
  reverseLinkedList(&head, NULL, head);
  head->print();

  return 0;
}
