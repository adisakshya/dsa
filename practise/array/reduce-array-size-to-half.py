"""
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
Return the minimum size of the set so that at least half of the integers of the array are removed.

Source - https://leetcode.com/problems/reduce-array-size-to-the-half/
"""

"""
Time Complexity - O(nLogn)
Space Complexity - O(k)
    - 'k' is the number of unique elements in input array
"""

from collections import Counter

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        l = len(arr)
        freq = Counter(arr)
        freq = list(freq.values())
        freq.sort(reverse=True)
        currL = 0
        res = 0
        for fVlaue in freq:
            currL += fVlaue
            res += 1
            if currL >= l/2:
                break
        return res
