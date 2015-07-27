#include <string>
#include <iostream>

using namespace std;

string numToBinStr(const int &n) {
    string s;
    if (n == 0) return string("0");
    int d = n;
    while( d!= 1) {
        s.insert(s.begin(), '0' + (d%2));
        d /= 2;
    }
    s.insert(s.begin(), '1');
    return s;
}

int main(int argc, const char *argv[])
{
    while(true) {
        int n;
        std::cin >> n;
        std::cout << "its binary is:" << std::endl;
        std::cout << numToBinStr(n) << std::endl;
    }
    return 0;
}
