"""
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Source - https://leetcode.com/problems/maximum-subarray/
"""

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # Assume global maximum sum is offered by first element
        # also assume current maximum sum is also being offered by first element
        maxSum = currSum = nums[0]
        # For every element in array
        for i in range(1, len(nums)):
            # Check if nums[i] is greater than the sum of it with previous sum, if yes then consider nums[i] to provide current maximum sum
            currSum = max(nums[i], currSum + nums[i])
            # Check if current maximum sum is greater than global maximum sum
            if currSum > maxSum:
                maxSum = currSum
        # Return result
        return maxSum
