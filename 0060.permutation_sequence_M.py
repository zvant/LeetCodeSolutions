'''
https://leetcode.com/problems/permutation-sequence/description/
2015/08
60 ms
'''

class Solution:
    # @param {integer} n
    # @return {integer}
    def factorial(self, n):
        if n <= 1:
            return 1
        else:
            return self.factorial(n - 1) * n
    
    # @param {integer} n
    # @param {integer} k
    # @return {string}
    def getPermutation(self, n, k):
        permutation = []
        k -= 1
        nums = [i for i in range(1, n + 1)]
        m = n - 1
        while len(nums) >= 2:
            idx = k / self.factorial(m)
            permutation.append(str(nums[idx]))
            del nums[idx]
            k = k % self.factorial(m)
            m -= 1
        
        permutation.append(str(nums[0]))
        return ''.join(permutation)
