#include<bits/stdc++.h>
using namespace std;

void printSpiralMat(vector<vector<int>> v){
    //initialize the tracker lists
    int incrY[] = {1,0,-1,0}, incrX[] = {0,1,0,-1},limX[] = {0,v.size()-1}, limY[]={0,v[0].size()-1};
    int indX=0,indY=0,newX, newY, dir=0;

    for(int it=0; it<v.size()*v[0].size()-1; it++){   //total number of elements to print m*n.
        cout << v[indX][indY] << " ";
        newX = indX + incrX[dir]; newY = indY + incrY[dir];

        if(newX >= limX[0] && newX <limX[1] //newX within the range lim[0] & lim[1]
        && newY >= limY[2] && newY <limY[3]){  //newY within the range lim[2] & lim[3]
            indX = newX; indY = newY;
        }
        if(newX ==limX[1]) limY[1]--;
        else if(newX == limX[0])
        else{
            dir = (dir+1)%4;
            indX +=incrX[dir]; indY +=incrY[dir];
        }
    }
}



int main(){
    vector<vector<int>> v1 {{1,2,3},{4,5,6},{7,8,9}}, 
    v2 = {{1,3,5,7}, {2,4,6,8}, {9,11,13,15},{10,12,14,16}};



    return 0;
}