"""
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Source - https://leetcode.com/problems/find-k-closest-elements/
"""

# Using Binary Search

class Solution:
    # Binary Search to find closest element
    def closestBinarySearch(self, arr, x, n):
        if n == 1:
            return 0
        low = 0
        high = n - 1
        mid = 0
        while low <= high:
            mid = (low+high)//2
            if arr[mid] == x:
                return mid
            elif x < arr[mid]:
                high = mid - 1
            elif x > arr[mid]:
                low = mid + 1
        return low
    
    # Find k closest elements using sliding window technique
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n = len(arr)
        # Base Cases
        if x < arr[0]:
            return arr[:k] 
        if x > arr[-1]:
            return arr[n-k:]
        if k == n:
            return arr
        # Initialize a sliding window
        pos = self.closestBinarySearch(arr, x, n)
        left  = pos - 1
        right = left + 1
        while (right - left - 1) < k:
            # Check bounds
            if left < 0:
                right += 1
                continue
            if right == n:
                left -= 1
                continue
            # Expand Window
            if abs(arr[left]- x) <= abs(arr[right]-x):
                left -= 1
            else:
                right += 1
        return arr[left+1:right]

# Using bisce_left [FASTER] - https://docs.python.org/3/library/bisect.html

class Solution2:
    # Find k closest elements using sliding window technique
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n = len(arr)
        # Base Cases
        if x < arr[0]:
            return arr[:k] 
        if x > arr[-1]:
            return arr[n-k:]
        if k == n:
            return arr
        # Initialize a sliding window
        pos = bisect_left(arr, x)
        left  = pos - 1
        right = left + 1
        while (right - left - 1) < k:
            # Check bounds
            if left < 0:
                right += 1
                continue
            if right == n:
                left -= 1
                continue
            # Expand Window
            if abs(arr[left]- x) <= abs(arr[right]-x):
                left -= 1
            else:
                right += 1
        return arr[left+1:right]