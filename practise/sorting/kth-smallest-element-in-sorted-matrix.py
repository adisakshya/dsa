"""
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Source - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
"""

"""
Time Complexity - O(n^2)
    - Concatenation using sum() - O(k) - O(n^2) {k = length of concatenated list}
    - Sorting - O(nLogn)
Space Complexity - O(n^2)
    - To store flattend matrix
"""

# Brute Force

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        return sorted(sum(matrix, list()))[k-1]

"""
Time Complexity - O(nLogn)
Space Complexity - O(n)
    - To store intermediate array containing possible positions of mid in each row of matrix
"""

# Using binary search - FASTER

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        # Mark smallest and largest elements in the matrix
        smallest, largest = matrix[0][0], matrix[-1][-1]
        while smallest < largest:
            # Find mid value between smallest and largest
            mid = (smallest + largest)//2
            # If mid value can be inserted at a place after k then mid lies ahead of the k-th smallest element
            if sum(bisect_right(row, mid) for row in matrix) >= k:
                # bring largest element to mid
                largest = mid
            else:
                # If mid value can be inserted at a place before k then mid lies before of the k-th smallest element
                # send smallest element to mid+1
                smallest = mid+1
        # Return the k-th smallest element
        return smallest
