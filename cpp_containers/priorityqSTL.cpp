#include<iostream>
#include<queue>
using namespace std;

template<typename T>
void printQ(T q){while(!q.empty()){cout << q.top() <<" "; q.pop();} cout<<endl;}

template<typename T>
void printArr(T a){ for(auto i:a) cout << i << " "; cout << endl;}

int main(){
    /*
        Provides constant time lookup of the largest (by default) element, at the expense of logarithmic insertion and extraction.
        A user-provided Compare can be supplied to change the ordering, e.g. using std::greater<T> would cause the smallest element to appear as the top().
        Working with a priority_queue is similar to managing a heap in some random access container, with the benefit of not being able to accidentally invalidate the heap.
    */
    //insert ops: push()
    //delete: pop()
    //access: top()
    //modifiers: swap()
    //others: size(), empty()

    const auto data = {1,8,5,6,3,4,0,9,7,2};
    //Maintaining a max-heap
    priority_queue<int> maxh;
    cout << "Creating a max Heap from the array: "; printArr(data);
    for (auto i:data) maxh.push(i);
    cout << "The maxHeap looks like: "; printQ(maxh);

    //Maintaining a min-heap
    priority_queue<int,  vector<int>, greater<int>> minh(data.begin(), data.end());
    cout << "Creating a min Heap from the array: "; printArr(data);
    cout << "The minHeap looks like: "; printQ(minh);

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp); 
    cout << "Creating a custom priority Heap from the array: "; printArr(data);
    for(int n : data) q3.push(n);
    cout << "The custom priority heap with lambda function is: "; printQ(q3);


    return 0;
}