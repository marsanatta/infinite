#include "stackList.h"
#include <iostream>

Stack sort(Stack &s) {
    Stack out;
    while (!s.empty()) {
        Node* p = s.pop();
        while(!out.empty() && out.peek()->val > p->val) {
            Node* tmp = out.pop();
            s.push(tmp->val);
            delete(tmp);
        }
        out.push(p->val);
        delete(p);
    }
    return out;
}

int main(int argc, const char *argv[])
{
    Stack in, out;
    for (int i = 10; i >= 0; i--) {
        in.push(i);
    }
    std::cout << "in:" << std::endl;
    in.print();
    out = sort(in); 
    std::cout << "out:" << std::endl;
    out.print();
    return 0;
}
