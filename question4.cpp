//Name: Kelly Huang
//Student ID: 1123526
//Date of Submission: 10th, December

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Function to find the sum of weights of edges in MST using Prim's Algorithm
int primMST(int V, vector<vector<pair<int, int>>>& adj) {
    // Priority queue to store (weight, vertex) pairs, min-heap based on weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Vector to store the minimum weight of the edge connecting to each vertex
    vector<int> key(V, INT_MAX);
    
    // Vector to track if the vertex is included in the MST
    vector<bool> inMST(V, false);
    
    // Start from vertex 0
    pq.push({0, 0}); // (weight, vertex)
    key[0] = 0;
    
    int mstWeight = 0;
    
    // While there are vertices not yet included in the MST
    while (!pq.empty()) {
        // Extract the vertex with the minimum weight edge
        int u = pq.top().second;
        pq.pop();
        
        // If vertex u is already in MST, skip it
        if (inMST[u]) continue;
        
        // Add its weight to the total MST weight
        mstWeight += key[u];
        
        // Mark vertex u as included in MST
        inMST[u] = true;
        
        // Traverse all adjacent vertices of u
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;  // adjacent vertex
            int weight = neighbor.second;  // weight of the edge
            
            // If vertex v is not in MST and weight of (u, v) is less than current key[v]
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;  // Update the key value
                pq.push({key[v], v});  // Push the new edge into the priority queue
            }
        }
    }
    
    return mstWeight;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V): ";
    cin >> V;
    cout << "Enter the number of edges (E): ";
    cin >> E;
    
    // Initialize the adjacency list
    vector<vector<pair<int, int>>> adj(V);
    
    cout << "Enter the edges (vertex1, vertex2, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});  // As the graph is undirected
    }
    
    // Calculate the sum of weights of the MST
    int result = primMST(V, adj);
    
    cout << "Sum of weights of edges in the MST: " << result << endl;
    
    return 0;
}
