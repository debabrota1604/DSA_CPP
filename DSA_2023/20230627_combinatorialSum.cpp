#include<bits/stdc++.h>
using namespace std;

//Given an input array and a target sum, determine in how many ways the target sum can be achieved.
// Once element can be selected multiple times.

class CombinatorialSum{
    vector<int> array;
    unordered_map<int,int> memo;

    public:
    CombinatorialSum(vector<int> inp){
        this->array = inp;
    }
    int countCombinatorialSum(int remainingSum){
        if(memo.find(remainingSum) != memo.end()) return memo[remainingSum];
        int counter=0;
        for(int iter=0; iter<array.size(); iter++){
            if(remainingSum -array[iter] ==0) counter++;
            else if(remainingSum - array[iter] > 0) counter += countCombinatorialSum(remainingSum - array[iter]);
        }
        return (memo[remainingSum] = counter);
    }
};

class CombinatorialSumIterative{
    vector<int> array;

    public:
    CombinatorialSumIterative(vector<int> inp){ this->array = inp; }
    int coutIterative(){
        
    }
}


int main(){
    CombinatorialSum cs({1,2,5});
    cout << "Total ways to get the target: " << cs.countCombinatorialSum(5) << endl;

    return 0;

}