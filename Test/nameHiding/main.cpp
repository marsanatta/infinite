#include <iostream>

using namespace std;

class First{
public:
  virtual void MethodA (int);
  virtual void MethodA (int, int);
};

void First::MethodA (int i) {
  cout << "ONE!!" << endl;
}

void First::MethodA (int i, int j) {
  cout << "TWO!!" << endl;
}

class Second : public First{
public:
  virtual void MethodA (int) override;
  //virtual void MethodA (int, int) override;

};

void Second::MethodA (int i) {
  cout << "THREE!!" << endl;
}
/*void Second::MethodA (int i, int j) {
  cout << "FOUR!!" << endl;
}*/
int main() {
  Second a;
  a.MethodA(1);
  a.MethodA(1, 1);
}
