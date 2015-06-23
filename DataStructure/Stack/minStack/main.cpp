#include "stackList.h"
#include <iostream>

void printStack(const Stack &s) {
    std::cout << "printing stack:"  << std::endl;
    s.print();
}
int main(int argc, const char *argv[])
{

    MinStack s;
    for ( int i = 10; i >= 5; i-- ) {
        s.push(i);    
    }
    printStack(s);
    std::cout << "min is:" << s.min() << std::endl;
    s.push(3);
    std::cout << "min is:" << s.min() << std::endl;

    s.pop();
    std::cout << "min is:" << s.min() << std::endl;

    s.pop();
    std::cout << "min is:" << s.min() << std::endl;
    
    s.pop();
    std::cout << "min is:" << s.min() << std::endl;

    s.pop();
    std::cout << "min is:" << s.min() << std::endl;

    s.push(1);
    std::cout << "min is:" << s.min() << std::endl;
    printStack(s);


    //s.pop();
    //for ( int i = 5; i < 10; i++ ) {
        //Node* p = s.pop();
        //if (p != nullptr) 
            //std::cout << p->val << std::endl;
    //}
    return 0;
}
