#include <iostream>
#include <algorithm>
#include <vector>

typedef struct computer{
  int price;
  int quality;

  computer(int _price, int _quaility) : price(_price), quality(_quaility){}

}Computer;

struct less_than_price
{
  inline bool operator()(const Computer& c1, const Computer& c2){
    return (c1.price > c2.price);
  }
};

int main() {

  std::vector<Computer> computers;
  int numComputer;
  //read input
  std::cin >> numComputer;
  for (int i = 0; i < numComputer; i++) {
    int newPrice;
    int newQuality;
    std::cin >> newPrice;
    std::cin >> newQuality;
    Computer newComputer = Computer(newPrice, newQuality);
    computers.push_back(newComputer);
  }
  //sort
  std::sort(computers.begin(), computers.end(), less_than_price());

  /*for (int i = 0; i < computers.size(); i++) {
    std::cout << "#" << i << " price:" << computers[i].price << " quality:" << computers[i].quality << "\n";
  }*/
  //check Happy Alex or Poor Alex
  for (int i = 0; i < computers.size(); i++) {
    if((i+1) == computers.size()){
      break;
    }
    if(computers[i+1].quality > computers[i].quality){
      std::cout << "Happy Alex" << "\n";
      return 0;
    }
  }
  std::cout << "Poor Alex" << "\n";
  return 0;
}

