#include<iostream>
#include<vector>
using namespace std;


int squareRoot(int num){
    int lo, hi;
    long long mid; // long long to counter integer overflow
    lo = 0;
    hi = num;
    while(lo <= hi){
        mid = lo + (hi-lo)/2;
        if(mid*mid == num) return mid;
        else if(mid*mid > num) hi = mid -1;
        else lo = mid +1;
    }
    return mid;
}

int squareRoot_SaveFloor(int num){
    int lo, hi, mid, ans;
    long long square; // long long to counter integer overflow
    lo = 0;
    hi = num;
    while(lo <= hi){
        mid = lo + (hi-lo)/2;
        square = mid *mid;
        if(square == num) return mid;
        else if(square > num) hi = mid -1;
        else{
            ans = mid; // Save the last lower root
            lo = mid +1;
        }
    }
    return ans;
}

double morePrecision(int num, int precision, int intRoot){
    double factor = 1, stepIncr = intRoot, ans = intRoot;
    for(int iter=0; iter<precision; iter++){
        factor /= 10;
        stepIncr = ans;
        while(stepIncr*stepIncr < num){
            ans = stepIncr;
            stepIncr += factor; // loop until square is less than given num
        }
    }
    return ans;
}


int main(){
    int num = 37;
    cout << squareRoot(num) << endl;
    cout << squareRoot_SaveFloor(num) << endl;

    cout << "Final Root: " << morePrecision(num, 5, squareRoot_SaveFloor(num)) << endl;


    return 0;
}