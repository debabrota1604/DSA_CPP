#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v = 0xABCDEF00;
    unsigned char *p = (unsigned char *) &v;
    for(;p<((unsigned char *)&v +4);++p){
        printf("%02x\n",*p);
    }
    return 0;
}