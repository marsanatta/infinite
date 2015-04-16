#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#define STRING_SIZE 32

using namespace std;

string randomGenerateString() {
  string newStr;
  for (int i = 0; i < STRING_SIZE; i++) {
    newStr += (char)(32 + rand()%95);
  }
  return newStr;
}

int main() {

  int n;
  cout << "Enter the data size(Bytes):";
  cin >> n;
  
  ofstream outfile("data.dat");
  int numString = n / (STRING_SIZE * sizeof(char));
  srand(time(NULL));
  for (int i = 0; i < numString; i++) {
    outfile << randomGenerateString() << endl;
  }

  outfile.close();
  return 0;
}
