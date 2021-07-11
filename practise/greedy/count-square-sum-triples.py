"""
A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

Source - https://leetcode.com/problems/count-square-sum-triples/
"""

"""
Time Complexity - O(n^2)
Space Complexity - O(1)
"""

class Solution:
    def countTriples(self, n: int) -> int:
        # Counetr to hold result
        res = 0
        # Iterate over integers in range [1,n] - fixing value for 'a'
        for a in range(1,n+1):
            # Iterate over integers in range [1,n] - fixing value for 'b'
            for b in range(1, n+1):
                # Find value of c using 'a' and 'b'
                c = (a*a + b*b) ** 0.5
                # Check if c is a square root of an integer less than 'n'
                if c <= n and int(c) == c:
                    # If holds a valid value then increment result counter
                    res += 1
        # Return result
        return res
