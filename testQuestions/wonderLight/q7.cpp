#include<cstdlib>
using namespace std;

int main(){
    void *p = malloc(1024*1024);
    while(1){}
}

/*
If we kill the process, the 1MB memory will be:
A. Retained in memory
B. Locked in memory
C. Returned back to the free pool by Operating System
D. None of the above


Correct Answer: C
*/