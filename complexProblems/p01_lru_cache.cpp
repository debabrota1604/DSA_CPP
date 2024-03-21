#include<bits/stdc++.h>
using namespace std;

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. 
        Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

*/

class LRUCache {
    list<pair<int,int>> val;
    int cap;
    unordered_map<int, list<pair<int,int>>::iterator> valMap;

    void push_to_front(list<int> node){

    }
public:
    LRUCache(int capacity):cap(capacity){}
    
    int get(int key) {
        // Step1: Search in map in O(1) time. If key not present, return.
        if(valMap.find(key) == valMap.end()) return -1;

        // Step2: If key is present, make the key most recently used
        auto searchRes = *valMap[key];

        // Erase and insert the same node in the beginning
        val.erase(valMap[key]);
        val.push_front(searchRes);

        // Update the iterator in the map
        valMap[key] = val.begin();

        // Step3: return the key
        return searchRes.second;
    }
    
    void put(int key, int value) {
        // Step1: If key exists, erase the value to add it to front later
        if(valMap.find(key) != valMap.end()){
            val.erase(valMap[key]);
        }
        // Step2: If cache is full, remove the least recently used item
        else if(val.size() == cap){
            valMap.erase(val.back().first);
            val.pop_back();
        }
        // Step3: Add/Update the key to the front
        val.push_front({key, value});
        valMap[key] = val.begin();

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(){
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache.get(2) << endl;     // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache.get(1) << endl;     // return -1 (not found)
    cout << lRUCache.get(3) << endl;    // return 3
    cout << lRUCache.get(4) << endl;     // return 4
    return 0;
}