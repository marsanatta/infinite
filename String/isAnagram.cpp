#include <iostream>
#include <string>
using namespace std;
const static int ASCII = 256;
bool isAnagram(const string &s1, const string &s2) {
    int freq1[ASCII];
    int freq2[ASCII];
    for (int i = 0; i < ASCII; i++) {
        freq1[i] = 0;
        freq2[i] = 0;
    }

    if ( s1.length() != s2.length() ) return false;
    for (int i = 0; i < s1.length(); i++) {
        freq1[s1[i]]++;
        freq2[s2[i]]++; 
    }
    for (int i = 0; i < ASCII; i++) {
         if (freq1[i] != freq2[i]) {
            return false; 
         }
    }
    return true;
}

int main(int argc, const char *argv[])
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << isAnagram(s1, s2) << endl;
    return 0;
}
