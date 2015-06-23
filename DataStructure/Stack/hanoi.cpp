#include "stackList.h"
#include <iostream>
#include <string>

class MyStack : public Stack {

    public:
        std::string name;
        MyStack(std::string newName) {
            name = newName;
        }
};
void moveTopTo(MyStack *src, MyStack *dst) {
    if ( src == nullptr || dst == nullptr )
        return;
    Node* p = src->pop();
    dst->push(p->val);
    std::cout << "move " << p->val << " from " << src->name << " to " << dst->name << std::endl;
    free(p);
};

void hanoi(int n, MyStack* src, MyStack* tmp, MyStack* dst) {

    if ( n > 0 ) {
        hanoi(n - 1, src, dst, tmp);
        moveTopTo(src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}



int main(int argc, const char *argv[])
{ 
    MyStack src("source");
    MyStack dst("destination");
    MyStack tmp("temp");
    int n = 10;
    for ( int i = n; i >= 1; i--) {
        src.push(i);
    }
    hanoi(n, &src, &tmp, &dst);
    std::cout << "printing src..." << std::endl;
    src.print();
    std::cout << "printing temp..." << std::endl;
    tmp.print();
    std::cout << "printing dest..." << std::endl;
    dst.print();
    
    return 0;
}
