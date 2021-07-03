"""
Given a string s, return the first non-repeating character in it and return its index. If it does not exist, return -1.

Source - https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
"""

# Storing frquency counts in defaultdict
# Two O(n) runs on string 's'

from collections import defaultdict

class Solution:
    def default(self) -> int:
        return 0
    
    def firstUniqChar(self, s: str) -> int:
        freqCounts = defaultdict(self.default)
        for char in s:
            freqCounts[char] += 1
        i = 0
        for char in s:
            if freqCounts[char] == 1:
                return i
            i += 1
        return -1

# Using Counter to get frequency counts

from collections import Counter

class Solution2:
    def firstUniqChar(self, s: str) -> int:
        freqCounts = Counter(s)
        for index, char in enumerate(s):
            if freqCounts[char] == 1:
                return index
        return -1
