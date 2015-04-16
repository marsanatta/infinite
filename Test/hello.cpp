#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Foo {

public:
  void setF(int _f){ f = _f; }
  int getF() { return f; }
  Foo(int _f) : f(_f) {}

private:
  int f;
};

int main(){
	//std::cout << "Hello, World!" << std::endl;
  /*int a = 1;
  int* ptr = &a;
  cout << "ptr addr: " << &ptr << endl;
  cout << "ptr value: " << *ptr << endl;
  cout << "ptr point to addr: " << ptr << endl;
  ptr = *ptr - 1;
  *ptr++; // ptr = ptr+1 & *ptr
  cout << "ptr addr: " << &ptr << endl;
  cout << "ptr value: " << *ptr << endl;
  cout << "ptr point to addr: " << ptr << endl;
 
  int &ref = a;
  cout << "ref:" << ref << endl;
  
  std::string s = std::to_string(42);
  cout << "s:" << s << endl;
  */

  /*vector<Foo> foos;
  for (int i = 1; i <= 5; i++) {
    Foo *newFoo = new Foo(i);
    foos.push_back(*newFoo);
  }
  for (auto foo : foos) {
    cout << foo.getF() << endl;
    foo.setF(100);
  }
  for (auto &foo: foos) {
    cout << foo.getF() << endl;
  }
  */

  /*int arr[5][5];
  cout << arr << endl;
  for (int i = 0; i < 5; i++) {
    cout << &arr[i] << endl;
  }
  
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << &arr[i][j] << " ";
    }
    cout << endl;
    }*/

  /*int a[10];
  int b[20];
  int *aptr = a;
  int *bptr = b;
  cout << sizeof(a) << endl;
  cout << sizeof(b) << endl;
  cout << sizeof(aptr) << endl;
  cout << sizeof(bptr) << endl;*/

  /*char company1[10] = "VIVOTEK";
  char company2[] = "VIVOTEK";
  char *company3 = "VIVOTEK";
*/

  //cout << sizeof(int) << endl;

  int n = 10;
  int &rn = n;

  cout << &n << endl;
  cout << &rn << endl;

  return 0;
}
