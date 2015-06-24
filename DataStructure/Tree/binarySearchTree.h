#include <climits>
#include <iostream>
#include <queue>

class Node {
public:
    Node* left;
    Node* right;
    int val;
    Node(int newVal) : val(newVal), left(nullptr), right(nullptr) {
    }
};

class BinarySearchTree {
private:
    void delete_dfs(Node* cur) {
        if ( cur->left != nullptr ) {
            delete_dfs(cur->left);
        }
        if ( cur->right != nullptr ) {
            delete_dfs(cur->right);
        }
        delete(cur);
    }

    void balanced_dfs(Node* cur, int unsigned level, unsigned int &max, unsigned int &min) {
        if ( cur->left == nullptr && cur->right == nullptr ) {
            if ( level < min )
                min = level;
            if ( level > max )
                max = level;
        }
        if ( cur->left != nullptr )
            balanced_dfs(cur->left, level + 1, max, min);
        if ( cur->right != nullptr )
            balanced_dfs(cur->right, level + 1, max, min);
    }
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {
    }

    ~BinarySearchTree() {
        delete_dfs(root);
    }

    bool isBalanced() {
        unsigned int min = UINT_MAX;
        unsigned int max = 0;
        balanced_dfs(root, 0, max, min);
        std::cout << "max:" << max << std::endl;
        std::cout << "min:" << min << std::endl;
        if ( max - min > 1 )
            return false;
        else 
            return true;
    }

    void dfs_root() {
        std::cout << "dfs from root:" << std::endl;
        dfs(root);
    }

    void dfs(Node* cur) {
        std::cout << cur->val << std::endl;
        if ( cur->left != nullptr ) {
            dfs(cur->left);
        }
        if ( cur->right != nullptr ) {
            dfs(cur->right);
        }
    }

    void bfs() {
        std::cout << "bfs from root:" << std::endl;
        if (root == nullptr)
            return;
        std::queue<Node*> q;
        q.push(root); 
        while( !q.empty() ) {
            Node* p = q.front();
            q.pop();
            std::cout << p->val << std::endl;
            if ( p->left != nullptr ) {
                q.push(p->left); 
            }
            if ( p->right != nullptr ) {
                q.push(p->right);
            }
        }
    }

    void insert(int val) {
        if ( root == nullptr ) {
            root = new Node(val);
            return;
        }
        Node* cur = root;
        while ( true ) {
            if (cur->val > val) {
                if ( cur->left == nullptr ) {
                    cur->left = new Node(val);
                    return;
                }
                else 
                    cur = cur->left;

            }
            else {
                if ( cur->right == nullptr ) {
                    cur->right = new Node(val);
                    return;
                }
                else 
                    cur = cur->right;
            }
        }
    }
    
};
