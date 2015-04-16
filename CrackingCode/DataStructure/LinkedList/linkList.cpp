#include <iostream>
#include <cstdlib>
#include <new>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

struct Node {
  int value;
  Node* next;

  Node(int _value){
    value = _value;
    next = NULL;
  }

  
  void addNode(int newValue){
    Node *cur = this;
    Node *newNode = new Node(newValue);

    while(cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = newNode;
    cout << "add " << newValue << endl;
    return;
  }

  Node* tail() {
    Node *cur = this;
    while (cur->next != NULL)
      cur = cur->next;
    return cur;
  }
  
  int length() {
    Node* cur = this;
    int length = 1;
    while (cur->next != NULL) {
      cur = cur->next;
      length++;
    }
    return length;
  }


  Node* find(int value){
    Node *cur;
    cur = this;
    while(cur != NULL){
      if (cur->value == value)
        return cur;
      cur = cur->next;
    }
    cout << "cannot find " << value << endl;
    return NULL;
  }
  Node* del(Node* n){
    cout << "delete " << n->value << " addr: "<< n << endl; 
    Node *cur = this;
    Node *head = this;
    //delete head
    if(head == n){
      Node *ret = head->next;
      delete head;
      return ret;
    }

    while(cur->next != NULL) {
      if (cur->next == n){
        cur->next = cur->next->next;
        delete n;
        break;
      }
      cur = cur->next;
    }
    return head;
  }

  void print(){

    cout << value << " addr: " << this << endl; 
    Node* ptr = next;
    while(ptr != NULL)
    {
      cout << ptr->value << " addr: " << ptr << endl;
      ptr = ptr->next;
    }
    cout << endl;
  }

};

void reverseLinkedList1(Node* n, Node** head){
  Node* originalHead = *head;
  
  if(n == NULL || head == NULL)
    return;

  if(n->next == NULL){
    *head = n;
    return;
  }
  reverseLinkedList1(n->next, head);
  n->next->next = n;
  if (n == originalHead){
    n->next = NULL;
  }
  return;
}

void reverseLinkedList2(Node **head) {
  Node* prev = *head;
  Node* cur = prev->next;
  Node* child = cur->next;
  prev->next = NULL;
  while (child != NULL){
    cur->next = prev;
    prev = cur;
    cur = child;
    child = child->next;
  }
  cur->next = prev;
  *head = cur;
  return;
}

//O(n)
bool hasAppeared[32];
void removeDuplicate1(Node* head){
  Node* prev = head;
  Node* cur = head->next;
  memset(hasAppeared, false, sizeof(bool) * 32);
  hasAppeared[head->value] = true;
  while(cur != NULL){
    if(hasAppeared[cur->value])
    {
      Node* temp = cur;
      prev->next = cur->next;
      cur = cur->next;
      delete temp;
    }
    else {
      hasAppeared[cur->value] = true;
      prev = cur;
      cur = cur->next;
    }
  }
}
bool isDuplicated(Node* n, Node* head){
  Node* cur = head;
  while (cur != n){
    //check if the value has appeared before
    if (cur->value == n->value)
      return true;
    cur = cur->next;
  }
  return false;
}
//O(n^2)
void removeDuplicate2(Node* head) {
  Node* prev = head;
  Node* cur = head->next;
  while (cur != NULL) {
    if (isDuplicated(cur, head)) {
      Node* temp = cur;
      prev->next = cur->next;
      cur = cur->next;
      delete temp;
    }
    else {
      prev = cur;
      cur = cur->next;
    }
  }
}

Node* findNthToEnd(int N, Node* head) {
  int nth = 0;
  Node* cur = head;
  //find Nth node to the head
  while (nth != N) {
    cur = cur->next;
    nth++;
  }
  if (cur == NULL) {
    cout << N << "th exceed the linked list" << endl;
    return head;
  }
  Node* ret = head;
  //travser cur to end; ret = ret->next in each step
  while (cur->next != NULL) {
    cur = cur->next;
    ret = ret->next;
  }
  return ret;
}

Node* findNthToEndRecursive(int* N, Node* n) {
  if (n->next == NULL) {
    if (*N == 0){
      *N = *N - 1;
      return n;
    }
    *N = *N - 1;

    return NULL;
  }
  Node* ret = findNthToEndRecursive(N, n->next);
  if (*N == 0) {
    //*N = *N - 1;
    return n;
  }
  *N = *N - 1;
  return ret;
}

void directDelete(Node* n) {
  if (n == NULL || n->next == NULL)
    return;
  cout << "delete " << n->value << endl;
  n->value = n->next->value;
  n->next = n->next->next;
  return;
  
}

Node* addDigit1(Node* n1, Node* n2) {
  
  Node* larger = NULL;
  Node* smaller = NULL;
  bool sameLength = false;
  
  if (n1->length() > n2->length()) {
    larger = n1;
    smaller = n2;
  }
  else if (n2->length() > n1->length()) {
    larger = n2;
    smaller = n1;
  }
  else {
    larger = n1;
    smaller = n2;
    sameLength = true;
  }

  Node* out = NULL;
  int more = 0;
  while (smaller != NULL) {
    int sum = smaller->value + larger->value + more;
    int digit1 = sum % 10;
    more = (sum - digit1)/10;
    if (out == NULL)
      out = new Node(digit1);
    else
      out->addNode(digit1);
    larger = larger->next;
    smaller = smaller->next;
  }
  if (sameLength && more != 0) {
    out->addNode(more);
  }
  else if (!sameLength && more != 0) {
    while (larger != NULL){
      int sum = more + larger->value;
      cout << "sum: " << sum << endl;
      int digit1 = sum%10;
      more = (sum - digit1)/10;
      out->addNode(digit1);
      larger = larger->next;
    }
    if (more != 0) {
      out->addNode(more);
    }
  }
  else if (!sameLength && more == 0) {
    Node* tail = out->tail();
    tail->next = larger;
  }


  return out;

}

bool checkAppeared(Node* n, vector<Node*> appeared){
  for (int i = 0; i < appeared.size(); i++) {
    //cout << "checking"
    if (appeared[i] == n)
      return true;
  }
  return false;
}

//O(n^2)
Node* findLoopBegin1(Node* head) {
  Node* cur = head;
  vector<Node*> appeared;
  while (cur != NULL) {
    if (checkAppeared(cur, appeared)) {

      return cur;
    }
    else {
      appeared.push_back(cur);
      //cout << "add " cur->next << " into appeared" << endl;
    }
    cur = cur->next;
  }
  return NULL;
}

Node* findLoopBegin2(Node* head) {
  
  Node* fast = head;
  Node* slow = head;

  do {
    if (fast == NULL || slow == NULL) {
      return NULL; //No loop in this linked list
    }
    fast = fast->next->next;
    slow = slow->next;
  } while(fast != slow);

  slow = head;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }

