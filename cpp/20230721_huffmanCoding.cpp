#include<bits/stdc++.h>
using namespace std;

struct HeapNode{
    int data, freq;
    HeapNode *left, *right;

    HeapNode(char d1, int d2){
        data = d1;
        freq = d2;
        left = right = nullptr;
    }
};

void PrintHuffmanTree(HeapNode *root, string str){
    if(!root) return;

    //If its not a internal node, then it's a leaf node. Print the character with its encoding
    if(root->data != '$'){
        cout << (char) root->data << ": " << str << "\n";
        return;
    }

    // Recursively print left and right nodes
    PrintHuffmanTree(root->left, str + '0');
    PrintHuffmanTree(root->right, str + '1');
}

bool heapOrder(HeapNode *l, HeapNode *r){
    return l->data > r->data;
}

struct HeapOrderStruct{
        bool operator()(HeapNode *l, HeapNode *r){
        return l->freq > r->freq;
    }
};

void Encode(vector<char> inp, vector<int> frq){
    //first type of declaration: Not working maybe due to decltype
    //priority_queue<HeapNode*, vector<HeapNode*>, decltype(&heapOrder)> minHeap;

    //second type of declaration: Create a heap with increasig order of frequency
    priority_queue<HeapNode*, vector<HeapNode*>, HeapOrderStruct> minHeap;

    // For each character insert into the heap. It will get automatically sorted
    for(int iter=0; iter<inp.size(); iter++){
        HeapNode *t = new HeapNode(inp[iter], frq[iter]);
        minHeap.push(t);
    }

    // Until heap contains a single node, pop two min frequency nodes
    // And replace them with an internal node of $ symbol and frequency as sum of the earlier nodes
    while(minHeap.size() !=1){
        HeapNode *l, *r, *n;
        l = minHeap.top();
        minHeap.pop();

        r = minHeap.top();
        minHeap.pop();

        n = new HeapNode('$', l->freq +r->freq);
        n->left = l;
        n->right = r;
        
        minHeap.push(n);
    }

    // The min heap now have a single internal node with frequency 100. Lets print it cleverly.
    PrintHuffmanTree(minHeap.top(), "");
}



int main(){

    vector<char> arr {'a', 'b', 'c', 'd', 'e', 'f' };
    vector<int> freq { 5, 9, 12, 13, 16, 45 };
 
 
    Encode(arr, freq);
 
    return 0;

}