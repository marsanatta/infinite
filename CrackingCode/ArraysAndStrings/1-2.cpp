#include <iostream>
#include <cstring>

using namespace std;


void swap(string& s, int idx1, int idx2){
  char tempC = s[idx1];
  s[idx1] = s[idx2];
  s[idx2] = tempC;
}

string reverseString(string s){

  for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
    swap(s, i, j);
  }
  return s;
}

int main() {

  string s;
  cin >> s;

  cout << reverseString(s) << endl;

  return 0;
}
