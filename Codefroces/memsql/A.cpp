#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

double qExp[100001];
static double q;

double getDecimal(string n){
  double result = 0.0;
  int numDigit = (int)n.size();
  for (int i = numDigit-1 ; i >= 0; i--) {
    int digit;
    if(n[i] == '1')
      digit = 1;
    else if(n[i] == '0')
      digit = 0;
    
    double qexp;
    if(qExp[numDigit-1-i] != -1.0)
      qexp = qExp[numDigit-1-i];
    else{
      qexp = pow(q, numDigit-1-i);
      qExp[numDigit-1-i] = qexp;
    }
    result += digit * qexp;
  }
  return result;
}

int main() {

  string n1, n2;
  //init
  q = 1.618033988;
  for (int i = 0; i < 100001; i++) {
    qExp[i] = -1.0;
  }

  cin >> n1;
  cin >> n2;

  double r1, r2;

  r1 = getDecimal(n1);
  r2 = getDecimal(n2);

  if(fabs(r1 - r2) <= 0.000999){
    cout << "=";
  }
  else if(r1 > r2){
    cout << ">";
  }
  else if(r1 < r2){
    cout << "<";
  }
  else{
    cout << "=";
  }

  return 0;
}
