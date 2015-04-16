#include <iostream>
#include <sstream>

using namespace std;

int main() {

  int n;
  string s, lastTwoDigit;
  int oneRemainder, twoRemainder, threeRemainder, fourRemainder;
  int sumRemainder;
  
  cin >> s;
  if(s.size() >= 2)
    lastTwoDigit = s.substr(s.size() - 2, 2);
  else
    lastTwoDigit = s.substr(s.size() - 1, 1);


  istringstream buffer(lastTwoDigit);
  buffer >> n;


  oneRemainder = 1;
  if(n % 4 == 1){
    twoRemainder = 2;
    threeRemainder = 3;
    fourRemainder = 4;
  }
  else if(n % 4 == 2){
    twoRemainder = 4;
    threeRemainder = 4;
    fourRemainder = 1;
  }
  else if(n % 4 == 3){
    twoRemainder = 3;
    threeRemainder = 2;
    fourRemainder = 4;
  }
  else if(n % 4 == 0){
    twoRemainder = 1;
    threeRemainder = 1;
    fourRemainder = 1;
  }

  /*
  if (n % 2 == 1) {
    fourRemainder = 4;
  }
  else if (n % 2 == 0){
    fourRemainder = 1;
  }
  */

  sumRemainder = oneRemainder + twoRemainder + threeRemainder + fourRemainder;

  if(sumRemainder >= 5)
    sumRemainder %= 5;

  cout << sumRemainder << "\n";

  return 0;
}
