#include <iostream>

class ParentClass
{
public:
  void someFunction(float f){ };
};

class ChildClass : public ParentClass
{
public:
  int someFunction(int i){};

  /*This makes the someFunction
   *        declaration in ParentClass visible
   *               here as well:
   *                   */
  //using ParentClass::someFunction;
};

class GrandChildClass : public ChildClass
{
public:
  void differentFunction()
  {
    float f;
    someFunction(f);

  }
};

int main() {
  
  return 0;
}
