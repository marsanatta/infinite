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

int addup() {
    static int sum = 1;
    sum++;
    return sum;
}

int StaticTest::test = 1;

int a;

int main(int argc, const char *argv[])
{
    //std::cout << StaticTest::foo << std::endl;
    //std::cout << StaticTest::test << std::endl;
    //std::cout << g << std::endl;
    //StaticTest::setG(100);
    //std::cout << g << std::endl;
    //addup();
    //addup();
    //std::cout << addup() << std::endl;
    std::cout << a << std::endl;
    return 0;
}
