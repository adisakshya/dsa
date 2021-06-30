/**
 * Find Transition Point
 * 
 * You are given a sorted array containing only numbers 0 and 1.
 * Find the transition point efficiently. The transition point is a point where "0" ends and "1" begins (0 based indexing).
 * Note that, if there is no "1" exists, print -1.
 * Note that, in case of all 1s print 0. 
 * The task is to complete the function transitionPoint() that takes array and N as input and returns the value of the position where "0" ends and "1" begins.
 * 
 * Expected Time Complexity: O(logN)
 * Expected Auxiliary Space: O(1)
 * 
 * Constraints:
 * 1 ≤ N ≤ 500000
 * 0 ≤ C[i] ≤ 1
 */

// Function to find the transition point
int transitionPoint(int arr[], int n) {
    int l = 0;
    int r = n-1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(arr[mid] != 1) {
            l = mid + 1;
        } else if(arr[mid] == 1 && arr[mid-1] == 0) {
            return mid;
        } else if(arr[mid] == 1 && arr[mid-1] == 1) {
            r = mid - 1;
        }
    }
    return -1;
}