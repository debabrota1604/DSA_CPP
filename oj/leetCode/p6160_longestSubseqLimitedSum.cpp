#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> res; int i,j; bool fl;

        sort(nums.begin(),nums.end());

        for(i=0;i<queries.size();i++){
            int maxSum = queries[i], localSum=0; fl=true;
            for(j=0; j<nums.size();j++){
                localSum +=nums[j];
                if (localSum > maxSum){
                    res.push_back(j);
                    fl = false; break;
                }
            }
            if (fl){
                if (j==nums.size()-1)
                    res.push_back(j+1);
                else{
                    res.push_back(j);
                }
            }
        }
        return res;
    }

    void display( vector<int> v){
        for(auto i: v){ cout << i << " ";}
        cout << endl;
    }
};

int main(){

    Solution s;
    //vector<int> nums {4,5,2,1,1} , queries {4,10,13};
    vector<int> nums {624082} , queries {972985,564269,607119,693641,787608,46517,500857,140097};

    s.display(s.answerQueries(nums, queries));

    return 0;
}