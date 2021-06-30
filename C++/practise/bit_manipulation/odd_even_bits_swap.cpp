/**
 * Problem Name: Swap all odd and even bits
 * Problem Url: https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits/0
 * Problem Statement: 
 *      Given an unsigned integer N. 
 *      The task is to swap all odd bits with even bits. 
 *      For example, if the given number is 23 (00010111), it should be converted to 43(00101011). 
 *      Here, every even position bit is swapped with adjacent bit on right side(even position bits are highlighted in binary representation of 23), 
 *      and every odd position bit is swapped with adjacent on left side.
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Time Comlexity: O(1)
 * Space Complexity: O(1)
*/
unsigned int getSwappedResult(int n) {
    // Get all even bits
    unsigned int even = n & 0xAAAAAAAA;
    // Get all odd bits
    unsigned int odd = n & 0x55555555;
    // Left shift even bits by 1
    even >>= 1;
    // Right shift even bits by 1
    odd <<= 1;
    // Combine even and odd bits
    return even | odd;
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
        cout << getSwappedResult(n) << '\n';
    }
    return 0;
}