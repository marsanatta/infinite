#include <iostream>

void changeValue(int &n) {
    n = 10
}

class Test {
public:
    const int a;
    Test() : a(10) {
    }

    int getA() const {
        return a;
    }
    void setA() const {
        changeValue(a);
    }
};
int main(int argc, const char *argv[])
{
    Test t;
    std::cout << t.a << std::endl;

    const Test ct;
    ct.setA();
    std::cout << ct.getA() << std::endl; 
    return 0;
}
