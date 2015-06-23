#include <iostream>
#include <vector>

int main(int argc, const char *argv[])
{
    std::vector<int> v{1, 2};
    std::cout << *(v.begin()) << std::endl;
    std::cout << *(v.end()) << std::endl;
    return 0;
}
