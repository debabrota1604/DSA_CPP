#include<bits/stdc++.h>
using namespace std;

template<typename T>
class maxHeap{
    vector<T> memory;
    int heapSize;
    public:

    void updateSize(){ heapSize = memory.size(); }

    void dispArr(){
        for(auto i: memory) cout << i << " ";
        cout << endl;
    }

    void swap(T& val1, T&val2){
        T& temp = val1;
        val1 = val2;
        val2 = temp;
    }

    //Constructor to convert array into a heap
    maxHeap(vector<T> inp){
        heapSize = inp.size();

        // Heapify starts from last internal node, which is at floor(sz/2) index
        memory = inp;
        int index = (heapSize-1)/2;
        while(index >=0){
            heapify(index);
            index--;
        }
    }

    // This function makes the current node and all it's child's a valid heap
    void heapify(int root){

        int largest = root;
        int lft = 2*root +1;
        int rgt = 2*root +2;

        if(lft < heapSize && memory[lft] < memory[largest]) largest = lft;
        if(rgt < heapSize && memory[rgt] < memory[largest]) largest = rgt;

        if(largest != root){
            swap(memory[root], memory[largest]);
            largest < (heapSize-1)/2 ? heapify(largest) :1;
        }        
    }

    // void insert(T data){
    //     memory.emplace_back(data);
    //     updateSize();

    //     int parent = (heapSize -1)/2;
    //     while(1){
    //         if(memory[parent])
    //     }
    // }



};

template<typename T>
class MinHeap{
    /*
    getMin(): It returns the root element of Min Heap. 
        The time Complexity of this operation is O(1). 
        In case of a maxheap it would be getMax().

    extractMin(): Removes the minimum element from MinHeap. 
        The time Complexity of this Operation is O(log N) 
        as this operation needs to maintain the heap property 
        (by calling heapify()) after removing the root.
        
    decreaseKey(): Decreases the value of the key. 
        The time complexity of this operation is O(log N). 
        If the decreased key value of a node is greater than 
        the parent of the node, then we don’t need to do anything. 
        Otherwise, we need to traverse up to fix the violated heap property.

    insert(): Inserting a new key takes O(log N) time. 
        We add a new key at the end of the tree. If the new key 
        is greater than its parent, then we don’t need to do anything. 
        Otherwise, we need to traverse up to fix the violated heap property.
    delete(): Deleting a key also takes O(log N) time. We replace 
        the key to be deleted with the minimum infinite by 
        calling decreaseKey(). After decreaseKey(), the minus 
        infinite value must reach root, so we call extractMin() to remove the key.
    */

    vector<T> memory;
    int heapSize;
    public:

    void updateSize(){
        heapSize = memory.size();
    }
    void dispArr(){
        for(auto i: memory) cout << i << " ";
        cout << endl;
    }
    void swap(T& val1, T&val2){
        T temp = val1;
        val1 = val2;
        val2 = temp;
    }

    //Constructor to convert array into a heap
    MinHeap(vector<T> inp){
        heapSize = inp.size();

        // Heapify starts from last internal node, which is at floor(sz/2) index
        memory = inp;
        int index = (heapSize-1)/2;
        while(index >=0){
            heapify(index);
            cout << index << ": ";
            dispArr();
            index--;
        }
    }

    // This function makes the current node and all it's child's a valid heap
    void heapify(int root){
        // Step1: initialize all valid indices to be compared.
        int smallest = root;
        int lft = 2*root +1;
        int rgt = 2*root +2;

        // Step2: Compare and compute the index containing the smallest element
        if(lft < heapSize && memory[lft] < memory[smallest]) smallest = lft;
        if(rgt < heapSize && memory[rgt] < memory[smallest]) smallest = rgt;

        // If the smallest is not the root index, value swapping must be performed to make heap
        if(smallest != root){
            swap(memory[root], memory[smallest]);

            // If swap is performed, recursively heapify the subtree.
            if(smallest < (heapSize-1)/2) heapify(smallest);
        }
    }

    void insertElement(T data){
        memory.emplace_back(data);
        updateSize();

        int current = heapSize-1;
        int parent = (current -1)/2;
        while(1){
            if(memory[parent] > memory[current]){
                swap(memory[parent], memory[current]);

                if(parent ==0) break;

                current = parent;
                parent =  (current -1)/2;
            }
            else{
                break;
            }
        }
    }
};

int main(){
    vector<int> v {10, 13, 11, 5, 9, 16, 20, 1, 3, 4};

    MinHeap<int> heap(v);
    heap.dispArr();
}