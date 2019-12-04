/* UNDER DEVELOPMENT */

// /**
//  * Optimal Binary Search Tree
//  * 
//  * Given sequence of "N-distinct keys" in sorte order (increasing)
//  * For each key we have frequency (fi) that shows number of queries for
//  * key (ki).
//  * Build a BST from those keys.
//  * 
//  * Complexity
//  * 
//  * Time: O(n^4)
//  * Space: 
//  * 
//  */

// #include<bits/stdc++.h>
// using namespace std;

// /* Global Variables */

// // Number of keys
// int n = 7;

// // Cost Matrix
// int cost[n+2][n+2];

// // Root matrix
// int root[n+1][n+1];

// // Key array
// char key[n];

// // Frequency array
// char freq[n];

// /* Optimal Binary Search Tree */
// void optimal_bst(int n) {

//     // Assume cost of any BST is maximum INT_MAX
//     for(int i=1; i<=n; i++) {
//         for(int j=i+1; j<=n+1; j++) {
//             cost[i][j] = INT_MAX;
//         }
//     }

//     // Cost of OBST of zero nodes
//     for(int i=1; i<=n+1; i++) {
//         cost[i][i-1] = 0;
//     }

//     // Cost of OBST of one node
//     for(int i=1; i<=n; i++) {
//         cost[i][i] = freq[i];
//         root[i][i] = i;
//     }

//     // OBST for j+1 nodes
//     for(int j=1; j<=n-1; j++) {
//         for(int i=1; i<=n-j; i++) {
//             for(int r=i; r<=i+j; r++) {
                
//                 int t = cost[i][r-1] + cost[r+1][i+j];
//                 for(int k=i; k<=i+j; k++) {
//                     t += freq[k];
//                 }
//                 if(t < cost[i][i+j]) {
//                     cost[i][i+j] = t;
//                     root[i][i+j] = r;
//                 }

//             }
//         }
//     }
// }

// /* Main Function */
// int main() {

//     // Initialize key & frequency arrays
//     char key[] = { "A", "B", "C", "D", "E", "F", "G" };
//     int freq[] = { 4, 2, 1, 3, 5, 2, 1 };

//     // Function Call
//     optimal_bst(n);

//     // Print Results
//     cout << "Optimal Tree of cost " << cost[1][n] << " is: ";
//     printOBST(1,n);

//     cout << "\n\nCost Array: \n";
//     for(int i=1; i<=n; i++) {
//         for(j=1; j<=n; j++) {
//             cout << setw(3) << cost[i][j];
//         }
//         cout << "\n\n";
//     }

//     cout << "\nRoot Array: \n";
//     for(int i=1; i,=n; i++) {
//         for(j=1; j,=n; j++) {
//             cout << Setw(2) << root[i][j];
//         }
//         cout << "\n";
//     }

//     return 0;
// }