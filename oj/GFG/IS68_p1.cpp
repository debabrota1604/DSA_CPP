#include<bits/stdc++.h>
using namespace std;

class Solution {

  public:
    int noConseBits(int query) {
        vector<int> bin; int temp = query, res=0;

        //generate bit string
        while (temp>0){
            bin.emplace_back(temp%2);
            temp = temp/2;
        }
        // Disable set bits.
        for(int i=bin.size()-1; i>=0; i--){
            if(i-2<0){break;}
            if (bin[i] == 1 && bin[i-1] ==1 && bin[i-2] ==1 ){
                bin[i-2] =0;
            }
        }

        //Reconstruct decimal integer
        int pow=1;
        for(int i=0; i<bin.size(); i++){
            res += pow*bin[i];
            pow *=2;
        }
        return res;
    }
};



int main(){
    Solution s; int inp; cin  >> inp;
    cout << s.noConseBits(inp) << endl;



}