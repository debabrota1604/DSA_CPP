#include<bits/stdc++.h>
using namespace std;

/*
There is an undirected tree with n nodes labeled from 1 to n. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree.

Return the number of valid paths in the tree.

A path (a, b) is valid if there exists exactly one prime number among the node labels in the path from a to b.

Note that:

The path (a, b) is a sequence of distinct nodes starting with node a and ending with node b such that every two adjacent nodes in the sequence share an edge in the tree.
Path (a, b) and path (b, a) are considered the same and counted only once.
 

Example 1:


Input: n = 5, edges = [[1,2],[1,3],[2,4],[2,5]]
Output: 4
Explanation: The pairs with exactly one prime number on the path between them are: 
- (1, 2) since the path from 1 to 2 contains prime number 2. 
- (1, 3) since the path from 1 to 3 contains prime number 3.
- (1, 4) since the path from 1 to 4 contains prime number 2.
- (2, 4) since the path from 2 to 4 contains prime number 2.
It can be shown that there are only 4 valid paths.
Example 2:


Input: n = 6, edges = [[1,2],[1,3],[2,4],[3,5],[3,6]]
Output: 6
Explanation: The pairs with exactly one prime number on the path between them are: 
- (1, 2) since the path from 1 to 2 contains prime number 2.
- (1, 3) since the path from 1 to 3 contains prime number 3.
- (1, 4) since the path from 1 to 4 contains prime number 2.
- (1, 6) since the path from 1 to 6 contains prime number 3.
- (2, 4) since the path from 2 to 4 contains prime number 2.
- (3, 6) since the path from 3 to 6 contains prime number 3.
It can be shown that there are only 6 valid paths.
 

Constraints:

1 <= n <= 105
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
The input is generated such that edges represent a valid tree.

*/

// Code was compiled successfully, but result is coming zero. Need to debug.

class Solution {
public:
    bool isPrime2(int num){
        cout << num << endl;
        if(num <2) return false;
        for(int iter=2; iter<=sqrt(num); iter++){
            if(num%iter==0) return false;
        }
        return true;
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> parent;
        long long int res=0;
        
        //prepare parent map to traverse from leaf to root
        for(int i=0; i<edges.size(); i++){
            parent[edges[i][1]] = parent[edges[i][0]];
        }
        
        // Check for all nodes from leaf to root
        for(int iter=n; iter>0; iter--){
            int primeCount=0, currNode, currPar;
            
            if(parent.find(currNode) == parent.end()) break;
            currNode = iter, currPar = parent[currNode];
            
            // Check for all parents for this node
            while(true){
                if(isPrime2(currNode)) primeCount++;
                if(isPrime2(currPar)) primeCount++;
                
                if(primeCount ==1) res++;
                else if(primeCount >1) break;
                
                
                if(parent.find(currNode) == parent.end()) break;
                currNode = currPar;
                currPar = parent[currNode];
            }
        }
        return res;
        
        
    }
};