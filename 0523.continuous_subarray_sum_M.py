'''
https://leetcode.com/problems/continuous-subarray-sum/
2021/10
904 ms
'''

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        summ, remainders = 0, {0: -1}
        for i in range(0, len(nums)):
            summ = (summ + nums[i]) % k
            if summ in remainders:
                if i - remainders[summ] > 1:
                    return True
            else:
                remainders[summ] = i
        return False
