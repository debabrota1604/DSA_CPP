#include<bits/stdc++.h>
using namespace std;

/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
*/

class LFUCache {
private:
    int capacity;
    unordered_map<int, pair<int, int>> cache; // key -> (value, frequency)
    unordered_map<int, list<int>> freqMap;   // frequency -> list of keys with that frequency
    unordered_map<int, list<int>::iterator> iterMap; // key -> iterator to the corresponding key in freqMap

    int minFrequency;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFrequency = 0;
    }
    
    int get(int key) {
        //Step1: search the key in O(1) time
        if(iterMap.find(key) == iterMap.end()) return -1;

        // Step2: Element exists, increase freq then return.
        int freq = ++cache[key].second; // increment freq and get it stored
        freqMap[freq].push_back(key); // add new freq to the freq list
        iterMap[key] = --freqMap[freq].end(); // Not understood!!!

        // Step3: Remove from old frequency list
        freqMap[freq-1].erase(iterMap[key]);

        //Update minFrequency if necessary
        if(minFrequency == freq-1 && freqMap[minFrequency].empty()) minFrequency++;

        return cache[key].first; // return the value
    }
    
    void put(int key, int value) {
        // Step 1: If key exists, update value and freq
        if(cache.find(key) != cache.end()){
            cache[key].first = value;
            get(key); // increases the freq
            return;
        }

        // Step2: If cache is full, evict the least freq used key
        if(cache.size() == capacity){
            // Get the least recently used element with min freq
            auto evictList = freqMap[minFrequency]; 
            int evictKey = evictList.front();

            // Delete the key from all three data structures
            cache.erase(evictKey);
            iterMap.erase(evictKey);
            evictList.pop_front(); // Throwing SIGABRT
        }

        // Step3: add the new key_value pair
        cache[key] = {value,1};
        freqMap[1].push_back(key);
        iterMap[key] = --freqMap[1].end(); // Get iterator to the last valid item
        minFrequency = 1; // reset freq as it is a new key
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(){
    LFUCache lfu(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lfu.get(1) << endl;      // return 1
                    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                    // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lfu.get(2) << endl;      // return -1 (not found)
    cout << lfu.get(3) << endl;      // return 3
                    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                    // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lfu.get(1) << endl;      // return -1 (not found)
    cout << lfu.get(3) << endl;      // return 3
                    // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lfu.get(4) << endl;      // return 4
                    // cache=[4,3], cnt(4)=2, cnt(3)=3
    return 0;
}