#include "stackList.h"
#include <iostream>

class MyQueue {
private:
    Stack sin, sout;
public:
    void enqueue(int val) {
        sin.push(val);
    }
    Node* dequeue() {
        if (sout.empty() && sin.empty()) {
            std::cout << "underflow" << std::endl;
            return nullptr;
        }
        if (sout.empty()) {
            while (!sin.empty()) {
                Node* p = sin.pop();
                sout.push(p->val);
                delete(p);
            }
        }
        return sout.pop();
    }

};

int main(int argc, const char *argv[])
{
    MyQueue q;
    for (int i = 0; i < 10; i++) {
        q.enqueue(i); 
    }
    for (int i = 0; i < 11; i++) {
        Node* p = q.dequeue(); 
        if ( p != nullptr )
            std::cout << p->val << std::endl;
    }
    return 0;
}
