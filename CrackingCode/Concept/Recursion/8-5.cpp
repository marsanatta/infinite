#include <iostream>

using namespace std;

void printPar(int left, int right, char* str, int count) {
  if (left < 0 || left > right)
    return;
  if (left == 0 && right == 0)
    cout << str << endl;
  else {
    if (left > 0) {
      str[count] = '(';
      printPar(left - 1, right, str, count+1);
    }
    if (right > left) {
      str[count] = ')';
      printPar(left, right - 1, str, count+1);
    }
  }
}
void printPar(int count) {
  char *str = new char[count*2];
  printPar(count, count, str, 0);
}

int main() {

  int n;
  cin >> n;
  printPar(n);
  return 0;
}
