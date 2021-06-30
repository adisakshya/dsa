/**
 * Selection Sort
 * 
 * Sort a sequence of numbers (integers) using selection sort.
 * 
 * Complexity
 * 
 * Time:
 * 
 * Best:    O(n^2)
 * Average: O(n^2)
 * Worst:   O(n^2)
 * 
 * Space:   O(1)
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

/* Swap */
void swap(int *x, int *y) {
    
    int temp = *x;
    *x = *y;
    *y = temp;
    
}

/* Selection Sort */
void selection_sort(int arr[], int n) {

    for(int i=0; i<n-1; i++) {
        int min_index = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
    }

}

/* Main Function */
int main() {

    // Array
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);

    // Function Call
    selection_sort(arr, n);

    // Print Array
    print_array(arr, n);

    return 0;
}