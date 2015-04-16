#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;


string insert_char(const string word, char c, int index){
  string start = word.substr(0, index);
  string end = word.substr(index);
  return start + c + end;
}

vector<string> stringPermutation(string s){

  vector<string> permutations;
  if (s.length() == 1) {
    permutations.push_back(s);
    return permutations;
  }
  char last = s[s.length()-1];
  string remainder = s.substr(0, s.length()-1);
  vector<string> words = stringPermutation(remainder);
  for (string w : words) {
    for (int i = 0; i <= w.size(); i++) {
      permutations.push_back(insert_char(w, last, i));
    }
  }
  return permutations;
}

void printAllPermutation(string s){

  vector<string> permutations;
  permutations = stringPermutation(s);
  for (const string& p : permutations) {
    cout << p << endl;
  }
}

int main() {

  string s;
  cin >> s;

  /*sort(s.begin(), s.end());
  do {
    cout << s << "\n";
  } while(next_permutation(s.begin(), s.end()));
  */


  printAllPermutation(s);

  return 0;
}
