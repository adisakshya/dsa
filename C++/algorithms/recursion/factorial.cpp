/**
 * Factorial (Recursive)
 * 
 * Find factorial of a number
 * 
 * Complexity
 *      Time: 
 *          Worst Case: O(N)
 *      Space: O(N)
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// Function to find factorial of a number
int factorial(int n) {
    // Base condition
    if(!n) {
        return 1;
    }
    // Recursive call
    return n*factorial(n-1);
}

int main() {
    int n = 9;
    cout << "Factorial of " << n << " is: " << factorial(n) << endl;
    return 0;
}