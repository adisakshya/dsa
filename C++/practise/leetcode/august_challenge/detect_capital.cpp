/**
 * Problem Name: Detect Capital
 * Problem Url: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/
 * Problem Statement: 
 *      Given a word, you need to judge whether the usage of capitals in it is right or not.
 *      We define the usage of capitals in a word to be right when one of the following cases holds:
 *          1. All letters in this word are capitals, like "USA".
 *          2. All letters in this word are not capitals, like "leetcode".
 *          3. Only the first letter in this word is capital, like "Google".
 *      Otherwise, we define that this word doesn't use capitals in a right way.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool detectCapitalUse(string word) {
            int upperCount = 0,
                lowerCount = 0;
            for(int i=0; i<word.length(); i++) {
                char ch = word[i];
                if(ch >= 'A' && ch <= 'Z') {
                    upperCount++;
                }
                if(ch >= 'a' && ch <= 'z') {
                    lowerCount++;
                }    
            }
            bool case1 = upperCount == word.length() ? true: false;
            bool case2 = lowerCount == word.length() ? true: false;
            bool case3 = upperCount == 1 && lowerCount == word.length()-1 && word[0] >= 'A' && word[0] <= 'Z' ? true: false;
            return case1 || case2 || case3;
        }
};