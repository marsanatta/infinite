#include <string>
#include <iostream>

using namespace std;

int main() {

  string a("fg");
  string b("gf");

  cout << b.compare(a) << endl;
  cout << b.substr(2, 0);

  return 0;
}
