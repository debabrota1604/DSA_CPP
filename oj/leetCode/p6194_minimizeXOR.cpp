#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getBin(int x){
        string s="";
        while(x>0){
            s= to_string(x%2) +s;
            x = x/2;
        }
        return s;
    }
    int getSetBit(int x){
        int res=0;
        while(x>0){
            if(x%2==1) res++;
            x=x/2;
        }
        return res;
    }
    int minimizeXor(int num1, int num2) {
        int desBit = getSetBit(num2), curBit = getSetBit(num1);
        cout << "Num1: " << num1 << " Binary: " << getBin(num1) << endl;
        cout << "Num2: " << num2 << " Binary: " << getBin(num2) << endl;

        if(desBit == curBit) return num1;
        else{
            if(desBit> curBit){
                //add a bit from LSB
                int addBits = desBit - curBit, it=0,res=num1;
                cout << "Add bits " << addBits << endl;
                while(addBits){
                    int x = 1<< it, y = res&x;
                    if(y==0){
                        res |= 1<<it; addBits--;
                    } 
                    it++;
                }
                cout << "Result " << res << " Binary: " << getBin(res) << endl;
                return res;
            }
            else{
                //remove a bit from MSB
                int subBits = curBit-desBit, it=0,res=num1;
                cout << "Sub bits " << subBits << endl;
                while (subBits){
                    int x = 1<< it, y = res&x;
                    if(y){
                        res ^= 1<<it; subBits--;
                    }
                    it++;
                }
                cout << "Result " << res << " Binary: " << getBin(res) << endl;
                return res;
            }
        }
    }
};


int main(){
    Solution s;
    cout << s.minimizeXor(1,12) << endl;
    cout << s.minimizeXor(25,72) << endl;



    return 0;
}