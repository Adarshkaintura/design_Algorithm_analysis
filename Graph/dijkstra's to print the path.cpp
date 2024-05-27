#include <iostream>
#include <limits.h>

#define V 5 // Assuming the maximum number of vertices is 5, change accordingly

// Function to find the vertex with minimum distance value, from the set of vertices
// not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}
  
// Function to print the constructed distance array
void printSolution(int dist[], int n, int parent[]) {
    std::cout << "Vertex   Distance from Source   Path\n";
    for (int i = 0; i < V; i++) {
        std::cout << i << " \t\t " << dist[i] << "\t\t";
        int j = i;
        while (j != -1) {
            std::cout << j;
            j = parent[j];
            if (j != -1) std::cout << " -> ";
        }
        std::cout << "\n";
    }
}
  
// Function that implements Dijkstra's single source shortest path algorithm for a graph
// represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
    int parent[V]; // Array to store shortest path tree

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1; // Initialize parent array with -1
    }
  
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
  
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
  
        // Mark the picked vertex as processed
        sptSet[u] = true;
  
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it is not in sptSet, there is an edge from u to v,
            // and the total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Update parent array
            }
        }
    }
  
    // Print the constructed distance array
    printSolution(dist, V, parent);
}
  
// Driver program to test above function
int main() {
    int graph[V][V];
    std::cout << "Enter the weighted, undirected graph represented using adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cin >> graph[i][j];
        }
    }
    int src;
    std::cout << "Enter the source vertex: ";
    std::cin >> src;
    dijkstra(graph, src);
    return 0;
}
