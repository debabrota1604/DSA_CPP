#include<iostream>
#include<map>
using namespace std;
#define map_print 1

int min3(int i, int j, int k){ return min(min(i,j),k);}

int uglyNumber(int n){
    int i,i2,i3,i5, arr[n]; i=1; i2=i3=i5=0; arr[0]=1;
    while(i<n){
        arr[i] = min3(arr[i2]*2, arr[i3]*3, arr[i5]*5);
        arr[i2]*2 == arr[i] ? i2++:1;        
        arr[i3]*3 == arr[i] ? i3++:1;        
        arr[i5]*5 == arr[i] ? i5++:1;
        i++;
    }
    for(auto i=0;i<n-1;i++){ cout << arr[i] << " "; }
    return arr[i-1];
}

int main(){
    int n; 
    cout << "Ugly numbers are only divisible by 2, 3 and 5. This program finds the n-th ugly number.\nInput n: ";
    cin >> n;
    cout << "Answer: " << uglyNumber(n) << endl;

    return 0;
}