# https://leetcode.com/problems/find-the-value-of-the-partition/
# 2023/09
# 423 ms

class Solution:
    def findValueOfPartition(self, nums: List[int]) -> int:
        nums.sort()
        min_dist = nums[1] - nums[0]
        for i in range(2, len(nums)):
            dist = nums[i] - nums[i - 1]
            if dist < min_dist:
                min_dist = dist
        return min_dist
