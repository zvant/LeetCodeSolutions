# https://leetcode.com/problems/minimize-string-length/
# 2023/09
# 71 ms

class Solution:
    def minimizedStringLength(self, s: str) -> int:
        chars, c = set(), '#'
        for i in range(0, len(s)):
            if s[i] != c:
                c = s[i]
                chars.add(c)
        return len(chars)
