"""
Find duplicates in an array

Given an array a[] of size N which contains elements from 0 to N-1,
you need to find all the elements occurring more than once in the given array.
Complete the function duplicates() which takes array a[] and n as input as parameters and returns a list of elements that occur more than once in the given array in sorted manner. If no such element is found return -1. 

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
Note : The extra space is only for the array to be returned.
Try and perform all operation withing the provided array. 

Constraints:
1 <= N <= 105
0 <= A[i] <= N-1, for each valid i
"""

def duplicates(arr, n): 
	freq = dict()
	res = list()
	for i in range(n):
	    if arr[i] in freq.keys():
	        freq[arr[i]] += 1
	    else:
	        freq[arr[i]] = 1
	for key in freq.keys():
	    if freq[key] > 1:
	        res.append(key)
	res.sort()
	if len(res):
	    return res
	else:
	    return [-1]
