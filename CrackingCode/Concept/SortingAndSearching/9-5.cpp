#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#define STRING_SIZE 3

using namespace std;

int getStringValue(string s) {
  int val = 0;
  for (int i = 0; i < s.length(); i++) {
    val += (int)(s[i]);
  }
  return val;
}

string randomGenerateString() {
  string newStr;
  for (int i = 0; i < STRING_SIZE; i++) {
    newStr += (char)('A' + rand()%26);
  }
  return newStr;
}

int binarySearch(string *strs, int left, int right, string const &find) {
  
  if (left > right) {
    return -1;
  }
  int mid = left + (right - left) / 2;
  int idx = mid;
  cout << "left:" << left << "right:" << right << "mid:" << mid << endl;
  while (idx <= right){
    if (strs[idx] != "") break;
    idx++;
  }
  if (idx > right)
    return binarySearch(strs, left, mid - 1, find);
  cout << "idx:" << idx << "strs[idx]" << strs[idx] << endl;
  if (strs[idx] == find)
    return idx;
  if (getStringValue(strs[idx]) > getStringValue(find))
    return binarySearch(strs, left, mid - 1, find);
  if (getStringValue(strs[idx]) < getStringValue(find))
    return binarySearch(strs, idx + 1, right, find);
}

bool sortFunc(string a, string b) {
  return getStringValue(a) < getStringValue(b);
}

bool validate(vector<string> &strv, string newStr) {
  for (auto s : strv) {
    if(getStringValue(s) == getStringValue(newStr))
      return false;
  }
  return true;
}

int main() {

  int n;
  cin >> n;
  string *strs = new string[n];
  srand(time(NULL));

  int numEmpty = 0 + rand()%(n+1);
  cout << "num of empties:" << numEmpty << endl;
  vector<string> strv;
  for (int i = 0; i < n - numEmpty; i++) {
    string newStr = randomGenerateString();
    bool isValid = validate(strv, newStr);
    if (isValid) {
      strv.push_back(newStr);
    }
    else {
      i--;
    }
  }
  sort(strv.begin(), strv.end(), sortFunc);
  for (int i = 0; i < numEmpty; i++) {
    int pos = 0 + rand()%(strv.size() + 1);
    strv.insert(strv.begin() + pos, "");
  }
  
  for (int i = 0; i < n; i++) {
    cout << i << strv[i] << "(" << getStringValue(strv[i]) << ")" <<endl;
    strs[i] = strv[i];
  }

  while(true) {
    cout << "Enter the string you want to find:";
    string find;
    cin >> find;
    cout << binarySearch(strs, 0, n - 1, find) << endl;
  }

  return 0;
}
