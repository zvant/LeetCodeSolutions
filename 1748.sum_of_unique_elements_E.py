# https://leetcode.com/problems/sum-of-unique-elements/
# 2021/10
# 32 ms

class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        counts = {}
        for n in nums:
            if not n in counts:
                counts[n] = 1
            else:
                counts[n] += 1
        total = 0
        for n in counts:
            if counts[n] == 1:
                total += n
        return total
