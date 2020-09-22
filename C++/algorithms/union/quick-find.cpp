/**
 * Dynamic Connectivity (incremental) using Quick Find (Eager Approach)
 * 
 * Dynamically maintain information about connected components of graph and,
 * answer query about two nodes x and y whether they are in the same connected components or not.
 * Doing M unions and find opertion on set of N objects
 * 
 * 
 * Complexity
 * 
 * Time:
 *  Worst:   O(N*M)
 * 
 * Space: O(N)
 * 
 */

#include<bits/stdc++.h>
#define MAX_NODES 10
using namespace std;

class Union {
    private:
        // Array to hold representatives of connected-components
        int ids[MAX_NODES];
        // Size of array
        int size = 0;

    public:
        // Contructor
        Union(int n) {
            // Initialize sets
            size = n;
            for(int i=0; i<size; i++) {
                ids[i] = i;
            }
        }

        // Function to connect two nodes
        void make_union(int p, int q) {
            int pid = ids[p];
            int qid = ids[q];
            for(int i=0; i<size; i++) {
                if(ids[i] == pid) {
                    ids[i] = qid;
                }
            }
        }

        // Function to check if two nodes are connected
        bool connected(int p, int q) {
            return ids[p] == ids[q];
        }
};

/* Main Function */
int main() {

    // Initialize union
    Union u = Union(10);

    // Create unions
    u.make_union(0, 1);
    u.make_union(2, 3);
    u.make_union(3, 4);
    u.make_union(2, 5);

    // Queries
    cout << u.connected(0,1) << endl;
    cout << u.connected(1,2) << endl;
    cout << u.connected(2,3) << endl;
    cout << u.connected(3,4) << endl;
    cout << u.connected(4,5) << endl;

    return 0;
}