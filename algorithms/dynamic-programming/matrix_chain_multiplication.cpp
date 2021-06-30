/**
 * Matrix Chain Multiplication
 * 
 * Given chain of N-matrix <a1,a2,a3...,aN>
 * Every matrix A(i,j), has dimensions (P(i-1) * P(i)).
 * Fully parenthesise the product in a way that
 * minimize number of scaler multiplications.
 * 
 * Complexity
 * 
 * Time: O(n^3)
 * Space: O(n^2)
 * 
 */

#include<bits/stdc++.h>
using namespace std;

/* Print Parenthesis */
void parenthesis(int i, int j, int n, int *bracket, char &name) {

    // one matrix in current segment
    if(i==j) {
        cout << name++;
        return;
    }

    cout << "(";

    // Put brackets around subexpression
    // from i to brackets[i][j]
    parenthesis(i, *((bracket+i*n)+j), n, bracket, name);

    // Put brackets around subexpression
    // from brackets[i][j] + 1 to j
    parenthesis(*((bracket+i*n)+j)+1, j, n, bracket, name);

    cout << ")"; 
    
}

/* Matrix Chain Multiplication */
void matrix_chain_multiplication(int p[], int n) {

    // Cost Matrix
    int m[n][n];

    // Store brackets
    int bracket[n][n];

    // Multiplying one matrix
    for(int i=1; i<n; i++) {
        m[i][i] = 0;            // Cost = 0
    }

    // Iterate on chain length "L"
    for(int L=2; L<n; L++) {

        // Row
        for(int i=1; i<n-L+1; i++) {

            int j = i + L - 1;
            m[i][j] = INT_MAX;

            // i <= k < j
            for(int k=i; k<j; k++) {

                // compute cost/scaler multiplications
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]) {
                    
                    m[i][j] = q;
                    bracket[i][j] = k;

                }

            }

        }

    }

    // Print Matrix
    // First mtrix = 'A' (say), Second = 'B' and so on
    char matrix = 'A';
    cout << "Optimal Parenthesization is: ";
    parenthesis(1, n-1, n, (int *)bracket, matrix);

}

/* Main Function */
int main() {

    // Dimensions of matrix
    int dim[] = { 40, 20, 30, 10, 30};
    int n = sizeof(dim)/sizeof(dim[0]);

    // Function Call
    matrix_chain_multiplication(dim, n);

    return 0;
}