#include <iostream>
#include <sstream>
#include <string>
void replaceSpace(char* s, int len) {
    int spaceCnt = 0;
    for (int i = 0; i < len; i++) {
       if (s[i] == ' ')
           spaceCnt++;
    }

    int newLen = len + spaceCnt * 2; 
    s[newLen] = '\0';
    for (int i = len - 1; i >= 0; i--) {
       if (s[i] == ' ') {
           s[newLen - 1] = '0';
           s[newLen - 2] = '2';
           s[newLen - 3] = '%';
           newLen -= 3;
       }
       else {
            s[newLen - 1] = s[i];
            newLen -= 1;
       }
    }

}
int strLen(char* s) {
    int idx = 0;
    while (s[idx] != '\0') {
       idx++; 
    }
    return idx;
}

void strCpy(char* s, std::string str) {
    for (int i = 0; i < str.length(); i++) {
       s[i] = str[i];
    }
    s[str.length()] = '\0';
}
int main(int argc, const char *argv[])
{
    char s[128];
    std::string str;
    std::getline(std::cin, str);
    strCpy(s, str);
    replaceSpace(s, strLen(s));
    std::cout << s << std::endl;    
    return 0;
}

