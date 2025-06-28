#include <bits/stdc++.h>
using namespace std;

/*
Kahn's Algorithm for Topological Sort using BFS:
Basic Idea:
1. **Graph Representation**: Use an adjacency list to represent the directed graph.
2. **In-Degree Calculation**: Calculate the in-degree of each vertex (number of incoming edges).
3. **Queue for Zero In-Degree Vertices**: Use a queue to store vertices with in-degree 0.
4. **BFS Traversal**: Process vertices from the queue, adding them to the sorted list and reducing the in-degree of their neighbors.
5. **Cycle Detection**: If the sorted list size is not equal to the number of vertices, the graph contains a cycle. 

Implementation Details:
- Use a vector to store in-degrees of vertices. 
- Use a queue to manage vertices with in-degree 0.
- Process each vertex in the queue, appending it to the sorted list and updating the in-degrees of its neighbors.
- If a neighbor's in-degree becomes 0, add it to the queue.
- If the sorted list size does not match the number of vertices, it indicates a cycle in the graph.
*/

vector<vector<int>> createAdjacencyList(int numVertices, vector<vector<int>> &edges) {
    vector<vector<int>> adjList(numVertices); // Graph represented as an adjacency list
    for (auto &edge : edges) {
        adjList[edge[0]].push_back(edge[1]); // Add directed edge from source to destination
    }
    return adjList;
}

// Performs topological sort using Kahn's algorithm (BFS)
vector<int> topologicalSort(int numVertices, vector<vector<int>> &edges) {
    vector<vector<int>> adjList = createAdjacencyList(numVertices, edges); // Create adjacency list
    vector<int> inDegree(numVertices, 0); // Vector to store in-degree of each vertex

    for (int i = 0; i < numVertices; i++) { // Calculate in-degrees for each vertex
        for (int neighbor : adjList[i]) {
            inDegree[neighbor]++; // Increment in-degree for each neighbor
        }
    }

    queue<int> zeroInDegreeQueue; // Queue to store vertices with in-degree 0
    for (int i = 0; i < numVertices; i++) {
        if (inDegree[i] == 0) {
            zeroInDegreeQueue.push(i);
        }
    }

    vector<int> sortedList; // Vector to store the topological sorted list
    while (!zeroInDegreeQueue.empty()) {
        int vertex = zeroInDegreeQueue.front();
        zeroInDegreeQueue.pop();
        sortedList.push_back(vertex);

        for (int neighbor : adjList[vertex]) {// Decrease in-degree of adjacent vertices
            inDegree[neighbor]--;

            if (inDegree[neighbor] == 0) // Add vertex to queue if in-degree is 0
                zeroInDegreeQueue.push(neighbor); 
        }
    }

    if (sortedList.size() != numVertices) {
        cout << "Graph contains cycle!" << endl;
        return {}; // Return empty vector if cycle is detected
    }

    return sortedList; // Return the topological sorted list
}

int main() {
    int numVertices = 6; // Number of vertices
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}, {5, 1}, {5, 2}}; // Graph edges

    vector<int> sortedList = topologicalSort(numVertices, edges); // Perform topological sort

    for (int vertex : sortedList)
        cout << vertex << " ";
    cout << endl;

    return 0;
}