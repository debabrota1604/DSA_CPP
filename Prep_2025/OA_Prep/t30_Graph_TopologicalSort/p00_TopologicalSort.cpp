#include <bits/stdc++.h>
using namespace std;

/*
Toplogical Sort using DFS
Basic idea:
1. **Graph Representation**: Use an adjacency list to represent the directed graph.
2. **DFS Traversal**: Perform a depth-first search (DFS) to explore the graph.
3. **Stack for Result**: Use a stack to store the vertices in topological order.
4. **Visited Array**: Maintain a visited array to track which vertices have been visited.
5. **Post-order Traversal**: Push vertices onto the stack after all their neighbors have been visited (post-order).
*/

void dfs(int vertex, vector<vector<int>> &adjList, vector<bool> &isVisited, stack<int> &sortedStack) {
    isVisited[vertex] = true; // Mark current node as visited
    for (int neighbor : adjList[vertex])  // Recur for adjacent vertices
        if (!isVisited[neighbor])
            dfs(neighbor, adjList, isVisited, sortedStack);
    sortedStack.push(vertex); // Push current vertex to stack
}

vector<vector<int>> createAdjacencyList(int numVertices, vector<vector<int>> &edges) {
    vector<vector<int>> adjList(numVertices);
    for (auto &edge : edges)
        adjList[edge[0]].push_back(edge[1]);
    return adjList;
}

vector<int> topologicalSort(int numVertices, vector<vector<int>> &edges) {
    stack<int> sortedStack; // Stack to store result
    vector<bool> isVisited(numVertices, false); // Visited array
    vector<vector<int>> adjList = createAdjacencyList(numVertices, edges); // Construct adjacency list

    for (int i = 0; i < numVertices; i++) // Call helper function for all vertices
        if (!isVisited[i])
            dfs(i, adjList, isVisited, sortedStack);

    vector<int> sortedList;
    while (!sortedStack.empty()) { // Append stack contents to result
        sortedList.push_back(sortedStack.top());
        sortedStack.pop();
    }
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