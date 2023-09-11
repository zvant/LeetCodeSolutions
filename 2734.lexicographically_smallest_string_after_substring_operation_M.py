# https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/
# 2023/09
# 156 ms

class Solution:
    def smallestString(self, s: str) -> str:
        L = len(s)
        i1 = 0
        while i1 < L and s[i1] == 'a':
            i1 += 1 # first non-'a' index
        if i1 == L:
            return s[:-1] + 'z'
        i2 = i1 + 1
        while i2 < L and s[i2] != 'a':
            i2 += 1 # after i1, first 'a' index
        return s[:i1] + ''.join([chr(ord(c) - 1) for c in s[i1 : i2]]) + s[i2:]
