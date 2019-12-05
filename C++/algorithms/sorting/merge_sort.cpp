/**
 * Merge Sort
 * 
 * Sort a sequence of numbers (integers) using insertion sort.
 * 
 * Complexity
 * 
 * Time:
 * 
 * Best:    O(nlogn)
 * Average: O(nlogn)
 * Worst:   O(nlogn)
 * 
 * Space:   O(n)
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

/* Merge */
void merge(int arr[], int l, int r, int m) {
    
    // Size of LHS & RHS Arrays
    int n1 = m - l + 1;
    int n2 = r - m;

    // Auxilary Arrays
    int L[n1], R[n2];

    // Initialize L & R
    for(int i=0; i<n1; i++) {
        L[i] = arr[l + i];
    }

    for(int i=0; i<n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    
}

/* Merge Sort */
void merge_sort(int arr[], int l, int r) {

    if(l>=r) {
        return;
    }

    int mid = l + (r-l)/2;
 
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);

    merge(arr, l, r, mid);

}

/* Main Function */
int main() {

    // Array
    int arr[] = { 40, 20, 30, 10, 50};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Function Call
    int l = 0;
    int r = n;
    merge_sort(arr, l, r);

    // Print Array
    print_array(arr, n);

    return 0;
}