# https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments
# 2023/09
# 152 ms

class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        asciis1, asciis2 = list(map(ord, str1)), list(map(ord, str2))
        L1, L2 = len(str1), len(str2)
        i1, i2 = 0, 0
        while i1 < L1 and i2 < L2:
            if asciis1[i1] == asciis2[i2]:
                i1, i2 = i1 + 1, i2 + 1
            else:
                if asciis1[i1] + 1 == asciis2[i2] or (str1[i1] == 'z' and str2[i2] == 'a'):
                    i1, i2 = i1 + 1, i2 + 1
                else:
                    i1 = i1 + 1
        return i2 == L2
