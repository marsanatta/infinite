#include <iostream>

using namespace std;

int main() {

  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    unsigned int val, out;
    cin >> val;
    out = ~val;
    cout << out << endl;
  }
  return 0;
}
