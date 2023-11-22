#include<bits/stdc++.h>
using namespace std;

#define MAXLIMIT 100000000

void normalAllocation(){
    int normalVar = 10; //gets alloacted on stack and cleared after function returns
}

void memLeakAllocation(){
    int *heapVar = new int (10); // memory allocated on heap and reference name is stored on stack
    // memory won't be freed if explicit free is not called.
}

void memLeakAllocationFixed(){
    /* Practice is to deallocate the memory after its use is complete.*/
    
    int *heapVar = new int (10);
    free (heapVar);
}

int main(){
    for(int iter=0; iter<MAXLIMIT; iter++){
        //normalAllocation();
        //memLeakAllocation();
        memLeakAllocationFixed();
    }
    cout << "Waiting for user input after memory allocation. Press any key to exit\n";
    getchar();
}