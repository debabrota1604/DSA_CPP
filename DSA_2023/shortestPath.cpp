/*
This program aims to find the distance between two given vertices in an undirected unweighted graph.
We can use BFS as the first time it encounters a vertex it would be the shorted path to that vertex.
*/

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj, int source, int destination){
	adj[source].push_back(destination);
	adj[destination].push_back(source);
}

// Modified BFS call with path length update
bool BFS(vector<vector<int>>& adj, vector<int>& parent, vector<int>& distance, int source, int destination){
	list<int> queue; // Holds the BFS vertices as discovered
	vector<bool> visited (adj.size(), false); // initially all vertices are not visited.

    // initializing the BFS Queue with start vertes=x
	visited[source] = true;
	distance[source] = 0;
	queue.push_back(source);

	while (!queue.empty()) {
        // Until queue gets empty, pick one vertex from queue and process
		int u = queue.front();
		queue.pop_front();

        // For the current neighbour, if its not visited, mark it as visited and update the distance vector
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
				visited[adj[u][i]] = true;
				distance[adj[u][i]] = distance[u] + 1;
				parent[adj[u][i]] = u;
				queue.push_back(adj[u][i]);

                // If we reached the destination vertex by BFS, it is through the shortest path from start by BFS rule. 
				if (adj[u][i] == destination) return true;
			}
		}
	}
    // Control reaches here when all vertices have been traversed by BFS but destination not found. Return error status.
	return false;
}

// This function calls BFS and constructs the path from source to destination using parent vector
void computeShortedDistanceBFS(vector<vector<int>>& adj, int source, int destination)
{
    // Parent array stores the immediate parent to any discovered vertex. Needed to find the path to destination.
	vector<int> parent (adj.size(),-1), distance (adj.size(), INT_MAX);

	if (BFS(adj, parent, distance, source, destination) == false) {
		cout << "Error: Source and destination are not connected in this graph.\n";
		return;
	}

    // BFS returned true. So, check the parent vector to construct the path to destination
	vector<int> path;
	int iter = destination;
	path.push_back(iter);
	while (parent[iter] != -1) { // start vertex has parent as -1
		path.push_back(parent[iter]);
		iter = parent[iter];
	}

    // Output statements
	cout << "Shortest path length between " << source << " and " << destination << " is: " << distance[destination] << endl;

	cout << "The path from source to destination can be found through these vertices: ";
	for(int iter = path.size()-1; iter >= 0; iter--)	cout << path[iter] << " ";
    cout << endl;
}

int main()
{
    // Declaring an adjacency list for 10 vertex graph
    vector<vector<int>> adj(10); 

    // Adding edges to the graph
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 7);
	addEdge(adj, 3, 4);
	addEdge(adj, 3, 7);
	addEdge(adj, 4, 5);
	addEdge(adj, 4, 6);
	addEdge(adj, 5, 6);
	addEdge(adj, 6, 3);
	addEdge(adj, 6, 7);
	addEdge(adj, 6, 9);
	addEdge(adj, 7, 9);

    // This function does the BFS traversal and outputs result if both 0 & 9 are connected
	computeShortedDistanceBFS(adj, 0, 9);
	return 0;
}
