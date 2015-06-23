#include <iostream>
class StackArray
{
public:
    StackArray(int size);
    void push(int value);
    int* pop(); 
private:
    int *buf;
    int maxSize;
    int top;
};
