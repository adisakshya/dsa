/**
 * Insertion Sort
 * 
 * Sort a sequence of numbers (integers) using insertion sort.
 * 
 * Complexity
 * 
 * Time:
 * 
 * Best:    O(n)    // already sorted
 * Average: O(n^2)
 * Worst:   O(n^2)
 * 
 * Space: O(1)
 * 
 */

#include<bits/stdc++.h>
using namespace std;

/* Print Array */
void print_array(int arr[], int n) {
    // Print Sorted Array
    cout << "Sorted Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

/* Insertion Sort */
void insertion_sort(int arr[], int n) {

    for(int i=1; i<n; i++) {

        int key = arr[i];

        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;

    }
    
    print_array(arr, n);

}

/* Main Function */
int main() {

    // Array
    int arr[] = { 40, 20, 30, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Function Call
    insertion_sort(arr, n);

    return 0;
}