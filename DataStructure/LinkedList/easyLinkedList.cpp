#include "easyLinkedList.h"
#include <iostream>
Node::Node(int v):
    value(v),
    next(nullptr)
{
}
Node::~Node()
{
}
int Node::getValue() const
{
    return value;
}
Node* Node::getNext() const
{
    return next;
}
void Node::setValue(int newValue)
{
    value = newValue;
}
void Node::setNext(Node* newNext)
{
    next = newNext;
}

LinkedList::LinkedList():
    head(nullptr)
{
}
LinkedList::~LinkedList()
{
    Node *cur = head;
    while (cur != nullptr)
    {
        Node* next = cur->getNext();
        delete cur;
        cur = next;
    }
}
void LinkedList::print() const
{
    std::cout << "printing linked list:" << std::endl;
    Node *cur = head;
    while (cur != nullptr)
    {
        std::cout << cur << ":";
        std::cout << cur->getValue() << " ";
        cur = cur->getNext();
    }
    std::cout << std::endl;
}
Node* LinkedList::find(int value)
{
    Node *cur = head;
    while (cur != nullptr) {
        if (cur->getValue() == value) {
           return cur; 
        }
        cur = cur->getNext();
    }
    return nullptr;
}
void LinkedList::insert(int value)
{
    std::cout << "inserting " << value << std::endl;
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *cur = head;
    while(cur->getNext() != nullptr)
        cur = cur->getNext();
    cur->setNext(newNode);
}
void LinkedList::del(int value)
{
    std::cout << "deleting " << value << std::endl;
    if (head->getValue() == value)
    {
        Node* del = head;
        head = head->getNext();
        delete del;
        return; 
    }
    Node *cur = head;
    while(cur->getNext() != nullptr && cur->getNext()->getValue() != value)
        cur = cur->getNext();
    if (cur->getNext() == nullptr)
    {
        std::cout << "cannot find " << value << std::endl;
        return;
    }
    Node* del = cur->getNext();
    cur->setNext(del->getNext());
    delete del;
}

Node* LinkedList::getHead() const
{
    return head;
}

void LinkedList::setHead(Node* newHead)
{
    head = newHead;
}
