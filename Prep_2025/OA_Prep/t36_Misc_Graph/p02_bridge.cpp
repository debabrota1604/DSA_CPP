#include <iostream>
#include <list>
#include <vector>

using namespace std;

void findBridgesUtil(int vertex, vector<list<int>>& adjList, vector<bool>& visited, vector<int>& discoveryTime,
                     vector<int>& lowLink, int parent, int& time) {
    visited[vertex] = true;
    discoveryTime[vertex] = lowLink[vertex] = ++time;

    for (int neighbor : adjList[vertex]) {
        if (neighbor == parent)
            continue;

        if (visited[neighbor]) {
            lowLink[vertex] = min(lowLink[vertex], discoveryTime[neighbor]);
        } else {
            findBridgesUtil(neighbor, adjList, visited, discoveryTime, lowLink, vertex, time);
            lowLink[vertex] = min(lowLink[vertex], lowLink[neighbor]);

            if (lowLink[neighbor] > discoveryTime[vertex])
                cout << vertex << " " << neighbor << endl;
        }
    }
}

void findBridges(int numVertices, vector<list<int>>& adjList) {
    vector<bool> visited(numVertices, false);
    vector<int> discoveryTime(numVertices, -1);
    vector<int> lowLink(numVertices, -1);
    int time = 0;

    for (int i = 0; i < numVertices; i++)
        if (!visited[i])
            findBridgesUtil(i, adjList, visited, discoveryTime, lowLink, -1, time);
}

int main() {
    cout << "\nBridges in first graph \n";
    int numVertices1 = 5;
    vector<list<int>> adjList1(numVertices1);
    adjList1[1].push_back(0);
    adjList1[0].push_back(1);
    adjList1[0].push_back(2);
    adjList1[2].push_back(0);
    adjList1[2].push_back(1);
    adjList1[0].push_back(3);
    adjList1[3].push_back(0);
    adjList1[3].push_back(4);
    adjList1[4].push_back(3);
    findBridges(numVertices1, adjList1);

    cout << "\nBridges in second graph \n";
    int numVertices2 = 4;
    vector<list<int>> adjList2(numVertices2);
    adjList2[0].push_back(1);
    adjList2[1].push_back(0);
    adjList2[1].push_back(2);
    adjList2[2].push_back(1);
    adjList2[2].push_back(3);
    adjList2[3].push_back(2);
    findBridges(numVertices2, adjList2);

    cout << "\nBridges in third graph \n";
    int numVertices3 = 7;
    vector<list<int>> adjList3(numVertices3);
    adjList3[0].push_back(1);
    adjList3[1].push_back(0);
    adjList3[1].push_back(2);
    adjList3[2].push_back(1);
    adjList3[2].push_back(0);
    adjList3[0].push_back(2);
    adjList3[1].push_back(3);
    adjList3[3].push_back(1);
    adjList3[1].push_back(4);
    adjList3[4].push_back(1);
    adjList3[1].push_back(6);
    adjList3[6].push_back(1);
    adjList3[3].push_back(5);
    adjList3[5].push_back(3);
    adjList3[4].push_back(5);
    adjList3[5].push_back(4);
    findBridges(numVertices3, adjList3);

    return 0;
}