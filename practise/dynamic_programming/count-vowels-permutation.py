"""
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Source - https://leetcode.com/problems/count-vowels-permutation/
"""

"""
Time Complexity - O(n)
Space Complexity - O(n)
"""

class Solution:
    def countVowelPermutation(self, n: int) -> int:
        # DP table of size (n x number_of_vowels) => (n x 5)
        # dp[i][j] represent number of strings of length 'i' starting from vowel 'j' 
        dp = [[0] * 5 for i in range(n)]
        # Base case => n = 1
        # All vowels  contribute one string of length 1
        for vowel in range(5):
            dp[0][vowel] = 1
        # Fill DP table
        for i in range(1, n):
            # Vowel A
            dp[i][0] = dp[i-1][1]
            # Vowel E
            dp[i][1] = dp[i-1][0] + dp[i-1][2]
            # Vowel I
            dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]
            # Vowel O
            dp[i][3] = dp[i-1][2] + dp[i-1][4]
            # Vowel U
            dp[i][4] = dp[i-1][0]
        # Compute result
        res = 0
        for vowel in range(5):
            res += dp[n-1][vowel]
        # Return result
        return (res % (10**9 + 7))
