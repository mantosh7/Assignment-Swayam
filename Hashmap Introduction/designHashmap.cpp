/*
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

Example:
Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]
*/

#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
    static const int SIZE = 1000; 
    vector<list<pair<int,int>>> mp;

    MyHashMap() {
        mp.resize(SIZE);
    }

    void put(int key, int value) {
        int h = key % SIZE;

        for (auto it = mp[h].begin(); it != mp[h].end(); it++) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }

        mp[h].push_back({key, value});
    }

    int get(int key) {
        int h = key % SIZE;

        for (auto it = mp[h].begin(); it != mp[h].end(); it++) {
            if (it->first == key)
                return it->second;
        }
        return -1;
    }

    void remove(int key) {
        int h = key % SIZE;

        for (auto it = mp[h].begin(); it != mp[h].end(); it++) {
            if (it->first == key) {
                mp[h].erase(it);
                return;
            }
        }
    }
};

int main() {
    MyHashMap hm;

    hm.put(1, 10);
    hm.put(2, 20);
    hm.put(1001, 30);   
    cout << hm.get(1) << endl;     
    cout << hm.get(2) << endl;     
    cout << hm.get(1001) << endl;  

    hm.remove(2);
    cout << hm.get(2) << endl;   

    return 0;
}
