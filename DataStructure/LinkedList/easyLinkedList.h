#ifndef EASY_LINKED_LIST_H
#define EASY_LINKED_LIST_H
class Node
{
    public:
        Node(int v);
        ~Node();
        int getValue() const;
        Node* getNext() const;
        void setValue(int newValue);
        void setNext(Node* newNext);
    private:
        /* data */
        int value;
        Node* next;
};

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void print() const;
        void insert(int value);
        void del(int value);
        Node* find(int value);
        Node* getHead() const;
        void setHead(Node *newHead);
    private:
        Node *head;
};
#endif

