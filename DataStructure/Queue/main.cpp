#include "Queue.h"
#include <iostream>

int main(int argc, const char *argv[])
{
    Queue queue;
    int n;
    std::cout << "Enter number of elements:" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
       queue.enqueue(i); 
    }
    Node* ret;
    while ((ret = queue.dequeue()) != nullptr) {
        std::cout << ret->value << std::endl;
    }
    return 0;
}
