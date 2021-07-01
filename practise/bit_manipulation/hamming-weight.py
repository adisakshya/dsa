"""
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Source - https://leetcode.com/problems/number-of-1-bits/
"""

class Solution:
    def hammingWeight(self, n: int) -> int:
        # Result count
        res = 0
        while n:
            # Check if last bit is set to 1 -> If yes, then increment count
            res += n & 1
            # Remove last bit
            n >>= 1
        # Return result
        return res
