#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Stack {

private:
  vector<T> buffer;

public:
  void push(T value) {
    buffer.push_back(value);
  }

  T pop(){
    if (isEmpty()) {
      cout << "Stack Underflow" << endl;
      return NULL;
    }
    T ret = buffer.back();
    buffer.pop_back();
    return ret;
  }

  bool isEmpty() {
    return buffer.size() == 0 ? true : false;
  }

  T peak() {
    return buffer.back();
  }
};
