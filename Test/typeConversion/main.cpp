#include <iostream>

using namespace std;

void PrintValues(int nValue) {
  cout << nValue << endl;
}
void PrintValues(int nValue, int nValue2 = 20) {
  cout << nValue << endl;
  cout << nValue2 << endl;
}

int main() {
  
  float fValue = 10 / 4;
  cout << fValue << endl;
  fValue = (float)10 / 4;
  cout << fValue << endl;
  
  PrintValues(10);
  

  
  
}
