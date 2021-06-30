/**
 * Dijkastra
 * 
 * Single source shortest path.
 * 
 * Complexity
 * 
 * Time: O(V^2)
 * Space: O(V)
 * 
 */

#include<bits/stdc++.h>
#define V 8
using namespace std;

// Minimum distance node index
int minimum_distance(int dist[], bool sptSet[]) {

    int min = INT_MAX, min_index = -1;

    for(int v=0; v<V; v++) {
        if(!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    // Return minimum index
    return min_index;

}

// Print solution
void print_solution(int dist[]) {
    cout << "Vertex \t\t Distance from source\n";
    for(int i=0; i<V; i++) {
        cout << i << "\t\t " << dist[i] << "\n";
    }
}

/* Dijkastra */
void dijkastra(int graph[V][V], int source) {

    // Distance matrix
    int dist[V];

    // Set
    bool sptSet[V];

    // initialize dist[] and sptSet[]
    for(int i=0; i<V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[source] = 0;

    for(int count=0; count < V-1; count++) {
        int u = minimum_distance(dist, sptSet);
        sptSet[u] = true;

        for(int v=0; v<V; v++) {
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print Result
    print_solution(dist);

}

/* Main function */
int main() {

    // Graph
    int graph[V][V] = {
        { 4, 0, 8, 0, 0, 0, 11, 0 },
        { 0, 4, 0, 0, 0, 0, 8, 0 },
        { 8, 11, 0, 0, 0, 0, 0, 7 },
        { 0, 8, 0, 7, 0, 4, 0, 2 },
        { 0, 0, 2, 0, 0, 0, 7, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 0, 0 }
    };

    // Source vertex
    int source = 0;

    dijkastra(graph, source);

    return 0;

}