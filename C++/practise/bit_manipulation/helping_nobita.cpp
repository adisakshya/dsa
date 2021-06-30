/**
 * Problem Name: Help Nobita
 * Problem Url: https://practice.geeksforgeeks.org/problems/help-nobita/0
 * Problem Statement: 
 *      Nobita has his exam on the way and he is trying really hard to clear the examinations this time.
 *      So, he is practicing quite often. One day while practicing he faces a problem.
 *      The problem is as follows: 
 *      Given a string S of lowercase characters, 
 *      find out whether the summation of 'X' and 'Y' is even or odd, 
 *      where X is the count of characters which occupy even positions in english alphabets and have even frequency, 
 *      and Y is the count of characters which occupy odd positions in english alphabets and have odd frequency. 
 *      Help Nobita to solve this problem. 
*/

#include<bits/stdc++.h>
using namespace std;

const string alphabets = "abcdefghijklmnopqrstuvwxyz";

/**
 * Time Comlexity: O(n), where n is length of input string
 * Space Complexity: O(1)
*/
string checkEvenOddString(string input) {
    // Variables to hold X and Y
    int x = 0, 
        y = 0;
    // Map to hold frequency of english alphabets
    map<char, int> freq;
    // Set frequency
    for(int i=0; i<input.length(); i++) {
        if(freq[input[i]]) {
            freq[input[i]]++;
        } else {
            freq[input[i]] = 1;
        }
    }
    // Set X and Y
    for(map<char, int>::iterator i=freq.begin(); i!=freq.end(); ++i) {  
       const char alphabet = (*i).first;
       const int alphabetFreq =  (*i).second;
       // Get alphabet position in english alphabets
       const int charPosInEnglishAlphabets = alphabets.find(alphabet) + 1;
       if(charPosInEnglishAlphabets&1) {
            // Odd position
            if(alphabetFreq&1) {
                // Odd frequency
                y += 1;
            }
        } else {
            // Even position
            if(!(alphabetFreq&1)) {
                // Even frequency
                x += 1;
            }
        }
    }
    // Return response
    if((x+y)&1) {
        return "ODD";
    } else {
        return "EVEN";
    }
}

/**
 * Main
 * 
*/
int main() {
    int t = 0;
    cin >> t;
    while(t--) {
        string input;
        cin >> input;
        cout << checkEvenOddString(input) << '\n';
    }
    return 0;
}