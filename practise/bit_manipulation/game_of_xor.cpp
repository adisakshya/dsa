/**
 * Problem Name: Game of XOR
 * Problem Url: https://practice.geeksforgeeks.org/problems/game-of-xor/0
 * Problem Statement: 
 *      You are given an array A[] of size N. 
 *      Now, we call the value of an array the bit-wise XOR of all elements it contains. 
 *      For example, the value of the array [1,2,3] = 1^2^3.
 *      Now, Your task is to find the bit-wise XOR of the values of all sub arrays of array A.
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Time Comlexity: O(n/2) where n is length of input array
 * Space Complexity: O(1)
*/
int gameResult(int arr[], int n) {
    if(!(n & 1)) {
        // Array of even length
        return 0;
    } else {
        // XOR of alternative elements
        int res = 0;
        for(int i=0; i<n; i+=2) {
            res ^= arr[i];
        }
        return res;
    }
}

/**
 * Main
 * 
*/
int main() {
    int t = 0;
    cin >> t;
    while(t--) {
        int n = 0;
        cin >> n;
        int arr[n] = {0};
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cout << gameResult(arr, n) << '\n';
    }
    return 0;
}