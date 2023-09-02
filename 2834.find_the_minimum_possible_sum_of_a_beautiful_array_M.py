# https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array/
# 2023/09
# 37 ms

class Solution:
    def minimumPossibleSum(self, n: int, target: int) -> int:
        if n == 1:
            return 1
        if target <= 2:
            return n * (n + 1) // 2
        if target > n + n - 1:
            return n * (n + 1) // 2
        r = (target + 1) // 2 - 1
        return (n + 1) * n // 2 - (target * r - r * (r + 1) // 2) + n * r + r * (r + 1) // 2
