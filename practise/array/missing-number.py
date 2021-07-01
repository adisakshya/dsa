"""
Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.

Required -
Time Complexity - O(N)
Space Complexity - O(1)

Source - https://leetcode.com/problems/missing-number/
"""

# Using sum - Faster
class Solution1:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        return ((n*(n+1)//2) - sum(nums))

# Double XOR - Slower
class Solution2:
    def missingNumber(self, nums: List[int]) -> int:
        xor = 0
        for i in range(1, len(nums)+1):
            xor ^= i
        for num in nums:
            xor ^= num
        return xor
