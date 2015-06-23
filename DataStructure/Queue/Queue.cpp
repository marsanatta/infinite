#include "Queue.h"
#include <iostream>
Queue::Queue() :
    front(nullptr), back(nullptr)
{

}

void Queue::enqueue(int value)
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;

    if (front == nullptr)
    {
        front = newNode;
        back = front;
    }
    else 
    {
        back->next = newNode;
        back = newNode;
    }
}

Node* Queue::dequeue()
{
    if (front == nullptr)
        return nullptr;
    Node* ret = front;
    front = front->next;
    return ret;
}
