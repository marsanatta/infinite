#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>

using namespace std;

void useContainer(int k, ifstream &infile) {
  infile.unsetf(ios_base::skipws);
  int lineCount = 0;
  string line;
  list<string> lineList;
  while (getline(infile, line)) {
    lineCount++;
    if(lineCount > k) {
      lineList.pop_front();
      lineList.push_back(line);
    }
    else {
      lineList.push_back(line);
    }
  }

  for(auto s : lineList) {
    cout << s << endl;
  }
}

void bruteForce(int k, ifstream &infile) {
  
  infile.unsetf(ios_base::skipws);
  
  unsigned int lineCount = count(istream_iterator<char>(infile), istream_iterator<char>(), '\n');

  cout << "Lines:" << lineCount << endl;
  cout << "Print the last K lines:" << endl;
  infile.clear();
  infile.seekg(0);
  int curLine = 0;
  string line;
  while (getline(infile, line))
  {
    curLine++;
    //cout << curLine << endl;
    if(curLine > lineCount - k) {
      cout << line << endl;
    }
  }
}

int main() {

  int k;

  cin >> k;
  ifstream infile;
  infile.open("13-1.dat");
  //bruteForce(k, infile);
  useContainer(k, infile);


  return 0;
}
