"""
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Source - https://leetcode.com/problems/product-of-array-except-self/submissions/
"""

"""
Time Complexity - O(n)
Space Complexity - O(1)
"""

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        # array to store resultant array
        res = [None] * n
        # Calculate prefix products
        prefixProd = 1
        for i in range(n):
            res[i] = prefixProd
            prefixProd *= nums[i]
        # Multiply res with suffix products
        suffixProd = 1
        for i in range(n-1,-1,-1):
            res[i] *= suffixProd
            suffixProd *= nums[i]
        # Return res
        return res
