'''
https://leetcode.com/problems/intersection-of-two-arrays/description/
2016/07
44 ms
'''

class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        return list(set(nums1).intersection(nums2))
