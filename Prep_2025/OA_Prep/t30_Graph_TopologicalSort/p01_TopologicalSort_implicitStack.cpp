#include <bits/stdc++.h>
using namespace std;

/*
This code implements a topological sort using Depth First Search (DFS) with an implicit stack.
The output is reversed to get the correct topological order.
*/


void dfs(int vertex, vector<vector<int>> &adjList, vector<bool> &isVisited, vector<int> &sortedList) {
    isVisited[vertex] = true; // Mark current node as visited
    for (int neighbor : adjList[vertex])  // Recur for adjacent vertices
        if (!isVisited[neighbor])
            dfs(neighbor, adjList, isVisited, sortedList);
    sortedList.push_back(vertex); // Append current vertex to sorted list (post-order)
}

// Constructs adjacency list from edges
vector<vector<int>> createAdjacencyList(int numVertices, vector<vector<int>> &edges) {
    vector<vector<int>> adjList(numVertices);
    for (auto &edge : edges)
        adjList[edge[0]].push_back(edge[1]);
    return adjList;
}

// Performs topological sort on the graph
vector<int> topologicalSort(int numVertices, vector<vector<int>> &edges) {
    vector<int> sortedList; // List to store result
    vector<bool> isVisited(numVertices, false); // Visited array
    vector<vector<int>> adjList = createAdjacencyList(numVertices, edges); // Construct adjacency list

    for (int i = 0; i < numVertices; i++) // Call helper function for all vertices
        if (!isVisited[i])
            dfs(i, adjList, isVisited, sortedList);

    reverse(sortedList.begin(), sortedList.end()); // Reverse the list to get topological order
    return sortedList;
}

int main() {
    int numVertices = 6; // Number of vertices
    vector<vector<int>> edges = {{2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}}; // Graph edges

    vector<int> sortedList = topologicalSort(numVertices, edges); // Perform topological sort

    for (int node : sortedList)  // Print the result
        cout << node << " ";
    cout << endl;
    return 0;
}