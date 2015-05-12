#include "easyLinkedList.h"
#include <iostream>
void removeDup(LinkedList *list)
{
    std::cout << "removing duplicate" << std::endl;
    if (list->getHead() == nullptr) {
       return; 
    }
    Node *cur = list->getHead()->getNext();
    while (cur != nullptr) {
        Node *run = list->getHead();
        Node *prev = nullptr;
        while (run != cur) {
            if (run->getValue() == cur->getValue()) {
                Node* del = run;
                if (prev == nullptr) {
                    list->setHead(del->getNext());
                }
                else {
                    prev->setNext(del->getNext());
                }
                delete del;
                break;
            }
            prev = run;
            run = run->getNext();
        }
        cur = cur->getNext();
    }
}

LinkedList* add(const LinkedList *la, const LinkedList *lb)
{
    bool carry = false;
    Node* cura = nullptr;
    Node* curb = nullptr;
    LinkedList *out = new LinkedList();
    if (la != nullptr)
        cura = la->getHead();
    if (lb != nullptr)
        curb = lb->getHead();
    while (cura != nullptr || curb != nullptr || carry) {
        int sum = 0;
        if (cura != nullptr)
            sum += cura->getValue();
        if (curb != nullptr)
            sum += curb->getValue();
        if (carry)
            sum++;
        if (sum >= 10)
        {
            sum -= 10;
            carry = true;
        }
        else 
            carry = false;
        out->insert(sum);
        if (cura != nullptr)
            cura = cura->getNext();
        if (curb != nullptr)
            curb = curb->getNext();
    }    
    return out;
}

Node* findNLast(Node* head, unsigned int n)
{
    Node* cur = head;
    int step = 0;
    while (step != n && cur != nullptr) {
       step++;
       cur = cur->getNext();
    }
    if (cur == nullptr) {
        std::cout << "out of range" << std::endl;
        return nullptr;
    }
    Node *ans = head;
    while (cur->getNext() != nullptr) {
       cur = cur->getNext();
       ans = ans->getNext();
    }
    return ans;
}
int main(int argc, const char *argv[])
{
    LinkedList l1, l2;
    int n;
    std::cout << "Enter #digits of first number:" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        std::cin >> v;
        l1.insert(v); 
    }
    l1.print();
    std::cout << "Enter #digits of second number:" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        std::cin >> v;
        l2.insert(v); 
    }
    l2.print();
    LinkedList *out = add(&l1, &l2);
    out->print();
    //removeDup(&list);
    //list.print();
    //for (int i = 0; i < n + 1; i++) {
        //std::cout << "find " << i << " last:";
        //Node* find = findNLast(list.getHead(), i);
        //if (find)
            //std::cout << find->getValue() << std::endl;
    //}

    return 0;
}

