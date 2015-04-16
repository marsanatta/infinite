#include <iostream>
#include <cstring>

using namespace std;

void cppswap(string& s, int idx1, int idx2){
  char tempC;
  tempC = s[idx1];
  s[idx1] = s[idx2];
  s[idx2] = tempC;
}

string reverseString(string s){
  for (int i = 0, j = s.length()-1; i <= j; i++, j--) {
    cppswap(s, i, j);
  }
  return s;
}

void swap(char &c1, char &c2) {
  char temp = c1;
  c1 = c2;
  c2 = temp;
}

void reverse(char *str, int length) {
  int i = 0;
  int j = length - 1;
  while (i < j) {
    swap(str[i], str[j]);
    i++;
    j--;
  }
}

int main() {

  string s;
  cin >> s;
  cout << reverseString(s) << endl;

  reverse(const_cast<char*>(s.c_str()), s.length());
  cout << s << endl;

  return 0;
}
