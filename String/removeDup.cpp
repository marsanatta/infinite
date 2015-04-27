#include <iostream>
#include <cstddef>
void removeDup(char* s, int len) {
    if (s == NULL) return;
    if (len < 2 ) return;
    int tail = 1;
    for (int i = 1; i < len; i++) {
        int j;
        for (j = 0; j < tail; j++) {
            // skip if it's a duplicated character
            if (s[i] == s[j]) break;
        }
        // if it's unique, keep it
        // in-place and retain the order
        if (j == tail) {
            s[tail] = s[i];
            tail++;
        }
        
    }
    s[tail] = '\0';
};
void removeDup2(char* s, int len) {
    if (s == NULL) return;
    if (len < 2) return;
    bool hit[256];
    for (int i = 0; i < 256; i++) {
        hit[i] = false;
    }
    hit[s[0] - 'a'] = true;
    int tail = 1;    
    for (int i = 1; i < len; i++) {
        if (!hit[s[i] - 'a']) {
            hit[s[i] - 'a'] = true;
            s[tail] = s[i];
            tail++;
        }
    }
    s[tail] = '\0';
}
int getLen(char* s) {
    int idx = 0;
    while (s[idx] != '\0')
        idx++;
    return idx;
}
int main(int argc, const char *argv[])
{
    char s[128];
    std::cin >> s;
    removeDup2(s, getLen(s));
    std::cout << s << std::endl;
    return 0;
}
