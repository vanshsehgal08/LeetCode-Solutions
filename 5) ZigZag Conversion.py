'''
6. Zigzag Conversion
Medium
5.9K
11.9K
Companies
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
'''

class Solution:
    def convert(self, s, numRows):
        i,diagonal = 0, False
        d = {j:'' for j in range(0, numRows)}
        while i<len(s):
            # linear part: from top row to bottom
            if diagonal == False:
                for j in range(0, numRows):
                    d[j] += s[i]
                    i += 1
                    if i>=len(s):
                        break
            # diagonal part: from bottom row to top, skipping first and last rows
            else:
                for j in range(numRows-1, -1, -1):
                    if j==0 or j==(numRows-1):
                        continue
                    else:
                        d[j] += s[i]
                        i += 1
                    if i>=len(s):
                        break
            diagonal = not diagonal
        return ''.join(d[j] for j in range(0, numRows))
