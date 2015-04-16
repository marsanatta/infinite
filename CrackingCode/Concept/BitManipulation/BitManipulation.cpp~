#include "BitManipulation.h"
#include <iostream>

using namespace std;


int findIntFirstOnePos(int val) {
  int firstOnePos = -1;
  for (int i = 31; i >= 0; i--) {
    int temp = val;
    temp = temp >> i;
    temp &= 1;
    if (temp == 1) {
      firstOnePos = i;
      break;
    }
  }
  return firstOnePos;
}

string intToBinaryString(int val) {

  /*int firstOnePos = findIntFirstOnePos(val);
  if (firstOnePos == -1) {
    return string("0");
  }*/

  char buffer[33];
  buffer[32] = '\0';
  for (int i = 31; i >= 0; i--) {
    int bit = val & 1;
    char bitChar = bit + '0' ;
    buffer[i] = bitChar;
    val = val >> 1;
  }
  return string(buffer);

}

int stringToInt(string valStr) {
  if (valStr.length() == 0) {
    return 0;
  }
  int begin = 0;
  bool isNegative = false;
  int ret = 0;
  int len = valStr.length();
  //negative number
  if (valStr[0] == '-') {
    isNegative = true;
    begin++;
    len--;
  }
  for (int i = begin; i < valStr.length(); i++) {
    int digit = valStr[i] - '0';
    ret += digit * (int)pow(10.0, (double)(len-1-i));
  }
  return ret;
}
double getFloatPrecision(double value, double precision)
{
      return (floor((value * pow(10, precision) + 0.5)) / pow(10, precision)); 
}

void setBit(int &val, int pos, bool bit) {
  if (bit) {
    val = val | (1 << pos);
  }
  else {
    int mask = ~(1 << pos);
    val = val & mask;
  }
}

bool getBit(int val, int pos) {
  return (val & (1 << pos)) > 0;
}

