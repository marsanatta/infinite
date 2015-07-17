#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, const char *argv[])
{
    std::string s("ABCD");
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::cout << s << std::endl;
    return 0;
}
