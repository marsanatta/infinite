#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node(int newVal) : val(newVal), next(nullptr)  {
        }
};

class Stack {
    public:
        Stack() :head(nullptr) {
        }
        void push(int val) {
            if (!head) {
                head = new Node(val);
            }
            else {
                Node* temp = head;
                head = new Node(val);
                head->next = temp;
            }
        }
        Node* pop() {
            if (!head)
                return nullptr;
            else {
                Node* ret = head;
                head = head->next;
                return ret;
            }
        }
    private:
        Node* head;

};
int main(int argc, const char *argv[])
{
    vector<int> nums{1,3,4,6,7,2};
    Stack s;
    for( auto &n : nums ) {
        s.push(n);
    }
    while(1) {
        Node* p = s.pop();
        if (!p)
            return 0;
        std::cout << p->val  << std::endl;
    }



    return 0;
}
