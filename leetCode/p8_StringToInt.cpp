#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        bool numStart=false, sign=true; int num=0;
        for (int i=0;i<s.size();i++){
            if (s[i] == ' ' ){ 
                numStart = false; 
            }
            else if (s[i] == '+' ){
                numStart = true;
            }
            else if(s[i] == '-'){
                numStart = true;
                sign = false;
            }
            else if ( isdigit(s[i]) ){
                numStart = true;
                num = 10 * num + (s[i] - '0');
            }
            else{
                return num;
            }
        }  


        return num;      
    }
};
