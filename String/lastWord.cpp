#include <iostream>
#include <string>

using namespace std;

int lengthOfTheLastWord(const char *s) {
    //while (*s) {
        //std::cout << *s << std::endl;
        //if ( *s++ != ' ') {
            //out++;
        //}
        //else if (*s && *s != ' ') { 
            //out = 0; //reset
        //}
    //}
    //return out;
    int out = 0;
    string lastWord;
    bool space = false;
    while(*s) {
        if (*s != ' ' && space) {
            space = false;
            out = 1;
        }
        else if (*s != ' ' && !space) {
            out++;
        }
        else {
            space = true; 
        }
        std::cout << *s << " out:" << out << std::endl;
        s++;
    }
    return out;
}

void removeSpaces(char *s) {
}

int main(int argc, const char *argv[])
{
    string in("   Hello  Worldasdf  x ");    
    std::cout << lengthOfTheLastWord(in.c_str()) << std::endl;
    char *s = new char[in.length() + 1];
    s[in.length() + 1] = '\0';
    for (int i = 0; i < in.length(); i++) {
        s[i] = in[i];
    }
    std::cout << s << std::endl;
    int si = 0;
    for (int i = 0; i < in.length(); i++) {
        if (s[i] != ' ') {
            s[si] = s[i];
            si++;
        }
    }
    s[si] = '\0';
    std::cout << s << std::endl;
    if (!'\0')
        std::cout << "YES" << std::endl;
    return 0;
}
