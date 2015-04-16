#include "linkedList.h"

int main() {

  LinkedList ll;
  ll.add(1);
  ll.add(100);
  ll.add(53);
  ll.print();
  ll.del(100);
  ll.del(101);
  ll.del(53);
  ll.print();
  return 0;
}
