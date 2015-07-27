#include <iostream>
using namespace std;
class Parent {
public:
    virtual void A() {
        std::cout << "Parent's A" << std::endl;
    }
};

class Child : public Parent {
public:
    void B() {
        std::cout << "B" << std::endl;
    }
    virtual void A() {
        std::cout << "Child's A" << std::endl;
    }
};

int main(int argc, const char *argv[])
{
    Parent *p = new Child();
    p->A();
    return 0;
}


