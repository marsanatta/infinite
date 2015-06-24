#include "graph.h"
#include <iostream>

bool find_dfs(const Node &cur, int key) {

    if (cur.val == key) 
        return true;
    for ( auto nptr : cur.neighbors ) {
        bool ret = find_dfs(*nptr, key);
        if (ret) 
            return true;
    }
    return false;
}

int main(int argc, const char *argv[])
{
    Node root(1);
    Node n1(2);
    Node n2(3);
    Node n3(4);
    Node n4(5);
    root.neighbors.push_back(&n1);
    root.neighbors.push_back(&n2);
    root.neighbors.push_back(&n3);
    n3.neighbors.push_back(&n4);
    for (int i = 0; i < 10; i++) {
        std::cout << "finding " << i << std::endl;
        std::cout << find_dfs(root, i)  << std::endl;
    }

    return 0;
}

