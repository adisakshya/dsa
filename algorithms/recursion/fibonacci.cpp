/**
 * Fibonacci Series (Recursive)
 * 
 * Print the fibonacci series
 * 
 * Complexity
 *      Time: 
 *          Worst Case: 2^N
 *          Best Case: 2^(N/2)
 *      Space: O(N)
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// Function to get n-th term in the fibonacci series
int fibonacci(int n) {
    // Base conditions
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    // Recursive call
    return (fibonacci(n-1) + fibonacci(n-2));
}

int main() {
    int n = 11;
    cout << "Fibonacci Series of " << n << " numbers is: \n";
    for(int i=1; i<=n; i++) {
        cout << fibonacci(i) << " ";
    }
    return 0;
}