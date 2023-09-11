# https://leetcode.com/problems/remove-trailing-zeros-from-a-string/
# 2023/09
# 42 ms

class Solution:
    def removeTrailingZeros(self, num: str) -> str:
        i = len(num) - 1
        while num[i] == '0':
            i -= 1
        return num[: i + 1] 
