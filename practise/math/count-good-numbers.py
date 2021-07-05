"""
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.

Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

Source - 
"""

"""
Time Complexity - O(Logn)
Space Complexity - 1
"""

class Solution:
    def countGoodNumbers(self, n: int) -> int:
        even, odd, s = n//2 + n%2, n//2, 10 ** 9 + 7
        # ((a ^ b) * (c ^ d)) % s = (((a ^ b) % s) * ((c ^ d) % s)) % s
        return (pow(5, even, s) * pow(4, odd, s)) % s
