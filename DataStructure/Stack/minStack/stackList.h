#include <climits>
#include <iostream>

class Node {
    public:
        int val;
        Node* next;
        Node(int newVal) : val(newVal), next(nullptr){
        }
};
class Stack {
    private:

        Node* top; 

    public:

        Stack() : top(nullptr) {
        }

        void push(int newVal) {
            Node* newNode = new Node(newVal);
            newNode->next = top;
            top = newNode;
        }

        Node* pop() {
            if (top == nullptr) {
                return nullptr;
            }
            else {
                Node* ret = top;
                top = top->next;
                return ret;
            }
        }

        Node* peek() {
            return top;
        }

        void print() const {
            Node* cur = top;
            while ( cur != nullptr ) {
                std::cout << cur->val;
                std::cout << std::endl;
                cur = cur->next;
            }
        }
};

class MinStack : public Stack {

private:

    Stack min_stack;

public:
    
    int min() {
        if (min_stack.peek() == nullptr) {
            return INT_MAX;
        }
        return min_stack.peek()->val;
    }
    void push(int newVal) {

        if (newVal <= min()) {
            min_stack.push(newVal);
        }
        Stack::push(newVal);

    }

    Node* pop() {
        Node* p = Stack::pop();
        if (p != nullptr && p->val == min()) {
            min_stack.pop();
        }
        return p;
    }
};
