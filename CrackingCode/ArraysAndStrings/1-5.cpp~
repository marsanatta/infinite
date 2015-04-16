#include <iostream>
#include <cstring>

using namespace std;

string replaceSpaceWith(string s, string replace){
  for (int i = 0; i < s.length(); i++) {
    if(s[i] == ' '){
      s = s.substr(0, i) + replace + s.substr(i+1, s.length()-(i+1));
      i += 2;
    }
  }
  return s;
}

int main() {

  string s;
  char buf[256];
  //cin >> s;
  cin.getline(buf, 256);
  s = buf;

  string replace = "%20";
  cout << replaceSpaceWith(s, replace) << endl;

  return 0;
}
