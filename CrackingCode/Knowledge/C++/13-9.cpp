#include <iostream>
#include "13-9.h"

using namespace std;

int main() {
  SmartPointer<int> sp(new int(10));
  cout << *sp.getRef() << endl;
  cout << sp.getRefCount() << endl;
  SmartPointer<int> sp2 = sp;
  sp.reset();
  cout << *sp2.getRef() << endl;
  cout << sp2.getRefCount() << endl;
  SmartPointer<int> sp3 = sp2;
  cout << sp2.getRefCount() << endl;
  SmartPointer<int> sp4(sp2);
  cout << sp4.getRefCount() << endl;
  return 0;
}
