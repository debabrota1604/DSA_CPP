#include<bits/stdc++.h>
using namespace std; 
 
#define LL long long
#define LD long double
#define CY cout<<"YES\n"
#define cCNn cout<<"NO\n"
#define PR pair<int,int>
 
// 48-57 -> 0-9
// 65-90 -> A-Z
// 97-122 -> a-z
class Solution {
public:
    int reverse(int num){
        int res=0;
        while(num>0){
            res*=10;
            res+=num%10;
            num/=10;
        }
        return res;
    }
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++){
            if(i+reverse(i) == num) return true;
        }
        return false;
    }
};

int main()
{
    Solution s;

    cout << s.sumOfNumberAndReverse(181) << endl;
       
    return 0;
}
