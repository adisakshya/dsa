/**
 * Problem Name: Element that appears once where every element occurs twice
 * Problem Url: https://practice.geeksforgeeks.org/problems/element-that-appears-once-where-every-element-occurs-twice/0/
 * Problem Statement: 
 *      Given an array of integers, every element appears twice except for one.
 *      Find that single one in linear time complexity and without using extra memory.
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Time Comlexity: O(n) where n is length of input array
 * Space Complexity: O(1)
*/

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
        int arr[n] = {0},
            res = 0;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            res ^= arr[i];
        }
        cout << res << '\n';
    }
    return 0;
}