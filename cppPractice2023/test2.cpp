#include<bits/stdc++.h>
using namespace std;

string toBin(int n){
    string res=""; char c;
    while(n>0){ 
        c= n%2+'0'; n/= 2; 
        res= c+res; //Append in reverse
    }
    return res;
}
string toBinOpt(int n){
    string res=""; 
    for(int k=31; k>=0; k--){
        if (n & (1<<k)) res='1'+res;
        else res='0'+res;
    }
    return res;
}

int setBitK(int n, int k){
    return n | (1<<k);
}
int resetBitK(int n, int k){
    return n & !(1<<k);
}
int invertBitK(int n, int k){
    return n ^ !(1<<k);
}
int resetLastSetBit(int n){
    return n & (n-1);
}
int resetAllBitsExceptLast(int n){
    return n & -n;
}
int invertAllBitsAfterLastBit(int n){
    return n | (n-1);
}
bool bitAtPos(int n, int k){
    return (n & (1<<k));
}
void swapByAddition(int &x, int &y){
    x=x+y; 
    y=x-y;
    x=x-y;
}
void swapByMultiplication(int &x, int &y){
    x=x*y; 
    y=x/y;
    x=x/y;
}
void swapByXOR(int &x, int &y){
    x^=y; y^=x; x^=y;
}

bool isOdd(int num){
    return num&1;
}
bool isEven(int num){
    return !(num&1); //cannot AND with 0.
}

int setBits(int n){
    int res=0;
    while(n>0){ if(n%2){res++;} n/= 2;}
    return res;
}

int mult2(int n){
    return n<<1;
}
int div2(int n){
    return n>>1;
}

int compute2PowerK(int k){
    return 1<<k;
}
bool checkBitK(int num, int k){
    return num &(1<<k);
}

int setBitsOpt(int n){
    int res=0;
        //runs for number of bits set
    while(n>0){ n&=(n-1); res++;}
    return res;
}

int resetLsbTillKthBit(int n, int k){
    return n & ((1 << k) - 1);
}

char upper2Lower(char c){
    return c |= ' ';
}
char low2upper(char c){
    return c &= '_';
}

int log2(int n){
    int res=0;
    while(n>>=1) res++; //loops till n is zero, each time divide by 2
    return res; 
}

int computeXOR1toN(int n){
    int cond = n%4;
    if(cond==0) return n;
    else if(cond==1) return 1;
    else if(cond==2) return n+1;
    else return 0;
}

bool isPow2(int n){
    return (n&(n-1))==0 ? 1: 0;
}

vector<bool> toBoolVec(int n){
    vector<bool> res;
    while(n>0){ res.emplace_back(n%2); n/=2;}
    reverse(res.begin(), res.end());
    return res;
}

template<class T>
void dispVec(vector<T> vec){
    cout << "[ ";
    for(auto iter=0;iter<vec.size(); iter++){ cout << vec[iter] << " "; }
    cout << "]\n";
}


int main(){
    int a=5; cin>>a; int x=5, y=10;
    cout << "2 power: " << isPow2(a) << endl;
    cout << "isOdd: " << isOdd(a) << endl;
    cout << "isEven: " << isEven(a) << endl;
    cout << "mult2: " << mult2(a) << endl;
    cout << "div2: " << div2(a) << endl;
    cout << "div2: " << div2(a) << endl;
    cout << "compute2PowerK: " << compute2PowerK(7) << endl;
    cout << "checkBitK: " << checkBitK(a,3) << endl;
    cout << toBin(a) << endl;
    cout << setBits(a) << endl;
    cout << setBitsOpt(a) << endl;
    dispVec(toBoolVec(a));
    cout << x << " " << y << endl;
    swapByAddition(x,y);
    cout << x << " " << y << endl;
    swapByMultiplication(x,y);
    cout << x << " " << y << endl;
    swapByXOR(x,y);
    cout << x << " " << y << endl;

    return 0;
}