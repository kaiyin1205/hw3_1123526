//Name: Kelly Huang
//Student ID: 1123526
//Date of Submission: 10th, December

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

// Function to create adjacency list
vector<vector<int> > createAdjacencyList(int V, vector<pair<int, int> > &edges) {
    vector<vector<int> > adjList(V);

    // Loop through each edge and populate the adjacency list
    for (auto &edge : edges) {
        int u = edge.first;  // first node of the edge
        int v = edge.second; // second node of the edge

        // Add the edge to both nodes since it's undirected
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Sort each adjacency list for each node
    for (int i = 0; i < V; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    return adjList;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V): ";
    cin >> V;

    cout << "Enter the number of edges (E): ";
    cin >> E;

    vector<pair<int, int> > edges;
    cout << "Enter the edges in the format 'u v' (0-based indexing):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    // Create adjacency list
    vector<vector<int> > adjList = createAdjacencyList(V, edges);

    // Print the adjacency list
    for (int i = 0; i < adjList.size(); i++) {
        cout << "[" << i << "]: ";
        for (int j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
