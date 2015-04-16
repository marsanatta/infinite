#include <iostream>

#define CALL_WITH_MAX(a, b) ((a)>(b)?(a):(b))

template<typename T>
inline T callWithMax(const T& a, const T& b) {
  return (a > b ? a:b);
}

int main() {

  int a = 5;
  int b = 0;
  std::cout << CALL_WITH_MAX(++a, b) << std::endl; //a++ * 2
  a = 5;
  b = 0;
  std::cout << CALL_WITH_MAX(++a, b+10) << std::endl;

  a = 5;
  b = 0;
  std::cout << callWithMax(a, b) << std::endl;

  return 0;
}
