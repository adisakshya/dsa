/**
 * We define the usage of capitals in a word to be right when one of the following cases holds:
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * Given a string word, return true if the usage of capitals in it is right.
 * 
 * Source - https://leetcode.com/problems/detect-capital/
 * */


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