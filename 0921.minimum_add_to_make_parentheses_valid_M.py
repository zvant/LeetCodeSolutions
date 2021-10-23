# https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
# 2021/10
# 24 ms

class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        unpaired, added = 0, 0
        for c in s:
            if c == '(':
                unpaired += 1
            else:
                if unpaired < 1:
                    added += 1
                else:
                    unpaired -= 1
        return unpaired + added
