/*
This program aims to find all possible paths between two given vertices in an undirected unweighted graph.
*/

#include <bits/stdc++.h>
using namespace std;

// Stores visited path in the queue
struct QueueNode{
    int vertex;
    string pathFromSource;

    QueueNode(int v, string p): vertex(v), pathFromSource(p){}
    int getVertex(){ return vertex; }
    string getPath(){ return pathFromSource; }
};


void addEdge(vector<vector<int>>& adj, int source, int destination){
	adj[source].push_back(destination);
	adj[destination].push_back(source);
}

// Modified BFS call with path length update
vector<string> BFS(vector<vector<int>>& adj, int source, int destination){
	list<QueueNode> queue; // Holds the BFS vertices as discovered
	vector<bool> visited (adj.size(), false); // initially all vertices are not visited.
    vector<string> paths;

    // initializing the BFS Queue with start vertes=x
	visited[source] = true;
    QueueNode src (source, to_string(source));
	queue.push_back(src);

	while (!queue.empty()) {
        // Until queue gets empty, pick one vertex from queue and process
		QueueNode frontNode = queue.front();
		queue.pop_front();
        int u = frontNode.getVertex();

        // For the current neighbour, if its not visited, mark it as visited and update the distance vector
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
                //Do not mark destination as visited to find all possible paths
				if(adj[u][i] != destination) visited[adj[u][i]] = true;

                //Store the neighbour to the queue
                string newPath = frontNode.getPath()+ to_string(adj[u][i]);
                QueueNode newNode(adj[u][i], newPath);
				queue.push_back(newNode);

                // If we reached the destination vertex by BFS, it is through the shortest path from start by BFS rule. 
				if (adj[u][i] == destination) paths.emplace_back(newPath);
			}
		}
	}
    // Control reaches here when all vertices have been traversed by BFS.
	return paths;
}

// This function calls BFS and constructs the path from source to destination using parent vector
void computeShortedDistanceBFS(vector<vector<int>>& adj, int source, int destination)
{
    //Call BFS and check the results. BFS ensures results are sorted in ascending order of path length.
    vector<string> res = BFS(adj, source, destination);

	if (res.empty()) {
		cout << "Error: Source and destination are not connected in this graph.\n";
		return;
	}
    else{// Output statements
        cout << "Possible paths between " << source << " and " << destination << " is: " << endl;

        // Print all possible paths with their lengths
        for(int iter=0; iter<res.size(); iter++){
            cout << "Length " << res[iter].size() << ": ";
            for(int iter2=0; iter2<res[iter].size(); iter2++){
                cout << res[iter][iter2];
                if(iter2 !=res[iter].size()-1) cout << "->";
            }
            cout << endl;
        }
    }    
}

int main()
{
    // Declaring an adjacency list for 10 vertex graph
    vector<vector<int>> adj(10); 

    // Adding edges to the graph
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 0, 9);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 2, 7);
	addEdge(adj, 3, 4);
	addEdge(adj, 4, 5);
	addEdge(adj, 4, 6);
	addEdge(adj, 5, 6);
	addEdge(adj, 6, 3);
	addEdge(adj, 7, 9);

    // This function does the BFS traversal and outputs result if both 0 & 9 are connected
	computeShortedDistanceBFS(adj, 0, 9);
	return 0;
}
