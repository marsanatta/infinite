#include <iostream>
#include "hash.h"


int main() {

  Hash<int, int, KeyHash<int> > hash;
  hash.put(1, 2);
  std::cout << hash.get(1, 2) << std::endl;
  std::cout << hash.get(1, 3) << std::endl;
  std::cout << hash.get(2, 3) << std::endl;


  return 0;
}
