#include <bits/stdc++.h>
using namespace std;

/*
TStrongly Connected Components (SCC) using Tarjan's Algorithm
Basic Idea:
1. **Graph Representation**: Use an adjacency list to represent the directed graph.
2. **DFS Traversal**: Perform a depth-first search (DFS) to explore the graph.
3. **Discovery and Low Link Values**: Maintain discovery times and low link values for each vertex to identify SCCs.
4. **Stack for SCCs**: Use a stack to keep track of the vertices in the current DFS path.
5. **SCC Conditions**: 
   - A vertex is the root of an SCC if its low link value equals its discovery time.
   - Pop vertices from the stack until the root vertex is reached to form an SCC.
   
Implementation Details:
- Use `discoveryTime` and `lowLink` arrays to store discovery times and low link values.
- Use a `stack` to manage the current DFS path.
- Use a `isInStack` array to check if a vertex is currently in the stack.  
- Use a `time` variable to keep track of the discovery time during DFS.

*/

void dfs(int vertex, vector<list<int>>& adjList, int discoveryTime[], int lowLink[], stack<int>& stack, vector<bool>& isInStack, int& time, vector<vector<int>>& result) {
    discoveryTime[vertex] = lowLink[vertex] = ++time; 
    stack.push(vertex); 
    isInStack[vertex] = true; // Mark the current node as present in stack

    for (int neighbor : adjList[vertex]) {
        if (discoveryTime[neighbor] == 0) { 
            dfs(neighbor, adjList, discoveryTime, lowLink, stack, isInStack, time, result); 
            lowLink[vertex] = min(lowLink[vertex], lowLink[neighbor]); // Update lowLink value of vertex after recursion
        } 
        else if (isInStack[neighbor]) { // If neighbor is in stack, Update lowLink value of vertex
            lowLink[vertex] = min(lowLink[vertex], discoveryTime[neighbor]);
        }
    }

    // If vertex is a head node, pop the stack and add an SCC to the result
    if (lowLink[vertex] == discoveryTime[vertex]) {
        vector<int> scc;
        int w;
        do {
            w = stack.top();
            scc.push_back(w);
            isInStack[w] = false; 
            stack.pop();
        } while (w != vertex);
        result.push_back(scc); // Add the current SCC to the result
    }
}

vector<vector<int>> SCC(int vsize, vector<list<int>>& adjList) {
    int discoveryTime[vsize], lowLink[vsize]; // Arrays to store discovery and lowLink values
    vector<bool> isInStack(vsize, false); // Array to check if vertex is in stack
    stack<int> stack; // Stack for DFS
    int time = 0;
    vector<vector<int>> result; // Vector to store the strongly connected components

    for (int iter = 0; iter < vsize; iter++)
        discoveryTime[iter] = lowLink[iter] = 0;

    for (int iter = 0; iter < vsize; iter++)
        if (discoveryTime[iter] == 0)
            dfs(iter, adjList, discoveryTime, lowLink, stack, isInStack, time, result);

    return result;
}

void printSCCs(const vector<vector<int>>& result) {
    for (const auto& scc : result) {
        cout << "SCC: ";
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    auto testGraph = [](int vsize, initializer_list<pair<int, int>> edges) {
        vector<list<int>> adjList(vsize);
        for (auto& edge : edges)
            adjList[edge.first].push_back(edge.second);
        return SCC(vsize, adjList); // Return the SCCs
    };

    cout << "SCCs in first graph:\n";
    printSCCs(testGraph(5, {{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}}));

    cout << "SCCs in second graph:\n";
    printSCCs(testGraph(4, {{0, 1}, {1, 2}, {2, 3}}));

    cout << "SCCs in third graph:\n";
    printSCCs(testGraph(7, {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {1, 4}, {1, 6}, {3, 5}, {4, 5}}));

    cout << "SCCs in fourth graph:\n";
    printSCCs(testGraph(11, {{0, 1}, {0, 3}, {1, 2}, {1, 4}, {2, 0}, {2, 6}, {3, 2}, {4, 5}, {4, 6}, {5, 6}, {5, 7}, {5, 8}, {5, 9}, {6, 4}, {7, 9}, {8, 9}, {9, 8}}));

    cout << "SCCs in fifth graph:\n";
    printSCCs(testGraph(5, {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {3, 0}, {4, 2}}));

    return 0;
}