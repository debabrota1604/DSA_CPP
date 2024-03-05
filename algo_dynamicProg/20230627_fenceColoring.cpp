#include<bits/stdc++.h>
using namespace std;

// Given n fence & k colours, determine the number of ways to color the fences such that no more than two adjacent fences should have the same color.

// Recurrence Relation: 
#define MOD 1000000007
class FenceColoring{
    int fenceCount, colorCount;
    public:
    FenceColoring(int fCount, int cCount){
        this->fenceCount = fCount;
        this->colorCount = cCount;
    }

    int add(int a, int b){
        return (a %MOD + b %MOD) %MOD;
    }
    int mul(int a, int b){
        return (a %MOD * b %MOD) %MOD;
    }

    int countPossibleWays(int fences, int colors){
        if(fences == 1) return colors;
        if(fences == 2) return add(colors, mul(colors, colors -1));
        return add(mul(countPossibleWays(fences-2, colors), colors-1), 
                    mul(countPossibleWays(fences-1,colors), colors-1)); 
    }
};

int main(){

}

