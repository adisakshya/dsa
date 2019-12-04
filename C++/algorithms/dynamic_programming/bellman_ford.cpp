/**
 * Bellman Ford
 * 
 * Single source shortest path.
 * 
 * Complexity
 * 
 * Time: O(VE)
 * Space: O(V)
 * 
 */

#include<bits/stdc++.h>
#define INT_MAX 100000 // Override INT_MAX
using namespace std;

/* Bellman Ford */
void BellmanFord(int graph[][3], int V, int E, int source) {

    int dist[V];
    for(int i=0; i<V; i++) {
        dist[i] = INT_MAX;
    }

    dist[source] = 0;

    for(int i=0; i<V-1; i++) {
        for(int j=0; j<E; j++) {
            if(dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]]) {
                dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
            }
        }
    }

    cout << "Vertex Distance from source\n";
    for(int i=0; i<V; i++) {
        cout << i << "\t\t" << dist[i] << "\n";
    }

}

/* Main function */
int main() {

    // Graph
    int graph[][3] = {
        { 1, 2, 3 },
        { 1, 3, 2 },
        { 4, 3, -3 },
        { 0, 2, 4 },
        { 1, 4, 2 },
        { 0, 1, -1 },
        { 3, 2, 5 },
        { 3, 1, 1 }
    };

    // Source vertex
    int source = 0;

    // Vertex
    int V = 5;

    // Edges
    int E = 8;

    // Function call
    BellmanFord(graph, V, E, source);

    return 0;

}