/**
 * Problem Name: Find the Odd Occurence
 * Problem Url: https://practice.geeksforgeeks.org/problems/find-the-odd-occurence/0
 * Problem Statement: 
 *      Given an array of positive integers where all numbers occur even number of times except one number which occurs odd number of times. 
 *      Find the number.
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Time Comlexity: O(n), where n is length of input array
 * Space Complexity: O(1)
*/

/**
 * Main
*/
int main() {
    int t = 0;
    cin >> t;
    while(t--) {
        int n = 0;
        cin >> n;
        
        int arr[n] = {0};
        int res = 0;
        
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            res ^= arr[i];
        }
        
        cout << res << '\n';
    }
    return 0;
}