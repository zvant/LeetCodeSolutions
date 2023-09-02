# https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words
# 2023/09
# 51 ms

class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        L = len(words)
        if L != len(s):
            return False
        for i in range(0, L):
            if words[i][0] != s[i]:
                return False
        return True
