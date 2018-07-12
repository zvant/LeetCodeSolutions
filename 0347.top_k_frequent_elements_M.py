'''
https://leetcode.com/problems/top-k-frequent-elements/description/
2016/05
80 ms
'''

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freq = {}
        for n in nums:
            if n in freq:
                freq[n] += 1
            else:
                freq[n] = 1
        freq = freq.items()
        freq.sort(key=lambda x : -1 * x[1])
        
        return map(lambda x: x[0], freq[0:k])
