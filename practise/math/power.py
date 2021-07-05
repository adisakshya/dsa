"""
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

source - https://leetcode.com/problems/powx-n
"""

"""
Time Complexity - O(Logn)
Space Complexity - 1
"""

# Faster
class Solution:
    def myPow(self, x: float, n: int) -> float:
        return pow(x, n)

"""
Time Complexity - O(Logn)
Space Complexity - 1
"""

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1/x
            n = -n
        res = 1
        while n:
            if n & 1:
                res *= x
            n >>= 1
            x *= x
        return res

