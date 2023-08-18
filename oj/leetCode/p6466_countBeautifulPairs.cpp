#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int i, int j){
        if(i==1 || j==1) return true;
        else if(i%j!=0 && j%i !=0) return true;
        return false;
    }
    int msb(int num){
        while(num >10) num/=10;
        return num;
    }
    int lsb(int num){
        return num%10;
    }
    int countBeautifulPairs(vector<int> nums) {
        int res=0;
        unordered_map<int, unordered_map<int,bool>> memo;
        for(int it1=0; it1<nums.size();it1++){
            for(int it2=it1; it2<nums.size();it2++){
                if(it1 ==it2) continue;
                int v1 = msb(nums[it1]), v2 = lsb(nums[it2]);
                if(memo.find(v1) != memo.end() && memo[v1].find(v2) != memo[v1].end()) continue;
                if(isPrime(v1, v2)){ 
                    res++;
                    memo[v1][v2] = 1;
                }
                cout << "it1: " << it1 << " it2: " << it2 << " :: " << msb(nums[it1]) << ":" << lsb(nums[it2]) << " Res: " << res << endl;
            }
        }
        return res;
        
    }
};


int main(){
    Solution s;
    cout << s.countBeautifulPairs({2,5,1,4}) << endl;
    cout << s.countBeautifulPairs({11,21,12}) << endl;
    cout << s.countBeautifulPairs({68,8,84,14,88,42,53}) << endl;
    cout << s.countBeautifulPairs({31,25,72,79,74}) << endl;


    return 0;
}