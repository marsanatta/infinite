#include <string>

using std::string;

class A {

public:
  A(int _value, string s) {
    value = _value;
    str = s;
  }
  int getValue() { return value; }
  int getValue2() { return value2; }
  string getStr() { return str; }
private:
  int value;
  static const int value2 = 2;//in-class initialization
  string str;
};
