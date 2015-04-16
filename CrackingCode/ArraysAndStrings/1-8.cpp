#include <iostream>
#include <cstring>

using namespace std;

bool isSubstring(string s1, string s2) {
  if (s1.length() < s2.length()) {
    return false;
  }
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == s2[0]) {

      if (i+s2.length() > s1.length()){
        return false;
      }
      bool continueFlag = false;
      for (int j = 1; j < s2.length(); j++) {
        if (s1[i+j] != s2[j]){
          continueFlag = true;
          break;
        }
      }
      if(continueFlag)
        continue;

      return true;
    }
  }
  return false;
}

bool isRotation(string s1, string s2) {
  if (s1.length() != s2.length()) {
    return false;
  }
  s2 += s2;
  return isSubstring(s2, s1);
}

int main() {

  string s1, s2;

  cin >> s1;
  cin >> s2;
  
  cout.setf(ios::boolalpha);
  cout << isRotation(s1, s2) << endl;

  return 0;
}
