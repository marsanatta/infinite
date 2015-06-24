#include <iostream>
#include "BinarySearchTree.h"

int main(int argc, const char *argv[])
{
    int n;
    std::cin >> n;
    BinarySearchTree t;
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        t.insert(val);
    }
    t.dfs_root();

    t.bfs();
    
    std::cout.setf(std::ios::boolalpha);    
    std::cout << t.isBalanced() << std::endl;

    return 0;
}
