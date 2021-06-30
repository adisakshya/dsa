/**
 * Radix Sort
 * 
 * Sort a sequence of numbers (integers) using radix sort.
 * 
 * Complexity
 * 
 * Time:
 * 
 * Best:    O(nk)
 * Average: O(nk)
 * Worst:   O(nk)
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

/* Count Sort */
void count_sort(int arr[], int n, int position) {

    // output array
    int output[n];

    int count[10] = {0};

    // store count of occurences
    for(int i=0; i<n; i++) {
        count[ (arr[i]/position)%10 ]++;
    }

    // change count[i] so that count[i] contain
    // actual position of this digit in output[]
    for(int i=1; i<10; i++) {
        count[i] += count[i-1];
    }

    // Build output array
    for(int i=n-1; i>=0; i--) {
        output[count[ (arr[i]/position)%10 ] - 1] = arr[i];
        count[ (arr[i]/position)%10 ]--;
    }

    for(int i=0; i<n; i++) {
        arr[i] = output[i];
    }

}

/* Radix Sort */
void radix_sort(int arr[], int n) {

    int max_element = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    for(int position=1; max_element/position > 0; position *= 10) {
        count_sort(arr, n, position);
    }

}

/* Main Function */
int main() {

    // Array
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);

    // Function Call
    radix_sort(arr, n);

    // Print Array
    print_array(arr, n);

    return 0;
}