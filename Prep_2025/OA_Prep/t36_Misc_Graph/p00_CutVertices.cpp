#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected graph with V vertices and E edges, find all the articulation points in the graph.

The Tarjan's algo in brief:
1. **Graph Representation**: Use an adjacency list to represent the graph.
2. **DFS Traversal**: Perform a depth-first search (DFS) to explore the graph.
3. **Discovery and Low Values**: Maintain discovery times and low values for each vertex to identify articulation points.
3. **Articulation Point Conditions**: 
   - A vertex is an articulation point if it is not the root and has a child such that the child's low value is greater than or equal to the vertex's discovery time.
   - The root is an articulation point if it has more than one child in the DFS tree.

Implementation details:
 * - Use a `visited` array to track visited vertices.
 * - Use `disc` and `low` arrays to store discovery times and low values.
 * - Use a `isAP` array to mark articulation points.
 * - Use a `time` variable to keep track of the discovery time during DFS.
*/

// Constructs the adjacency list from the given edges.
vector<vector<int>> constructAdj(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]); // Add edge from u to v
        adj[edge[1]].push_back(edge[0]); // Add edge from v to u (undirected graph)
    }
    return adj;
}

// DFS function to find articulation points using Tarjan's algorithm.
void dfs(vector<vector<int>>& adj, int u, vector<int>& visited,
                vector<int>& disc, vector<int>& low, int& time, int parent, vector<int>& isAP) {
    visited[u] = 1; // Mark current node as visited
    disc[u] = low[u] = ++time; // Initialize discovery time and low value
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++; // Increment child count for unvisited neighbors
            dfs(adj, v, visited, disc, low, time, u, isAP); // Recurse for unvisited vertices

            low[u] = min(low[u], low[v]); // Update low value of u

            // Check if u is an articulation point (non-root case)
            if (parent != -1 && low[v] >= disc[u]) isAP[u] = 1;
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]); // Update low value for back edge
        }
    }

    // If u is root and has more than one child, it's an articulation point
    if (parent == -1 && children > 1) isAP[u] = 1;
}

// Function to find articulation points in the graph.
vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj = constructAdj(V, edges);
    vector<int> disc(V, 0), low(V, 0), visited(V, 0), isAP(V, 0);
    int time = 0;

    // Call DFS for each unvisited vertex
    for (int u = 0; u < V; u++) {
        if (!visited[u]) dfs(adj, u, visited, disc, low, time, -1, isAP);
    }

    vector<int> result;
    for (int u = 0; u < V; u++) {
        if (isAP[u]) result.push_back(u); // Store articulation points
    }

    return result.empty() ? vector<int>{-1} : result; // Return -1 if no APs found
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    vector<int> ans = articulationPoints(V, edges);

    for (int u : ans) cout << u << " ";
    cout << endl;

    return 0;
}