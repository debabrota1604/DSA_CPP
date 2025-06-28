#include <bits/stdc++.h>
using namespace std;

/*
Basic Idea:
Use vanilla DFS to explore the graph and count the number of connected components
If removing a vertex results in more than one component, then that vertex is an articulation point.
Loop through each vertex, mark it as visited, and perform DFS on its neighbors.
If number of components formed is more than 1, then that vertex is an articulation point.
*/


void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

vector<vector<int>> constructadj(int V, vector<vector<int>> &edges) {
    
    vector<vector<int>> adj(V);
    
    for (auto it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    return adj;
}

vector<int> articulationPoints(int V, vector<vector<int>> &edges) {
    
    vector<vector<int>> adj = constructadj(V, edges);
    vector<int> res;

    for (int i = 0; i < V; ++i) {
        vector<bool> visited(V, false);
        visited[i] = true;
        
        // count DFS calls from i's neighbors
        int comp = 0; 
        for (auto it : adj[i]) {
            if (comp > 1) break;  // early stop if already more than 1 component

            if (!visited[it]) {
                dfs(it, adj, visited); // explore connected part
                comp++;
            }
        }

        // if more than one component forms, it's an articulation point
        if (comp > 1)
            res.push_back(i);
    }

    if (res.empty())
        return {-1};

    return res;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};

    vector<int> ans = articulationPoints(V, edges);
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}