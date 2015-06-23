#include "stackArray.h"
#include <iostream>
int main(int argc, const char *argv[])
{
    int n;
    std::cout << "Size of Stack:" << std::endl;
    std::cin >> n;
    StackArray stack(n);
    std::cout << "Number of Elements to Push:" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
       stack.push(i); 
    }
    stack.push(11);
    std::cout << "Pop all of the elements" << std::endl;
    int *pValue;
    while ((pValue = stack.pop()) != nullptr) {
        std::cout << *pValue << std::endl;
    }
    return 0;
}
