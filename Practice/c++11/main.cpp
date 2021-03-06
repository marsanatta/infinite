#include <iostream>

using namespace std;

class Foo
{
private:
  int x;
  int y;
public:
  Foo(int x, int y): x(x), y(y){
    
  }
  //Foo() = default;
  Foo() {
  }
  int getX() {
    return x;
  }
  int getY() {
    return y;
  }
};

int main() {

  static_assert(__cplusplus > 12L, "c++11");

  int *p = nullptr;
  if (p == NULL)
    cout << "same" << endl;
  if (p == 0)
    cout << "same again" << endl;

  Foo f1(1, 11);
  //Foo f2(f1); //test copy constructor
  Foo f3(f1);
  f3 = f1; //assignment
  cout << f3.getX() << " " << f3.getY() << endl;
  return 0;
}
