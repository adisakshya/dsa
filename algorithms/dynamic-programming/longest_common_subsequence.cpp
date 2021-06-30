/**
 * Matrix Chain Multiplication
 * 
 * Given two sequences X, Y
 * Find maximum length common subsequence of X & Y
 * 
 * Complexity
 * 
 * Time: O(m*n)
 * Space: O(m*n)
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int lcs(char *X, char *Y, int m, int n) {

    // LCS matrix
    int L[m+1][n+1];
    
    // Iterate on X
    for(int i=0; i<=m; i++) {

        // Iterate on Y
        for(int j=0; j<=n; j++) {

            if(i == 0 || j == 0) {
                L[i][j] = 0;
            } else if(X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }

        }

    }

    return L[m][n];
}

/* Main Function */
int main() {

    // Sequences
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    
    // Length of sequences
    int m = strlen(X), n = strlen(Y);

    // Function call & print result
    cout << "Length of LCS is: " << lcs(X, Y, m, n);

    return 0;
}