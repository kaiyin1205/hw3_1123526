//Name: Kelly Huang
//Student ID: 1123526
//Date of Submission: 10th, December

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal
vector<int> bfsTraversal(int V, vector<vector<int>> &adj) {
    vector<int> bfsResult; // To store the BFS traversal result
    vector<bool> visited(V, false); // To keep track of visited nodes
    queue<int> q; // Queue for BFS

    // Start BFS from node 0
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfsResult.push_back(node);

        // Traverse neighbors of the current node
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfsResult;
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

    // Perform BFS traversal
    vector<int> bfsResult = bfsTraversal(V, adj);

    // Print the BFS traversal result
    cout << "BFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
