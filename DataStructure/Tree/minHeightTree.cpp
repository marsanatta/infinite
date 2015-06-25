#include "binarySearchTree.h"
#include <vector>

Node* addTree(std::vector<int> &v, int begin, int end) {
    if ( begin > end )
        return nullptr;
    int mid = begin + (end - begin) / 2;
    Node* n = new Node(v[mid]);
    n->left = addTree(v, begin, mid - 1);
    n->right = addTree(v, mid + 1, end);

    return n;
}

void print_dfs(Node* cur, unsigned int level) {
    std::cout << cur->val << " at level:" << level << std::endl;
    if ( cur->left != nullptr )
        print_dfs( cur->left, level + 1 );
    if ( cur->right != nullptr )
        print_dfs( cur->right, level + 1 );
}

int main(int argc, const char *argv[])
{
    std::vector<int> v;
    for (int i = 0; i < 16; i++) {
        v.push_back(i); 
    }
    Node* root = addTree(v, 0, 15); 
    print_dfs(root, 0);
    return 0;
}
