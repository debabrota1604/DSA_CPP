#include<bits/stdc++.h>
using namespace std;

/*
Find the nth number that contains the digit k or is divisible by k. (2 <= k <= 9)
Example –
if n = 15 & k = 3
Answer : 33
(3, 6, 9, 12, 13, 15, 18, 21, 23, 24, 27, 30, 31, 32, 33)
*/
bool digitPresent(int num, int digit){
    while(num>0){
        if(num%10 == digit) return true;
        num /=10;
    }
    return false;
}

int solve(int n, int k){
    int counter=1, test=2;
    while(counter <n){
        if(digitPresent(test, k) || test%k ==0) counter++;
        test++;
    }
    return test;
}

int main(){
    cout << solve(15,3) << endl;

    return 1;

}