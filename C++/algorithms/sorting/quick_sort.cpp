/**
 * Quick Sort
 * 
 * Sort a sequence of numbers (integers) using quick sort.
 * 
 * Complexity
 * 
 * Time:
 * 
 * Best:    O(nlogn)
 * Average: O(nlogn)
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

/* Partition */
int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<=high-1; j++) {
        
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }

    }

    swap(&arr[i+1], &arr[high]);
    return (i + 1);

}

/* Quick Sort */
void quick_sort(int arr[], int low, int high) {

    if(low >= high) {
        return;
    }

    int pi = partition(arr, low, high);

    quick_sort(arr, low, pi-1);
    quick_sort(arr, pi+1, high);

}

/* Main Function */
int main() {

    // Array
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);

    // Function Call
    int low = 0;
    int high = n - 1;
    quick_sort(arr, low, high);

    // Print Array
    print_array(arr, n);

    return 0;
}