#include <iostream>
#include <vector>
#include <string>

using namespace std;

unsigned int countDelete(string const &s) {
  char c = s[0];
  int cntDelete = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == c) {
      cntDelete++;
    }
    else {
      c = s[i];
    }
  }
  return cntDelete;
}

int main() {

  int T;
  vector<string> strs;
  cin >> T;
  for (int i = 0; i < T; i++) {
    string s;
    cin >> s;
    strs.push_back(s);
  }
  for (int i = 0; i < T; i++) {
    cout << countDelete(strs.at(i)) << endl;
  }

  return 0;
}
