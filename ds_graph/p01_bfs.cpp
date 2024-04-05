#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void bfs(vector<vector<int> >& adjList, int startNode,
		vector<bool>& visited)
{
	// Create a queue for BFS
	queue<int> q;

	// Mark the current node as visited and enqueue it
	visited[startNode] = true;
	q.push(startNode);

	// Iterate over the queue
	while (!q.empty()) {
		// Dequeue a vertex from queue and print it
		int currentNode = q.front();
		q.pop();
		cout << currentNode << " ";

		// Get all adjacent vertices of the dequeued vertex
		// currentNode If an adjacent has not been visited,
		// then mark it visited and enqueue it
		for (int neighbor : adjList[currentNode]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
}

// Function to add an edge to the graph
void addEdge(vector<vector<int> >& adjList, int u, int v)
{
	adjList[u].push_back(v);
}

int main()
{
	// Number of vertices in the graph
	int vertices = 5;

	// Adjacency list representation of the graph
	vector<vector<int> > adjList(vertices);

	// Add edges to the graph
	addEdge(adjList, 0, 1);
	addEdge(adjList, 0, 2);
	addEdge(adjList, 1, 3);
	addEdge(adjList, 1, 4);
	addEdge(adjList, 2, 4);

	// Mark all the vertices as not visited
	vector<bool> visited(vertices, false);

	// Perform BFS traversal starting from vertex 0
	cout << "Breadth First Traversal starting from vertex "
			"0: ";
	bfs(adjList, 0, visited);

	return 0;
}

/*
Time Complexity of BFS Algorithm: O(V + E)
    BFS explores all the vertices and edges in the graph. In the worst case, it visits every vertex and edge once. Therefore, the time complexity of BFS is O(V + E), where V and E are the number of vertices and edges in the given graph.
Space Complexity of BFS Algorithm: O(V)
    BFS uses a queue to keep track of the vertices that need to be visited. In the worst case, the queue can contain all the vertices in the graph. Therefore, the space complexity of BFS is O(V), where V and E are the number of vertices and edges in the given graph.


Applications of BFS in Graphs:
    BFS has various applications in graph theory and computer science, including:
        Shortest Path Finding: BFS can be used to find the shortest path between two nodes in an unweighted graph. By keeping track of the parent of each node during the traversal, the shortest path can be reconstructed.
        Cycle Detection: BFS can be used to detect cycles in a graph. If a node is visited twice during the traversal, it indicates the presence of a cycle.
        Connected Components: BFS can be used to identify connected components in a graph. Each connected component is a set of nodes that can be reached from each other.
        Topological Sorting: BFS can be used to perform topological sorting on a directed acyclic graph (DAG). Topological sorting arranges the nodes in a linear order such that for any edge (u, v), u appears before v in the order.
        Level Order Traversal of Binary Trees: BFS can be used to perform a level order traversal of a binary tree. This traversal visits all nodes at the same level before moving to the next level.
        Network Routing: BFS can be used to find the shortest path between two nodes in a network, making it useful for routing data packets in network protocols.
*/