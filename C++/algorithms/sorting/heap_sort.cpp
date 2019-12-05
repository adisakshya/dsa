/**
 * Heap Sort
 * 
 * Sort a sequence of numbers (integers) using heap sort.
 * 
 * Complexity
 * 
 * Time:
 * 
 * Best:    O(nlogn)
 * Average: O(nlogn)
 * Worst:   O(nlogn)
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

/* Heapify */
void heapify(int arr[], int n, int i) {

    // largest -> root
    int largest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }

}

/* Heap Sort */
void heap_sort(int arr[], int n) {

    // Build Heap
    for(int i=(n/2)-1; i>=0; i--) {
        heapify(arr, n, i);
    }

    // Extract element from heap
    for(int i=n-1; i>=0; i--) {

        // move root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on reduced heap
        heapify(arr, i, 0);
    }

}

/* Main Function */
int main() {

    // Array
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);

    // Function Call
    heap_sort(arr, n);

    // Print Array
    print_array(arr, n);

    return 0;
}