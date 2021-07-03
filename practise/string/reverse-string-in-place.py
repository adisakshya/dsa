"""
Write a function that reverses a string. The input string is given as an array of characters s.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Source - https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
"""


# Two pointer approach

class Solution:
    def reverseString(self, s: List[str]) -> None:
        n = len(s)
        i = 0
        j = n - 1
        while i < j:
            tempChar = s[i]
            s[i] = s[j]
            s[j] = tempChar
            i += 1
            j -= 1


# Using reverse() function

class Solution2:
    def reverseString(self, s: List[str]) -> None:
        s.reverse()
