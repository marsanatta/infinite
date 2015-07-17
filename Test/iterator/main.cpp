#include <vector>
#include <iostream>

int main() {

  std::vector<int> v{3, 1, 4, 1, 5, 9};

  for (auto it = v.begin() ; it != std::next(v.begin() ,v.size()/2); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  auto it = std::prev(v.end());
  //auto it = v.end();
  std::cout << *it << std::endl;

  return 0;
}
