#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    //enum Fruit{
        //APPLE,
        //BANANA
    //};
    //enum Color {
        //RED,
        //BLUE
    //};
    //Fruit ftype = APPLE;
    //Color ctype = RED;
    //if (ftype == ctype) {
        //cout << "apple is the same with red" << endl;
    //}

    enum class Fruit {
        APPLE,
        BANANA
    };
    enum class Color {
        RED,
        Blue
    };
    Fruit ftype = Fruit::APPLE;
    Fruit fftype = Fruit::BANANA;
    Color ctype = Color::RED;

    if (ftype != fftype) 
        std::cout << "apple is not equal to banana" << std::endl;

    //if (ftype == ctype) {
        //std::cout << "apple is the same with red" << std::endl;
    //}

    return 0;
}
