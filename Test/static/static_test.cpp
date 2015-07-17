#include <iostream>

static int g = 3;

class StaticTest
{
public:
    static int test;
    static const int foo = 2;
    static void setG(int _g) {
        g = _g;
    }
private:
};

int StaticTest::test = 1;

int main(int argc, const char *argv[])
{
    //std::cout << StaticTest::foo << std::endl;
    //std::cout << StaticTest::test << std::endl;
    std::cout << g << std::endl;
    StaticTest::setG(100);
    std::cout << g << std::endl;
    return 0;
}
