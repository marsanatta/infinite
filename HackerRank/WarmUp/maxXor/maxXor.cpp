#include <iostream>
#include <climits>

using namespace std;

bool getBitAt(unsigned int const & val, int idx) {
  unsigned int bit;
  bit = (val >> idx) & 1;
  if (bit == 1)
    return true;
  else if (bit == 0)
    return false;
  else {
    cout << "This shit could not happen... REAL?" << endl;
    return false;
  }
}

unsigned int countDigit(unsigned int const & val) {
  int len = 0;
  for (int i = 0; i < 32; i++) {
    if (getBitAt(val, i)) {
      len = i+1;
    }
  }
  return len;
}

void printBinary(unsigned int const & val) {
  unsigned int len = countDigit(val);
  for (int i = len - 1; i >= 0; i--) {
    cout << getBitAt(val, i);
  }
  cout << endl;
}

unsigned int maxXor(unsigned int const &l, unsigned int const &r) {
  unsigned int max = 0;
  for (int i = l; i <= r; i++) {
    for (int j = l; j <= r; j++) {
      if ((i^j) > max)
        max = i^j;
    }
  }
  return max;
}

int main() {

  unsigned int l, r;
  cin >> l;
  cin >> r;
  cout << maxXor(l, r) << endl;

  return 0;
}
