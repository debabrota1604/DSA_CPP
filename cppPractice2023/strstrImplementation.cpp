#include<iostream>
using namespace std;

class Solution{
    public:
    int strstr(string h, string n){

        if (n == "") return 0;
        if (h.size() < n.size()) return 0;

        int startIndex = 0, matchSize=0;
        for (auto i=0;i<h.size();i++){
            if (h[i] == n[0]){ //match of first char
                int i1=i, i2=0;
                while(h[i1++] == n[i2++]){
                    if (i2 == n.size()) return i; //return the first occurence
                }
            }
        }

        return -1;
    }

};


int main(){
    string a, b;
    a = "aaa";
    b = "o";
    cout  << a << " " << b << endl;
    Solution s;
    cout << "strstr output: " << s.strstr(a,b) << endl;

    return 0;
}