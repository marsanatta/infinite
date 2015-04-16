#include <iostream>
#include <new>
#define TABLE_SIZE 8

using std::cout;
using std::cin;
using std::endl;

class HashEntry {
private:
  int key;
  int value;
public:
  HashEntry(int _key, int _value) {
    key = _key;
    value = _value;
  }
  int getKey() {return key;}
  int getValue() {return value;}
};

class HashTable {
private:
  HashEntry **table;
public:
  HashTable() {
    table = new HashEntry*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
      table[i] = NULL;
    }
  }
  void put(int key, int value) {
    int hash = key % TABLE_SIZE;
    while (table[hash] != NULL && table[hash]->getKey() != key)
      hash = (hash + 1) % TABLE_SIZE;
    if (table != NULL)
      delete table[hash];
    table[hash] = new HashEntry(key, value);
  }
  int get(int key) {
    int hash = key % TABLE_SIZE;
    while (table[hash] != NULL && table[hash]->getKey() != key)
      hash = (hash + 1) % TABLE_SIZE;
    if (table[hash] == NULL)
      return -1;
    return table[hash]->getValue();
  }
  ~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
      if (table[i] != NULL)
        delete table[i];
    }
    delete[] table;
  }
};

int main() {

  HashTable hashTable;
  for (int i = 0; i < TABLE_SIZE; i++) {
    hashTable.put(i, i*10);
  }
  while (true) {
    int key;
    cin >> key;
    cout << hashTable.get(key) << endl;
  }
  return 0;
}
