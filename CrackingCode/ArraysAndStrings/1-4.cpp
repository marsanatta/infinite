#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//O(nlogn)
bool areAnagrams1(string s1, string s2){
  
  if(s1.length() != s2.length())
    return false;

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] != s2[i]) {
      return false;
    }
  }
  return true;
}
//O(n)
int cnt1[256];
int cnt2[256];

bool areAnagrams2(string s1, string s2){
  
  if(s1.length() != s2.length())
    return false;
  
  for (int i = 0; i < s1.length(); i++) {
    cnt1[s1[i]]++;
    cnt2[s2[i]]++;
  }

  for (int i = 0; i < 256; i++) {
    if (cnt1[i] != cnt2[i])
      return false;
  }
  return true;
  
}


int main() {
  
  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout.setf(ios::boolalpha);
  cout << "way1: " << areAnagrams1(s1, s2) << endl;
  cout << "way2: " << areAnagrams2(s1, s2) << endl;
  

  return 0;
}
