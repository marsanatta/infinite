#include <iostream>

using namespace std;

class Parent{
public:
  virtual void foo() {
    cout << "Parent" << endl;
  }
};

class ChildLeft : public Parent{
public:
  ChildLeft()
  : Parent()
  {
  }
  virtual void foo() {
    cout << "Child Left" << endl;
  }
};

class ChildRight : public Parent{
public:
  ChildRight() 
  : Parent()
  {
  
  }
  virtual void foo() {
    cout << "Child Right" << endl;
  }
};

class GrandChild : public ChildLeft, public ChildRight{
public:
  GrandChild() 
  : ChildLeft(), ChildRight()
  {
  
  }
  virtual void foo() {
    ChildRight::foo();
  }
};

int main() {
  GrandChild gc;
  gc.foo();
  gc.ChildLeft::foo();
}
