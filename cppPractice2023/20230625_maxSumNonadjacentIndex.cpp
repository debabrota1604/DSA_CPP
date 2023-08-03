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
        else if(index==0 || index==1) return elements[index]; //Base Case
        else if(memo.find(index) != memo.end()) return memo[index];
        else{
            auto res = max(findMaxSum(index-1),findMaxSum(index-2) + elements[index]);
            cout << index << ":" << res << endl;
            memo[index] = res;
            return res;
        } 
    }
    int findMaxSum(){
        return findMaxSum(elements.size()-1);
    }
};


class ElementSumIterative{
    vector<int> elem;
    public:
    ElementSumIterative(vector<int> inp){
        this->elem = inp;
    }
    int findMaxSum(){
        int memo[2] = {elem[0],elem[1]};

        for(int iter=2;iter<elem.size();iter++){
            memo[iter&1] = max(memo[(iter-1)&1], memo[(iter-2)&1]+elem[iter]);
            cout << iter << ":" << memo[iter&1] << endl;
        }
        return memo[(elem.size()-1)&1];
    }
};



int main(){
    ElementSum es({5, 5, 10, 100, 10, 105});
    ElementSumIterative esi({5, 5, 10, 100, 10, 105});

    cout << "Solution: " << es.findMaxSum() << endl;
    cout << "Iterative Solution: " << esi.findMaxSum() << endl;
}