"""
Intersection of two arrays
URL to the problem: https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays/0/?company[]=PayPal&problemType=full&page=1&sortBy=submissions&query=company[]PayPalproblemTypefullpage1sortBysubmissions

Given two arrays A and B respectively of size N and M. The task is to print the count of elements in the intersection (or common elements) of the two arrays.
For this question, intersection of two arrays can be defined as the set containing distinct common elements between the two arrays.
"""

def solution(arr1, arr2, n, m):
    set1 = set()
    set2 = set()
    for i in arr1:
        set1.add(i)
    for i in arr2:
        set2.add(i)
    return len(set1.intersection(set2))

if __name__ == '__main__':
    t = int(input())
    while t:
        n, m = list(map(int, input().split()))
        arr1 = list(map(int, input().split()))
        arr2 = list(map(int, input().split()))
        res = solution(arr1, arr2, n, m)
        print(res)
        t -= 1
