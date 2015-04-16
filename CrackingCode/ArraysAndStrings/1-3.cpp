#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool hasAppeared[256];

//O(n)
string removeDuplicates1(string s){
  
  string output = "";

  for (int i = 0; i < s.length(); i++) {
    if (hasAppeared[s[i]])
      continue;
    hasAppeared[s[i]] = true;
    output += s[i];
  }
  
  return output;

}


//O(n^2)
string removeDuplicates2(string s){

  string output = "";
  output += s[0];

  if (s.length() < 2) {
    return s;
  }
  
  for (int i = 1; i < s.length(); i++) {
    int j;
    for (j = 0; j < i; j++) {
      if(s[i] == s[j]){
        break; //s[i] is duplicated; ignore it
      }
    }
    if(j == i){//s[i] is not duplicated
      output += s[i];
    }
  }
  return output;
}

//O(n^2) second
string removeDuplicates3(string s){

  if (s.length() < 2) {
    return s;
  }
  int tail = 1;

  for (int i = 1; i < s.length(); i++) {
    int j;
    for (j = 0; j < i; j++) {
      if(s[i] == s[j]){
        break; //s[i] is duplicated; ignore it
      }
    }
    if(j == i){//s[i] is not duplicated
      s[tail] = s[i];
      tail++;
    }
  }
  //s[tail] = '\0';
  s.erase(tail, s.length()-tail);
  return s;
  
}

int main() {

  string s;
  cin >> s;
  cout << "way1: " << removeDuplicates1(s) << endl;
  cout << "way2: " << removeDuplicates2(s) << endl;
  cout << "way3: " << removeDuplicates3(s) << endl;
  //printf("way3: %s\n", removeDuplicates3(s).c_str());

  return 0;
}
