#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode* right;
    TreeNode ( int newVal) : val(newVal), left(nullptr), right(nullptr) {
    }
    void insert(int newVal) {
        if ( newVal > val ) {
            if ( right != nullptr )
                right->insert(newVal);
            else
                right = new TreeNode(newVal);
        }
        else {
            if ( left != nullptr )
                left->insert(newVal);
            else
                left = new TreeNode(newVal);
        }
    }
};
class Node {
public:
    int val;
    Node* next;
    Node (int newVal) : val(newVal), next(nullptr) {
        val = newVal;
    }
    void insert(int val) {
        Node* cur = this;
        while ( cur->next != nullptr ) cur = cur->next;
        cur->next = new Node(val);
    }
    void print() {
        Node* cur = this;
        while ( cur != nullptr ) {
            std::cout << cur->val;
            cur = cur->next;
            if ( cur != nullptr )
                std::cout << "=>";
        }
        std::cout << std::endl;
    }
};

void create_list_dfs( TreeNode* cur, std::unordered_map<unsigned int, Node*> &level_lists, unsigned int level ) {
    if ( cur == nullptr )
        return;
    auto it = level_lists.find(level);
    if ( it == level_lists.end() ) {
        std::pair<unsigned int, Node*> p (level, new Node(cur->val));
        level_lists.insert(p);
    }
    else {
        (*it).second->insert(cur->val);
    }
    create_list_dfs(cur->left, level_lists, level + 1);
    create_list_dfs(cur->right, level_lists, level + 1);
}
void print_dfs(TreeNode *cur) {
    std::cout << cur->val << std::endl;
    if ( cur->left != nullptr )
        print_dfs(cur->left);
    if ( cur->right != nullptr )
        print_dfs(cur->right);
}

int main(int argc, const char *argv[])
{

    TreeNode root(4);
    std::unordered_map<unsigned int, Node*> level_lists;
    const int arr[] = {2, 1, 3, 6, 5, 7};
    std::vector<int> v (arr, arr + sizeof(arr)/sizeof(arr[0]));
    for (auto &i : v ) {
        root.insert(i);
    }
    print_dfs(&root);
    create_list_dfs(&root, level_lists, 0);
    
    for ( auto &i : level_lists ) {
        std::cout << "level " << i.first << " :";
        i.second->print();
    }

    return 0;
}
