#include <iostream>

using namespace std;

class Base{
  float v;
  virtual void fuck() = 0;
};

class Der : public Base{
  float v;
  virtual void fuck() {
  }
};

int main() {
  
  //dervied to base
  Der* der = new Der;
  Base* base = dynamic_cast<Base*>(der);

  //base to dervied
  base = new Der;
  der = dynamic_cast<Der*>(base);

  //reinterpret
  reinterpret_cast<long long>(base);

  //remove the const-ness from reference and pointers
  const int *test = new int(1);
  int* yo = const_cast<int*>(test);
  cout << *test << endl;
  *yo = 2;
  cout << *test << endl;

  return 0;
}
