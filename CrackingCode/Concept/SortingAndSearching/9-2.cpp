#include <iostream>
#include <cstdlib>
#include <string>
#include <new>
#include <vector>
#include <algorithm>

using namespace std;

struct valueString {
  string s;
  int val;
  valueString(string _s) {
    s = _s;
    val = 0;
    for (int i = 0; i < s.length(); i++) {
      val += (int)(s[i]);
    }
  }
  valueString() {}
};

void vsSwap(valueString &vs1, valueString &vs2) {
  valueString temp = vs2;
  vs2 = vs1;
  vs1 = temp;
  return;
}

void sortAnagrams(valueString *vss, int left, int right) {


  if (left >= right) {
    return;
  }
  int mid = (left + right) / 2;
  int pivot = vss[mid].val;
  //cout << "pivot" << pivot << endl;
  swap(vss[left], vss[mid]);
  //cout << "d1" << endl;
  int i = left + 1;
  int j = right;
  //cout << "d1-1" << endl;
  while (i <= j) {
    //cout << "d1-2" << endl;
    while (vss[j].val > pivot)
      j--;
    while (i <= j && vss[i].val <= pivot)
      i++;
    //cout << "d3" << endl;
    if (i <= j) {
      swap(vss[i], vss[j]);
      //cout << "d4" << endl;
      i++;
      j--;
    }
    //cout << "d5" << endl;
  }
  //cout << "i:" << i << "j:" << j << endl;
  swap(vss[left], vss[j]);
  sortAnagrams(vss, left, j - 1);
  sortAnagrams(vss, j + 1, right);
}

bool func(valueString s1, valueString s2) {
  return (s1.val < s2.val);
}

int main() {

  int n;
  cin >> n;
  vector<valueString> vsVec;
  valueString *vss = new valueString[n];
  for (int i = 0; i < n; i++) {
    string newS;
    cin >> newS;
    vss[i] = valueString(newS);
    vsVec.push_back(vss[i]);
  }

  /*for (int i = 0; i < n; i++) {
    cout << vss[i].s << "(" << vss[i].val << ")" << endl;
  }

  sortAnagrams(vss, 0, n - 1);

  cout << "sorted:" << endl;
  for (int i = 0; i < n; i++) {
    cout << vss[i].s << "(" << vss[i].val << ")" << endl;
  }*/
  
  for (auto vs : vsVec) {
    cout << vs.s << "(" << vs.val << ")" << endl;
  }

  sort(vsVec.begin(), vsVec.end(), func);

  for (auto vs : vsVec) {
    cout << vs.s << "(" << vs.val << ")" << endl;
  }


  return 0;
}
