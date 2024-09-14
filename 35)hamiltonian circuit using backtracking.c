#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

// Function prototypes
void hamiltonianCircuit(int graph[V][V]);
bool isSafe(int v, int graph[V][V], int path[], int pos);
bool hamiltonianCircuitUtil(int graph[V][V], int path[], int pos);

// Function to print the Hamiltonian circuit
void printSolution(int path[]) {
    printf("Hamiltonian Circuit:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}

// Function to check if the vertex can be added to the Hamiltonian circuit
bool isSafe(int v, int graph[V][V], int path[], int pos) {
    // Check if the vertex is adjacent to the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;
  
    // Check if the vertex has not already been added to the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
  
    return true;
}

// Recursive utility function to find the Hamiltonian circuit
bool hamiltonianCircuitUtil(int graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the path
    if (pos == V) {
        // Check if there is an edge from the last added vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
  
    // Try different vertices as the next candidate in the Hamiltonian circuit
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            // Recur to add the next vertex to the path
            if (hamiltonianCircuitUtil(graph, path, pos + 1))
                return true;
            // If adding vertex v doesn't lead to a solution, remove it from the path and backtrack
            path[pos] = -1;
        }
    }
  
    return false;
}

// Main function to find the Hamiltonian circuit
void hamiltonianCircuit(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
  
    // Start from vertex 0 as the initial vertex in the Hamiltonian circuit
    path[0] = 0;
    if (!hamiltonianCircuitUtil(graph, path, 1)) {
        printf("Hamiltonian Circuit does not exist\n");
        return;
    }
  
    // Print the Hamiltonian circuit
    printSolution(path);
}

// Main driver code
int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = { {0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0} };
    hamiltonianCircuit(graph);
    return 0;
}
