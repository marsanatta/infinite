#include <cstddef>
#include <iostream>

int const TABLE_SIZE = 100;

class Node {
public:
    Node (int _key, int _value) :
    key(_key), value(_value), next(NULL)
    {

    }
    void setKey(int _key) {
        key = _key;
    }
    void setValue(int _value) {
        value = _value;
    }
    void setNext(Node* _next) {
        next = _next;
    }
    int getKey() {
        return key;
    }
    int getValue() {
        return value;
    }
    Node* getNext() {
        return next;
    }
    Node* getTail() {
        if (this->getNext() == NULL)
            return this;
        else
            return this->getNext()->getTail();
    }
private:
    int key;
    int value;
    Node* next;
};

class Hash
{
public:
    Hash() {
        table = new Node*[TABLE_SIZE];
    }
    void put(int const &key, int const &value) {
        int hashValue = key % TABLE_SIZE; 
        if (table[hashValue] == NULL) {
            table[hashValue] = new Node(key, value);
        }
        else {
            std::cout << "collision at " << key <<  std::endl;
            table[hashValue]->getTail()->setNext(new Node(key, value));
        }
    }
    Node* get(int const &key, int const &value) {
        int hashValue = key % TABLE_SIZE;
        if (table[hashValue] == NULL)
            return NULL;
        else {
           Node* cur = table[hashValue];
           while(cur != NULL) {
               if (cur->getKey() == key && cur->getValue() == value) {
                   return cur;
               }
               cur = cur->getNext();
           }
           return NULL;
        }
    }
    int countNULL() {
        int cnt = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if(table[i] == NULL)
                cnt++;
        }
        return cnt;
    }

private:
    /* data */
    Node** table;
};

int main(int argc, const char *argv[])
{
    Node first(10, 20);
    Node second(30, 40);
    Node third(100, 50);
    Node forth(100, 33);
    first.setNext(&second);
    second.setNext(&third);
    std::cout << first.getTail()->getValue() << std::endl;
    std::cout << second.getTail()->getValue() << std::endl;
    std::cout << third.getTail()->getValue() << std::endl;

    Hash h;
    h.put(10,20);
    h.put(30,40);
    h.put(10,30);
    h.put(30,50);
    std::cout << h.get(10,20) << std::endl;
    std::cout << h.get(11,20) << std::endl;
    std::cout << h.get(10,30) << std::endl;
    std::cout << h.get(31,100) << std::endl;
    std::cout << h.get(30,40) << std::endl;
    std::cout << h.get(30,50) << std::endl;

    return 0;
}
