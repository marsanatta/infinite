#include <vector>
class Node {
public:
    std::vector<Node*> neighbors;
    int val;
    Node(int newVal) {
        val = newVal;
    }
};


