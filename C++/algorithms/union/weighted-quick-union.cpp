/**
 * Dynamic Connectivity (incremental) using Quick Union (Weighted Approach)
 * 
 * Dynamically maintain information about connected components of graph and,
 * answer query about two nodes x and y whether they are in the same connected components or not.
 * Doing M unions and find opertion on set of N objects
 * 
 * Complexity
 * 
 * Time:
 *  Worst:   O(N + MLog2(N))
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
        // Array to hold size of trees
        int sz[MAX_NODES];
        // Size of array
        int size = 0;

        // Function to find root of node
        int root(int p) {
            while(p != ids[p]) {
                p = ids[p];
            }
            return p;
        }

    public:
        // Contructor
        Union(int n) {
            // Initialize sets
            size = n;
            for(int i=0; i<size; i++) {
                ids[i] = i;
                sz[i] = 1;
            }
        }

        // Function to connect two nodes
        void make_union(int p, int q) {
            // Change root of smaller tree to point to root of larger tree
            int proot = root(p);
            int qroot = root(q);
            int psz = sz[proot];
            int qsz = sz[qroot];
            if(psz < qsz) {
                ids[proot] = qroot;
                sz[qroot] += psz;
            } else {
                ids[qroot] = proot;
                sz[proot] += qsz;
            }
        }

        // Function to check if two nodes are connected
        bool connected(int p, int q) {
            return root(p) == root(q);
        }
};

/* Main Function */
int main() {

    // Initialize union
    Union u = Union(6);

    // Create unions
    u.make_union(0, 1);
    u.make_union(2, 3);
    u.make_union(3, 4);
    u.make_union(2, 5);

    // Queries
    cout << u.connected(0,1) << endl;
    cout << u.connected(0,4) << endl;
    cout << u.connected(1,2) << endl;
    cout << u.connected(2,3) << endl;
    cout << u.connected(3,4) << endl;
    cout << u.connected(4,5) << endl;

    return 0;
}