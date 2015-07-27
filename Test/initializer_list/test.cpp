#include <iostream>

using namespace std;

struct Car{
public:
    int speed;
    int size;
    void intro() {
        std::cout << "speed:" << speed << std::endl;
        std::cout << "size:" << size << std::endl;
    }
};

int main(int argc, const char *argv[])
{
    Car c1 = {10, 20};
    Car c2 = {100, 3000};
    c1.intro();
    c2.intro();

    return 0;
}
