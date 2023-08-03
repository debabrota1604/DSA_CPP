#include<bits/stdc++.h>
using namespace std;

// Given a knapsack weight capacity of K and an array of weights W with corresponding values V, 
// compute the maximum value of knapsack possible with maximum weight upto K.

class Knapsack{
    int maxWeight;
    vector<int> weights, values;
    unordered_map<int, unordered_map<int,int>> memo;

    public:
    Knapsack(int capacity, vector<int> weights, vector<int> values){
        this->maxWeight = capacity;
        this->weights = weights;
        this->values = values;
    }
    int maxValueSelection(int index,int availableCapacity){
        if(index <0) return 0;
        else if(memo.find(index) != memo.end() && memo[index].find(availableCapacity) != memo[index].end()) return memo[index][availableCapacity];
        else{
            // Calculate weight without the present indexed item
            memo[index][availableCapacity] = maxValueSelection(index-1,availableCapacity);

            if(availableCapacity-weights[index] >=0){
                // Update the value if weight considering current index item is greater.
                memo[index][availableCapacity] = max(memo[index][availableCapacity],maxValueSelection(index-1, availableCapacity-weights[index]) + values[index]);
            }

            //cout << index << "," << availableCapacity << ":" << memo[index][availableCapacity] << endl;
            return memo[index][availableCapacity];
        }
    }
};


int main(){
    Knapsack k(10,{2,3,5,10,12},{2,3,5,10,12});
    cout << "Result: " << k.maxValueSelection(4,16) << endl;
}