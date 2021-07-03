"""
Concatenation of Zig-Zag String in n Rows
URL: https://practice.geeksforgeeks.org/problems/concatenation-of-zig-zag-string-in-n-rows/0/

Given a string and number of rows 'n'.
Print the string formed by concatenating n rows when input string is written in row-wise Zig-Zag fashion.
"""

# Time complexity: O(n)
# Space complexity: O(n)
def solution(string, n):
    # Length of input string
    strlen = len(string)
    # If no.of rows = 1 or length-of-string
    # Then result will be the input string itself
    if n == strlen or n == 1:
        return string
    # Auxiliary array of strings
    # row[i] denotes content of i-th row
    row = ["" for _ in range(n+1)]
    # Counter to mark current row
    counter = 1
    # Factor to navigate between rows
    factor = 1
    # Iterate over the string
    for i in range(1, strlen + 1):
        # Get current character
        chr = string[i-1]
        # Add the character to the target row
        row[counter] += chr
        # If current row is the terminal row
        if counter == n:
            # Navigate backwards towards first row
            factor = -1
        # If current row is the first row
        elif counter == 1:
            # Navigate forwards towards terminal row
            factor = 1
        # Set next row
        counter += factor
    # Return response
    return "".join(row)

# Driver code
if __name__ == '__main__':
    # Test-case counter
    t = int(input())
    while t:
        # Input string
        string = input()
        # Number of zig-zag rows
        n = int(input())
        # Find and print solution
        res = solution(string, n)
        print(res)
        # Update current test-case counter
        t -= 1
