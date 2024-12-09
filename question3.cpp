//Name: Kelly Huang
//Student ID: 1123526
//Date of Submission: 10th, December

#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS traversal
void dfsTraversal(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dfsResult) {
    // Mark the node as visited and add it to the DFS result
    visited[node] = true;
    dfsResult.push_back(node);

    // Traverse neighbors of the current node
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsTraversal(neighbor, adj, visited, dfsResult);
        }
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices (V): ";
    cin >> V;

    vector<vector<int>> adj(V);
    cout << "Enter the adjacency list for each vertex:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " (enter neighbors separated by spaces, end with -1): ";
        int neighbor;
        while (cin >> neighbor && neighbor != -1) {
            adj[i].push_back(neighbor);
        }
    }

    // Vector to keep track of visited nodes
    vector<bool> visited(V, false);
    vector<int> dfsResult;

    // Perform DFS traversal starting from node 0
    dfsTraversal(0, adj, visited, dfsResult);

    // Print the DFS traversal result
    cout << "DFS Traversal: ";
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
