# httpsleetcode.comproblemsmax-consecutive-ones-iii
# 2021/09
# 644 ms

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        max_L, i1, i2, zeros = 0, 0, 0, 0
        while True:
            if zeros == k and nums[i1] == 0 and i1 == i2:
                i1 += 1
                i2 += 1
            while i2 < len(nums) and zeros < k:
                if nums[i2] == 0:
                    zeros += 1
                i2 += 1
            while i2 < len(nums) and nums[i2] == 1:
                i2 += 1
            max_L = max(max_L, i2 - i1)
            if i2 == len(nums):
                break
            while i1 <= i2 and nums[i1] == 1:
                i1 += 1
            if i1 < i2:
                i1 += 1
                zeros -= 1
        return max_L
