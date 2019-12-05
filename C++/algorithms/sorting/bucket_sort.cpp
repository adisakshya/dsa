/**
 * Bucket Sort
 * 
 * Sort a sequence of numbers (integers) using bucket sort.
 * 
 * Complexity
 * 
 * Time:
 * 
 * Best:    O(n)
 * Average: O(n)
 * Worst:   O(n^2)
 * 
 * Space:   O(n)
 * 
 */

#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

/* Print Array */
void print_array(float arr[], int n) {
    // Print Sorted Array
    cout << "Sorted Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

/* Bucket Sort */
void bucket_sort(float arr[], int n) {

    // Create "N-empty" buckets
    vector <float> buckets[n];

    // Put array elements in buckets
    for(int i=0; i<n; i++) {
        int bi = arr[i]*n;
        buckets[bi].push_back(arr[i]);
    }

    // Sort Individual Buckets
    for(int i=0; i<n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }

}

/* Main Function */
int main() {

    // Array
    float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr)/sizeof(arr[0]);

    // Function Call
    bucket_sort(arr, n);

    // Print Array
    print_array(arr, n);

    return 0;
}