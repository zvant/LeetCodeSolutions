'''
https://leetcode.com/problems/combinations/description/
2015/08
76 ms
'''

class Solution:
    def combineNext(self, combination, idx, remain):
        if remain <= 0:
            self.combinations.append(combination)
        else:
            for n in self.nums[idx:]:
                combination_new = combination[:]
                combination_new.append(n)
                self.combineNext(combination_new, n, remain - 1)
    
    # @param {integer} n
    # @param {integer} k
    # @return {integer[][]}
    def combine(self, n, k):
        self.nums = [i for i in range(1, n + 1)]
        self.combinations = []
        self.combineNext([], 0, k)
        return self.combinations
