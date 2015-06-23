typedef struct Node
{
    int value;
    Node* next;
}Node;

class Queue
{
public:
    Queue();
    void enqueue(int value);
    Node* dequeue();

private:
    Node* front;
    Node* back;
};
