#include <cstddef>

template<typename K, typename V>
class Node {

private:
  K key;
  V value;
  Node *next;
public:
  Node(K key, V value) :
  key(key), value(value), next(NULL){
  }

  void setValue(V value) {
    this->value = value;
  }
  void setKey(K key) {
    this->key = key;
  }
  void setNext(Node *next) {
    this->next = next;
  }
  V getValue() const {
    return value;
  }
  K getKey() const {
    return key;
  }
  Node* getNext() const {
    return next;
  }
};

const unsigned long TABLE_SIZE = 10;

template <typename K>
struct KeyHash {
  unsigned long operator() (K const &key) const {
    return reinterpret_cast<unsigned long>(key % TABLE_SIZE);
  }
};

template<typename K, typename V, typename F = KeyHash<K> >
class Hash {
private:
  Node<K, V>** table;
  F hashFunc;
public:
  Hash() {
    table = new Node<K, V>*[TABLE_SIZE];
  }
  ~Hash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
      if (table[i] != NULL) {
        Node<K, V>* cur = table[i];
        while(cur != NULL) {
          Node<K, V>* temp = cur;
          cur = cur->getNext();
          delete temp;
        }
      }
    }
    delete []table;
  }

  void put(const K &key, const V &value) {
    unsigned long hashValue = hashFunc(key);
    if(table[hashValue] == NULL) {
      table[hashValue] = new Node<K, V>(key, value);
      return;
    } 
    else {
      Node<K, V> *cur;
      while(cur->getNext() != NULL) {
        cur = cur->getNext();
      }
      cur->setNext(new Node<K, V>(key, value));
    }
  }

  bool get(const K &key, const V &value) {
    unsigned long hashValue = hashFunc(key);
    if(table[hashValue] == NULL)
      return false;
    else {
      Node<K, V> *cur = table[hashValue];
      while(cur != NULL) {
        if (cur->getKey() == key && cur->getValue() == value)
          return true;
        cur = cur->getNext();
      }
    }
  }
};

