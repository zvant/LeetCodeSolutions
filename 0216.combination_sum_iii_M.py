'''
https://leetcode.com/problems/combination-sum-iii/description/
2015/08
60 ms
'''

class Solution:
    def combineNext(self, combination, sub_sum, idx, remain):
        if remain <= 0:
            if sub_sum == self.target:
                self.combinations.append(combination)
        else:
            for idx_next in range(idx, self.num_size):
                combination_new = combination[:]
                combination_new.append(self.nums[idx_next])
                self.combineNext(combination_new, sub_sum + self.nums[idx_next], idx_next + 1, remain - 1)
    
    # @param {integer} k
    # @param {integer} n
    # @return {integer[][]}
    def combinationSum3(self, k, n):
        self.combinations = []
        self.nums = range(1, 10)
        self.num_size = 9
        self.target = n
        self.combineNext([], 0, 0, k)
        return self.combinations
