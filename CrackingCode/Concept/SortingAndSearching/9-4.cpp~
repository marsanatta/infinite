//External sort
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <new>
#define CHUNK_SIZE 256
#define STRING_SIZE 32

using namespace std;

struct FileString {
  ifstream fp;
  string line;
  bool isEmpty;
};

int getStringValue(string &s) {
  int val = 0;
  for (int i = 0; i < s.length(); i++) {
    val += (int)(s[i]);
  }
  return val;
}

bool sortFunc(string a, string b) {
  return getStringValue(b) > getStringValue(a);
}

bool areChunkFilesEmpty(vector<FileString> &fss) {
  for (int i = 0; i < fss.size(); i++) {
    if(!fss[i].fp.eof())
      return false;
  }
  return true;
}

int main() {

  ifstream infile;
  ofstream outfile;
  infile.open("data.dat");
  string line;

  //get each chunk and sort them;
  int currentSize = 0;
  int numChunk = 0;
  vector<string> sv;

  string outname = "chunk";
  //outname += (char)('0' + numChunk);
  outname += to_string(numChunk);
  outname += ".dat";
  outfile.open(outname);

  while (!infile.eof()) {
    getline(infile, line);
    currentSize += STRING_SIZE;
    sv.push_back(line);
    cout << line << endl;
    if (currentSize == CHUNK_SIZE) {
      //sort them...
      cout << "sorting the chunk..." << endl;
      sort(sv.begin(), sv.end(), sortFunc);
      for (auto s : sv) {
        cout << s << "(" << getStringValue(s) << ")" <<endl;
        outfile << s << endl;
      }
      //reset
      currentSize = 0;
      numChunk++;
      sv.clear();

      outname.clear();
      outname = "chunk";
      outname += to_string(numChunk);
      outname += ".dat";
      outfile.close();
      outfile.open(outname);
    }
  }
  outfile.close();
  remove(outname.c_str()); // remove the last chunk file

  //set file pointers to each chunk file
  vector<FileString> fss(numChunk);
  for (int i = 0; i < numChunk; i++) {
    string fname = "chunk";
    fname += to_string(i);
    fname += ".dat";
    fss[i].fp.open(fname);
    getline(fss[i].fp, fss[i].line);
    fss[i].isEmpty = false;
  }
  outfile.open("out.dat");
  while(!areChunkFilesEmpty(fss)) {
    //find the min string in fss
    int min = INT_MAX;
    int minIdx = -1;
    for (int i = 0; i < numChunk; i++) {

      if (fss[i].isEmpty) {
        continue;
      }
      
      int strVal = getStringValue(fss[i].line);
      if (strVal < min) {
        min = strVal;
        minIdx = i;
      }
    }
    //output the min string
    cout << fss[minIdx].line << "(" << getStringValue(fss[minIdx].line) << ")" << endl;
    outfile << fss[minIdx].line << endl;
    if (!fss[minIdx].fp.eof()) {
      getline(fss[minIdx].fp, fss[minIdx].line);
    }
    if (fss[minIdx].line == "") {
      fss[minIdx].isEmpty = true;
    }
  }
  
  infile.close();
  outfile.close();
  for (int i = 0; i < numChunk; i++) {
    fss[i].fp.close();
    string fname = "chunk" + to_string(i) + ".dat";
    remove(fname.c_str());
  }
  return 0;
}
