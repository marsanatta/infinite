#include <iostream>
#include <cstring>
#include "BitManipulation.h"
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void getFrontBack(string valStr, int &front, double &back) {

  if (valStr.length() == 0) {
    front = 0;
    back = 0;
    return;
  }
  int idx = 0;
  string frontStr;
  while (valStr[idx] != '.' && idx < valStr.length()) {
    frontStr += valStr[idx];
    idx++;
  }

  idx++; //jump to the '.''s back
  string backStr;
  while (idx < valStr.length()) {
    backStr += valStr[idx];
    idx++;
  }

  front = stringToInt(frontStr);
  back = (double)stringToInt(backStr);
  back /= pow(10.0, (double)backStr.length());
}

string getBinaryString(int front, double back) {
  
  string out("");

  int temp1 = front;
  if (temp1 == 0) {
    out+= '0';
    goto countBack;
  
  }
  while (temp1 != 1) {
    int re = temp1 % 2;
    temp1 /= 2;
    //out = (char)(re + '0') + out;
    out.insert(out.begin(), (char)(re+'0'));
  }
  out = string("1") + out;

countBack:
  
  list<double> bQ;
  double temp2 = back;
  if (temp2 != 0) {
    out += '.';
  }
  while (temp2 != 0) {
    temp2 *= 2;
    temp2 = getFloatPrecision(temp2, 2);
    if (temp2 >= 1) {
      out += '1';
      temp2 -= 1;
    }
    else{
      out += '0';
    }
    list<double>::iterator findIter = std::find(bQ.begin(), bQ.end(), temp2);
    if (findIter != bQ.end()) {
      out = string("ERROR");
      return out;
    }
    bQ.push_back(temp2);
  }
  return out;
}

int main() {

  string valStr;
  cin >> valStr;
  cout.precision(15);
  int front;
  double back;
  getFrontBack(valStr, front, back);
  cout << front << endl;
  cout << back << endl;
  cout << getBinaryString(front, back) << endl;

  return 0;
}
