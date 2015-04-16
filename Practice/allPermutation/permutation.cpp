#include <cstring>
#include <vector>
using namespace std;

string insert_char(string word, char c, int index) {
  string start = word.substr(0, index);
  string end = word.substr(index);
  return start + c + end;
}

vector<string> get_permutations(string s) {
  vector<string> permutations;
  if (s.length() == 0) {
    permutations.push_back("");
    return permutations;
  }
  char first = s[0];
  string remainder = s.substr(1);
  vector<string> words = get_permutations(remainder);
  for (string w : words) {
    for (int i = 0; i <= w.size(); ++i) {
      permutations.push_back(insert_char(w, first, i));
    }
  }
  return permutations;
}

int main (int argc, char **argv) {
  string s = "abc";
  vector<string> permutations = get_permutations(s);
  for (string s : permutations) {
    cout << s << endl;
  }
  return 0;
}
