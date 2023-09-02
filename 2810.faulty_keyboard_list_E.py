# https://leetcode.com/problems/faulty-keyboard
# 2023/09
# 48 ms

class Solution:
    def finalString(self, s: str) -> str:
        chars = []
        for i in range(0, len(s)):
            if s[i] == 'i':
                chars = chars[::-1]
            else:
                chars.append(s[i])
        return ''.join(chars)
