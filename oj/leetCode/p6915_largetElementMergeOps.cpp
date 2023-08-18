#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        //Step1: Convert array into linkedList to delete from middle index
        list<int> inp(nums.begin(), nums.end());
        list<int>  deleted {0};
                
        //Step2: Traverse the list from right to left and replace elements
        auto iter = inp.rbegin(), pre = iter; 
        iter++;

        while(iter !=inp.rend()){ 
            if(*iter <= *pre){
                // Add iter to pre and delete pre.
                *pre += *iter;
                deleted.splice(deleted.begin(), inp, iter.base());
                iter = pre++;
            }
            else{
                iter++; pre++;
            }
        }
        return *inp.begin();
    }
};

