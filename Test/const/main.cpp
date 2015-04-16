#include <iostream>
#include <string>

using namespace std;

class TextBook {
public:
  const char& operator[] (size_t position) const {
    cout << "const version" << endl;
    return text[position];
  }
  char & operator[] (size_t position) {
    cout << "non-const version" << endl;
    return text[position];
  }
  TextBook(const string &text) {
    this->text = text;
  }

private:
  mutable string text;

};

int main() {

  TextBook tb("Hello");
  cout << tb[0] << endl;
  tb[0] = 'J';
  cout << tb[0] << endl;
  TextBook const ctb("Hello");
  cout << ctb[0] << endl;

  return 0;
}
