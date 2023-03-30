#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Entry {
public:
    string key;
    string value;
    Entry* next;
    Entry(string k, string v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    vector<Entry*> table;
    int size;
public:
    int chain_collisions;
    int linear_collisions;
    HashTable(int s) : size(s), table(s), chain_collisions(0), linear_collisions(0) {}
    int hash_function(string key) {
        int sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum += key[i];
        }
        return sum % size;
    }
    void insert_with_chaining(string key, string value) {
        int index = hash_function(key);
        Entry* entry = table[index];
        if (entry == nullptr) {
            table[index] = new Entry(key, value);
        }
        else {
            chain_collisions++;
            while (entry->next != nullptr) {
                entry = entry->next;
            }
            entry->next = new Entry(key, value);
        }
    }
    void insert_with_linear_probing(string key, string value) {
        int index = hash_function(key);
        if (table[index] == nullptr) {
            table[index] = new Entry(key, value);
        }
        else {
            linear_collisions++;
            int i = 1;
            while (table[(index + i) % size] != nullptr) {
                i++;
            }
            table[(index + i) % size] = new Entry(key, value);
        }
    }
    void print_table() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Entry* entry = table[i];
            while (entry != nullptr) {
                cout << "(" << entry->key << ", " << entry->value << ")";
                entry = entry->next;
                if (entry != nullptr) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);

    ht.insert_with_chaining("apple", "a fruit");
    ht.insert_with_chaining("banana", "a fruit");
    ht.insert_with_chaining("carrot", "a vegetable");
    ht.insert_with_chaining("dog", "an animal");
    ht.insert_with_chaining("elephant", "an animal");
    ht.insert_with_chaining("fox", "an animal");

    cout << "Hash table with chaining:" << endl;
    ht.print_table();
    cout << "Total collisions with chaining: " << ht.chain_collisions << endl;

    ht.insert_with_linear_probing("apple", "a fruit");
    ht.insert_with_linear_probing("banana", "a fruit");
    ht.insert_with_linear_probing("carrot", "a vegetable");
    ht.insert_with_linear_probing("dog", "an animal");
    ht.insert_with_linear_probing("elephant", "an animal");
    ht.insert_with_linear_probing("fox", "an animal");

    cout << "Hash table with linear probing:" << endl;
    ht.print_table();
    cout << "Total collisions with linear probing: " << ht.linear_collisions << endl;

    return 0;
}
