//Name: Kelly Huang
//Student ID: 1123526
//Date of Submission: 10th, December

Question1: Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.

Input:
6
8
0 1
0 5
0 3
2 4
0 4
2 1
5 3
4 3

Output:
[0]: 1 3 4 5 
[1]: 0 2 
[2]: 1 4 
[3]: 0 4 5 
[4]: 0 2 3 
[5]: 0 3 

Question2: Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Traversal (BFS) starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.

Input:
4
1 3 -1
0 3 -1
3 -1
0 2 -1

Output:
BFS Traversal: 0 1 3 2 

Question3: Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Traversal (DFS) starting from vertex 0, visiting vertices from left to right as per the adjacency list, and return a list containing the DFS traversal of the graph.

Input: 
4
1 2 3 -1
0 3 -1
0 3 -1
0 1 2 -1

Output:
DFS Traversal: 0 1 3 2

Question4: Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

Input:
3
3
1 0 3
1 2 4
2 0 2

Output:
Sum of weights of edges in the MST: 5