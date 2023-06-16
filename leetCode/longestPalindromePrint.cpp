#include<iostream>
using namespace std;
string max_palin="";
int max_palin_len=0;

void findMaxPalindrome(string s){
    for(int i=0;i<s.size();i++){
        int left=i-1, right=i+1;

        //loop to right to find strings like aaaaaa.
        while(s[i]==s[right]) right++;

        while(left>0 && s[left]==s[r])
    }
}



int main(){
    string s="abaasaabasdesa";

    return 0;
}