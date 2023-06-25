#include<bits/stdc++.h>
using namespace std;

// Determine maximum sum of an array while selecting no adjacent elements

class ElementSum{
    vector<int> elements;
    unordered_map<int,int> memo;
    public:
    ElementSum(vector<int> inp){
        this->elements = inp;
    }
    int findMaxSum(int index){
        if(index<0) return 0;
        else if(index==0) return elements[index];
        else if(index>elements.size()) return findMaxSum(elements.size()-1);
        else if(memo.find(index) != memo.end()) return memo[index];
        else{
            auto res = max(findMaxSum(index-1),findMaxSum(index-2) + elements[index]);
            cout << index << ":" << res << endl;
            memo[index] = res;
            return res;
        } 
    }
};


class ElementSumIterative{
    vector<int> elem;
    public:
    ElementSumIterative(vector<int> inp){
        this->elem = inp;
    }
    int findMaxSum(int index){
        int memo[2];

        //Not able to think the base case for 0 & 1.
        // Because the recursion for n-1 & n-2.
        // The space can be optimized to 2 integers.

        return 0;
    }
}



int main(){
    ElementSum es({5, 5, 10, 100, 10, 105});

    cout << "Solution: " << es.findMaxSum(600) << endl;
}