#include <iostream>
#include <vector>
#include <string>
#include "A.h"

using namespace std;

int main() {

  //A a(100);
  //cout << a.getValue() << endl;
  //cout << a.getValue2() << endl;

  vector<A> vs;
  for (int i = 0; i < 10; i++) {
    A v = A(i, to_string((char)('0'+i)));
    cout << "v addr: " << &v << endl;
    vs.push_back(v);
  }
  for (int i = 0; i < 10; i++) {
    cout << "addr: " << &(vs.at(i)) << " " << vs.at(i).getStr() << endl;
  }

  return 0;
}
