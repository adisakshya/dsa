"""
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
A palindrome is a string that reads the same forwards and backwards.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".

Source - https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
"""

"""
Time Compelxity - O(26*n)
Space Complexity - O(n)
    - 'n' in case when first and last element of input string form a palindrome
"""

class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        # Counter to hold result
        res = 0
        # Iterate over all english alphabets (lowercase)
        for char in ascii_lowercase:
            # If alphabet is in input string
            if char in s:
                # Obtain sub-string which begin and end with the alphabet
                # First and last occurence of alphabet are used to obtain the sub-string
                # Only unique charaters are considered while building the palindromic sub-string
                palSubStr = set(s[s.index(char)+1:s.rindex(char)])
                # Add length of the set - number of palindromic sub-strings that can be formed with
                # alphabet at start and end
                res += len(palSubStr)
        # Return res
        return res
