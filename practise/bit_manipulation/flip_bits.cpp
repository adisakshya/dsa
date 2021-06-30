/**
 * Problem Name: Flip Bits
 * Problem Url: https://practice.geeksforgeeks.org/problems/flip-bits/0/
 * Problem Statement: 
 *      Given an array arr[] consisting of 0’s and 1’s. 
 *      A flip operation is one in which you turn 1 into 0 and a 0 into 1.
 *      You have to do atmost one “Flip” operation of a subarray. 
 *      Then finally display maximum number of 1 you can have in the array.
*/

#include<bits/stdc++.h>
using namespace std;

int flipBits(int arr[], int n) {
    bool flag = 0;
    int maxLength = 0,
        currentLength = 0,
        ones = 0,
        l = 0,
        r = 0;
    while(r <= n) {
        flag = arr[l] | arr[r];
        if(!flag) {
            currentLength++;
            if(currentLength > maxLength) {
                maxLength = currentLength;
            }   
            r++;
        } else {
            currentLength = 0;
            r++;
            l = r;
        }
        if(arr[r]) {
            ones++;
        }
    }
    return (ones + maxLength);
}

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
        cout << flipBits(arr, n) << '\n';
    }
    return 0;
}