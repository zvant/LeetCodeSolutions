# https://leetcode.com/problems/semi-ordered-permutation/
# 2023/09
# 70 ms

class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        min_idx, max_idx = 0, 0
        for i in range(0, len(nums)):
            if nums[i] == 1:
                min_idx = i
                break
        for i in range(0, len(nums)):
            if nums[i] == len(nums):
                max_idx = i
                break
        r = min_idx + len(nums) - 1 - max_idx
        if max_idx < min_idx:
            r -= 1
        return r
