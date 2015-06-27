#include <iostream>
#include <queue>

class TwoQueueStack {
private:
    std::queue<int> *q1;
    std::queue<int> *q2;
public:
    TwoQueueStack() : q1(new std::queue<int>), q2(new std::queue<int>) {
    }

    void push(int val) {
        q1->push(val);
    }

    int pop() {
        if (q1->empty()) {
            std::cout << "underflow" << std::endl;
            return -1;
        }
        while (q1->size() != 1) {
            q2->push(q1->front());
            q1->pop();
        }
        int ret = q1->front(); 
        q1->pop();
        std::queue<int> *temp = q1;
        q1 = q2;
        q2 = temp;
        return ret;
    }
};

int main(int argc, const char *argv[])
{
    TwoQueueStack s;
    for (int i = 0; i < 10; i++) {
       s.push(i); 
    }    
    for (int i = 0; i < 10; i++) {
        std::cout << s.pop() << std::endl;
    }
    return 0;
}
