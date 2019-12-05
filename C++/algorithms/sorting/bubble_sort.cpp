/**
 * Bubble Sort
 * 
 * Sort a sequence of numbers (integers) using insertion sort.
 * 
 * Complexity
 * 
 * Time:
 * 
 * Best:    O(n^2)
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

/* Swap */
void swap(int *x, int *y) {
    
    int temp = *x;
    *x = *y;
    *y = temp;
    
}

/* Insertion Sort */
void bubble_sort(int arr[], int n) {

    for(int i=0; i<n-1; i++) {

        for(int j=0; j<n-i-1; j++) {

            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }

        }

    }
    
    print_array(arr, n);

}

/* Main Function */
int main() {

    // Array
    int arr[] = { 40, 20, 30, 10, 50};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Function Call
    bubble_sort(arr, n);

    return 0;
}