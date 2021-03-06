#include <iostream>

using namespace std;

//pick means allowance to pick
int  count(int n, int pick) {
  int way = 0;
  if (n >= 25 && pick >= 25) {
    cout << "25 ";
    way += count(n - 25, 25);
  }
  if (n >= 10 && pick >= 10) {
    cout << "10 ";
    way += count(n - 10, 10);
  }
  if (n >= 5 && pick >= 5) {
    cout << "5 ";
    way += count(n-5, 5);
  }
  if (n >= 1) {
    cout << "1*" << n << endl;
    way++;
  }
  if (n == 0) {
    cout << "end" << endl;
    return 1;
  }
  return way;

}

int count2(int n, int denom) {
  int next_denom;
  switch (denom) {
  case 25:
    next_denom = 10;
    break;
  case 10:
    next_denom = 5;
    break;
  case 5:
    next_denom = 1;
    break;
  case 1:
    cout << "1*" << n;
    cout << " end" << endl;
    return 1;
  }
  int way = 0;
  for (int i = 0; i*denom <= n; i++ ) {
    cout << denom << "*" << i << " ";
    way += count2(n - i*denom, next_denom);
  }
  return way;
}

int main() {

  int n;

  while(true) {
    cin >> n;
    cout << count(n, 25) << " ways (sol1)" << endl;
    cout << count2(n, 25) << " ways (sol2)" << endl;
  }

  return 0;
}
