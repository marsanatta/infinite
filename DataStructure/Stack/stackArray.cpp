#include "stackArray.h"
StackArray::StackArray(int size):
    maxSize(size), top(-1)
{
    buf = new int[maxSize];
}

void StackArray::push(int value)
{
    if (top + 1 + 1 > maxSize) {
        std::cout << "stack overflow" << std::endl;
        return;
    }
    buf[++top] = value;
}

int* StackArray::pop()
{
    if (top == -1) {
        std::cout << "stack underflow" << std::endl;
        return nullptr;
    }
    int* ret = new int(buf[top--]);
    return ret;
}


