#include<bits/stdc++.h>
using namespace std;

//short modules
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define CY cout << "YES"
#define CN cout << "NO"
#define REP(i,a,b) for(int i=a; i<=b; i++)

typedef long long ll; // Bcoz defining a long long int initialized to 1 at any eqn requires 1LL.
typedef vector<int> vi;
typedef pair<int, int> pi;



int main(){ 
    int n1=1,n2=4,n3=5,n4=11,n5=35;
    //Bitwise Operators-----------------------------------------------------------

    // AND operator : Both the params should have the same bit set.

    //Use 1: Check if n is even or odd
    if( (n1 & 1) ==0) cout << n1 << " is even!\n";
    if( (n1 & 1) ==1) cout << n1 << " is odd!\n";

    // OR operator : At least one of the params should have the same bit set



    // XOR Operator: there must be a change of set bit in the params


    // NOT operator: Inverts the bits. ~x = -x-1.


    //Bit Shifts-------------------------------------------------------------------
    //Left Bit Shift: x<<k shifts the LSB towards MSB with k zeros. 

    //Use 1: Multiply by 2
    cout << "Twice of " << n1 << " is " << (n1<<1) << endl;
    cout << "Eight times of " << n2 << " is " << (n2<<3) << endl;

    //Right Bit Shift: x>>k shifts the MSB towards LSB k times.

    //Use 1: Divide by 2
    cout << "Half of " << n3 << " is " << (n3>>1) << endl;
    cout << "One-forth of " << n4 << " is " << (n4>>2) << endl;

    //Bit Masks--------------------------------------------------------------------
    //A bit mask like 1<<k has a single bit set at position k and all other bits zero.

    //Use 1: Check if a bit is set in a number
    REP(i,0,31){
        if(n5 & 1<<i) cout << "Bit " << i << " is set in " << n5 << endl;
    }

    //Use 2: Check if a bit is unset in a number
    REP(i,0,31){
        //check the condition
        //if((n5 & 1<<i) | ~(1<<i)) cout << "Bit " << i << " is not set in " << n5 << endl;
    }

    //Use 3: set k-th bit
    cout << "Value of " << n1 << " after setting 10th bit is " << (n1 | (1<<10)) << endl;


    //Use 4: Unset k-th bit
    cout << "Value of " << n4 << " after resetting 3rd bit to zero is " << (n4 & ~(1<<3)) << endl;

    //Use 5: Invert k-th bit
    cout << "Value of " << n2 << " after inverting 3rd bit is " << (n2 ^(1<<3)) << endl;

    return 0;
}