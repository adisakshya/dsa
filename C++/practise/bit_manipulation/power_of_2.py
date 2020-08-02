"""
Problem Name: Power of 2
Problem Url: https://practice.geeksforgeeks.org/problems/power-of-2/0
Problem Statement: 
    Given a positive integer N. 
    The task is to check if N is a power of 2.
    That is N is 2x for some x.
"""

from math import log

def isPowerOfTwo(n):
    if n == 0:
        return 'NO'
    
    x = log(n)//log(2)
    if pow(2,x) == n:
        return 'YES'
    else:
        return 'NO'

if __name__ == '__main__':
    t = int(input())
    while t:
        t = t - 1
        n = int(input())
        print(isPowerOfTwo(n))