  return fast;

}

Node* addDigit2(Node* n1, Node* n2) {
  Node* out = NULL;
  int carry = 0;
  while (n1 != NULL || n2 != NULL) {
    int sum = 0;
    int n1Value = (n1 != NULL) ? n1->value : 0;
    int n2Value = (n2 != NULL) ? n2->value : 0;
    sum = sum + n1Value + n2Value + carry;

    int digit = sum % 10;
    carry = (sum >= 10) ? 1:0;
    if (out == NULL) {
      out = new Node(digit);
    }
    else {
      out->addNode(digit);
    }

    n1 = (n1 != NULL) ? n1->next : NULL;
    n2 = (n2 != NULL) ? n2->next : NULL;
  }

  if (carry != 0) {
    out->addNode(carry);
  }

  return out;
}

void makeCircular(int index, Node* head) {
  Node* f = findNthToEnd(index ,head);
  head->tail()->next = f;
}


int main() {

  Node* head = new Node(1);
  head->addNode(2);
  head->addNode(3);
  head->addNode(4);
  head->addNode(5);
  head->print();

  makeCircular(4, head);
  //head->print();
  Node* loopBegin = findLoopBegin2(head);
  cout << loopBegin->value << endl;

  /*string n1, n2;
  
  cin >> n1;
  cin >> n2;

  Node* head1 = NULL;
  Node* head2 = NULL;
  

  for (int i = n1.length() - 1; i >= 0; i--) {
    stringstream ss;
    ss << n1[i];
    int value;
    ss >> value;
    if(head1 == NULL)
      head1 = new Node(value);
    else
      head1->addNode(value);
  }
  for (int i = n2.length() - 1; i >= 0; i--) {
    stringstream ss;
    ss << n2[i];
    int value;
    ss >> value;
    if (head2 == NULL)
      head2 = new Node(value);
    else
      head2->addNode(value);
  }

  head1->print();
  head2->print();

  Node* head3 = addDigit2(head1, head2);
  head3->print();
*/
  return 0;
}
