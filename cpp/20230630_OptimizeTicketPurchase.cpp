#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> days;
    vector<int> costs;
    unordered_map<int, int> memory;
    int sz;


    int solve(int index){
        if(index >= sz) return 0;
        if(memory.find(index) != memory.end()) return memory[index];
        
        int res = INT_MAX, iter;
        res = min(res, solve(index +1) + costs[0]);
        
        iter = index;
        while(days[iter] < days[index] +7 &&  iter<sz) iter++;
        res = min(res, solve(iter) + costs[1]);
        
        iter = index;
        while(days[iter] < days[index] +30 &&  iter<sz) iter++;
        res = min(res, solve(iter) + costs[2]);
        memory[index] = res;

        cout << index << ":" << res << endl;
        return res;
    }


    int solve_iterative(){
        
    }
    
    int mincostTickets(vector<int> days, vector<int> costs) {
        this->days = days;
        this->costs = costs;
        this->sz = days.size();
        return solve(0);
    }
};




int main(){
    Solution s;
    cout << "Minimum cost for travel: " << s.mincostTickets({2,5}, {1,4,25}) << endl;
    s.memory.clear();
    cout << "Minimum cost for travel: " << s.mincostTickets({1,3,4,5,7,8,10}, {2,7,20}) << endl;
    s.memory.clear();
    cout << "Minimum cost for travel: " << s.mincostTickets({1,4,6,7,8,20}, {2,7,15}) << endl;




    return 0;
}