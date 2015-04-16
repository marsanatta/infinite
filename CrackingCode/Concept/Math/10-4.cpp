#include <iostream>
#include <cmath>

using namespace std;

int flip(int n) {
  int d;
  if (n > 0)
    d = -1;
  else
    d = 1;
  int ret = 0;
  for (int i = 0; i < abs(n); i++) {
    ret += d;
  }
  return ret;
}

int multiply(int n1, int n2) {

  int ret = 0;
  for (int i = 0; i < abs(n2); i++) {
    ret += abs(n1);
  }
  if ((n2 < 0 && n1 > 0) || (n2 > 0 && n1 < 0)) ret = flip(ret);
  return ret;
}

int subtract(int n1, int n2) {
  /*if (n1 < 0 && n2 < 0) {
    return flip(abs(n1) + abs(n2));
  }*/
  return n1 + flip(n2);
}

int divide(int n1, int n2) {
  if (n1 < 0 && n2 < 0) {
    if(abs(n1) > abs(n2)) 
      return divide(abs(n1), abs(n2));
    else
      return divide(abs(n2), abs(n1));
  }

  if (n1 < n2) 
    return divide(n2, n1);
  if (n1 > 0 && n2 < 0) {
    if(abs(n1) > abs(n2))
      return flip(divide(abs(n1), abs(n2)));
    else
      return flip(divide(abs(n2), abs(n1)));
  }

  
  int ret = 0;
  int temp = abs(n1);
  while(temp != 0) {
    temp += flip(abs(n2));
    ret++;
  }
  if (n1 > 0 && n2 < 0) {
    ret = flip(ret);
  }
  return ret;
}

int main() {

  int n1;
  int n2;
  cin >> n1 >> n2;
  cout << "*:" << multiply(n1, n2) << endl;
  cout << "-:" << subtract(n1, n2) << endl;
  cout << "/:" << divide(n1, n2) << endl;
  return 0;
}
