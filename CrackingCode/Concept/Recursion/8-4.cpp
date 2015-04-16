#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getAllPermutations(string const &s, int len) {
  vector<string> perms;
  string appendStr;
  appendStr += s[len-1];
  if (len == 1) {
    perms.push_back(appendStr);
    return perms;
  }
  vector<string> tempPerms = getAllPermutations(s, len - 1);
  for (auto perm : tempPerms) {
    for (int i = 0; i < perm.length()+1; i++) {
      string newPerm(perm);
      newPerm.insert(i, appendStr);
      perms.push_back(newPerm);
    }
  }
  return perms;
}

vector<string> getAllPermutations2(string const &s) {
  vector<string> perms;
  string appendStr;
  appendStr += s[0];
  if (s.length() == 1) {
    perms.push_back(appendStr);
    return perms;
  }
  vector<string> words = getAllPermutations2(s.substr(1, s.length()-1));
  for (auto w : words) {
  
    for (int i = 0; i < w.length() + 1; i++) {
      string newPerm(w);
      newPerm.insert(i, appendStr);
      perms.push_back(newPerm);
    }
  }
  return perms;
}

int main() {

  string s;
  cin >> s;
  vector<string> perms = getAllPermutations2(s);
  for (auto s : perms) {
    cout << s << endl;
  }
  return 0;
}
