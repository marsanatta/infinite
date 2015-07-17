#include <iostream>

class Car {
private:
    int speed;
public:
    Car *chasing;
    Car() : chasing(nullptr) {
    }
    int getSpeed() {
        return speed;
    }
};

int main(int argc, const char *argv[])
{
    Car *c = new Car;
    Car *next = new Car;
    c->chasing = next;
    std::cout << c << std::endl;
    std::cout << c->chasing << std::endl;
    delete c;
    std::cout << c << std::endl;
    std::cout << c->chasing << std::endl;

    return 0;
}
