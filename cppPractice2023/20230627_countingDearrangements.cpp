#include<bits/stdc++.h>
using namespace std;

// dearrangements is such permutations where none of the elements in its actual position

// recurrence relation: f(n) = (n-1) * (f(n-1) + f(n-2))

class countDerrangements{
    vector<int> array;
    unordered_map<int,int> memo;
    public:
    countDerrangements(vector<int> input){
        this->array = input;
    }
    int calculateDearrangements(int lastIndex){
        if(lastIndex == 0 || lastIndex == 1) return lastIndex;
        else if(memo.find(lastIndex) != memo.end()) return memo[lastIndex];
        else{
            memo[lastIndex] = (lastIndex-1) * (calculateDearrangements(lastIndex - 1) + calculateDearrangements(lastIndex - 2));
            return memo[lastIndex];
        }
    }
};

class CountDearrangementsIterative{
    vector<int> array;
    public:
    CountDearrangementsIterative(vector<int> inp){this->array = inp;}
    int countDearrangementsIt(){
        //Base case
        int memo[2] = {0,1};

        for(int iter=2; iter<=array.size(); iter++){
            int lastIndex1 = iter-1, lastIndex2 = iter-2, newIndex = iter;

            // get mod 2 index
            lastIndex1&=1; lastIndex2&=1; newIndex&=1;

            memo[newIndex] = (iter-1) * (memo[lastIndex1] + memo[lastIndex2]);
        }

        return memo[array.size()&1];
    }
};




int main(){
    countDerrangements cd({1,2,3});
    cout << "Number of dearrangements: " << cd.calculateDearrangements(3) << endl;
    CountDearrangementsIterative cdi({1,2,3});
    cout << "Number of dearrangements: " << cdi.countDearrangementsIt() << endl;


    return 0;
}