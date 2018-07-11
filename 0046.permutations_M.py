'''
https://leetcode.com/problems/permutations/description/
2015/08
88 ms
'''

class Solution:
    def __init__(self):
        self.permutations = []
    
    def permute_rest(self, nums, permuted):
    # @param {integer[]} nums
    # @param {integer[]} permuted
        if len(nums) <= 0:
            self.permutations.append(permuted)
        
        for idx in range(0, len(nums)):
            permuted_add = permuted[:]
            nums_minus = nums[:]
            
            permuted_add.append(nums_minus[idx])
            del nums_minus[idx]
            self.permute_rest(nums_minus, permuted_add)
    
    def permute(self, nums):
    # @param {integer[]} nums
    # @return {integer[][]}
        self.permute_rest(nums, [])
        return self.permutations
