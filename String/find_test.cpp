#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    string s("/home/"); 
    int i = 0;
    size_t begin = s.find_first_not_of('/', i);
    size_t end = s.find_first_of('/', begin);
    std::cout << begin << std::endl;
    std::cout << end << std::endl;
    std::cout << s.substr(begin, end - 1) << std::endl;
    return 0;
}
