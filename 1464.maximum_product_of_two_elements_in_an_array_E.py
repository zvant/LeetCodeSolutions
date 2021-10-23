# https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
# 2020/10
# 44 ms

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        i = 0
        for idx in range(0, len(nums)):
            if nums[idx] > nums[i]:
                i = idx
        nums[i], nums[0] = nums[0], nums[i]
        j = 1
        for idx in range(1, len(nums)):
            if nums[idx] > nums[j]:
                j = idx
        return (nums[0] - 1) * (nums[j] - 1)
