#include <iostream>
#include <list>
#include <string>
using namespace std;

class HashTable
{
    int capacity;
    list<int>* table;

public:
    HashTable(int V);
    void insertItem(int key, int data);

    int findElem(int key);
    int checkPrime(int n) {
        int i;
        if (n == 1 || n == 0) {
            return 0;
        }
        for (i = 2; i < n / 2; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    int getPrime(int n) {
        if (n % 2 == 0) {
            n++;
        }
        while (!checkPrime(n)) {
            n += 2;
        }
        return n;
    }
    int hashFunction(int key) {
        return (key % capacity);
    }
    void displayHash();
};

int HashTable::findElem(int key) {
    int index = hashFunction(key);

    list<int>::iterator i;
    for (i = table[index].begin();
        i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }
    for (auto x : table[index])
        return x;
}

HashTable::HashTable(int c) {
    int size = getPrime(c);
    this->capacity = size;
    table = new list<int>[capacity];
}

void HashTable::insertItem(int key, int data) {
    int index = hashFunction(key);
    table[index].push_back(data);
}

void HashTable::displayHash() {
    for (int i = 0; i < capacity; i++) {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main() {
    int key[] = { 231, 321, 212, 321, 433, 262, 32, 21, 34, 1254 };
    int data[] = { 123, 432, 523, 43, 423, 111 , 2, 23, 543, 2231 };
    int size = sizeof(key) / sizeof(key[0]);
    HashTable h(size);
    int n = size;
    for (int i = 0; i < n; i++)
        h.insertItem(key[i], data[i]);
    h.displayHash();
    cout << h.findElem(2);
    cout << h.findElem(2);
    return 0;
}