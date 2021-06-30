/**
 * Problem Name: Missing Number
 * Problem Url: https://leetcode.com/problems/missing-number/
 * Problem Statement: 
 *      Given an array containing n distinct numbers taken from 0, 1, 2, ..., n.
 *      find the one that is missing from the array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int expectedSum = ((nums.size())*(nums.size()+1))/2;
        return expectedSum - sum;
    }
};