"""
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Source - https://leetcode.com/problems/longest-common-prefix/
"""

"""
Time Complexity - O(k*n)
    - 'k' is length of smallest string in input array
Space Complexity - O(1)
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        maxLen = 200
        for s in strs:
            if len(s) < maxLen:
                maxLen = len(s)
        res = str()
        for i in range(maxLen):
            c = strs[0][i]
            for s in strs:
                if s[i] != c:
                    return res
            res += c
        return res

# Brute Force

class Solution2:
    def matchScore(self, s1, s2):
        n = min(len(s1), len(s2))
        res = str()
        for i in range(n):
            if s1[i] == s2[i]:
                res += s1[i]
            else:
                break
        return res
    
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        commonPrefix = strs[0]
        for i in range(n-1):
            commonPrefix = self.matchScore(commonPrefix, strs[i+1])
        return commonPrefix
