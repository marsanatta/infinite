#include "easyLinkedList.h"
#include <iostream>
Node* findBegin(Node* head)
{
    if (head == nullptr)
        return nullptr;

    Node* fast = head;
    Node* slow = head;
    do {
       fast = fast->getNext()->getNext();
       slow = slow->getNext();
    } while (fast != slow);

    slow = head;
    while (fast != slow) {
        fast = fast->getNext();
        slow = slow->getNext();
    }
    return fast;
}
int main(int argc, const char *argv[])
{
    LinkedList list;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        list.insert(i);
    }
    list.print();
    Node* tail = list.find(n-1);
    std::cin >> n;
    Node* begin = list.find(n);
    tail->setNext(begin);
    begin = findBegin(list.getHead());
    std::cout << "begin:" << begin->getValue() << std::endl;
}
