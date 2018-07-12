'''
https://leetcode.com/problems/distribute-candies/description/
2017/05
179 ms
'''

class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        num_candies = len(candies) // 2
        num_kinds = len(set(candies))
        if num_kinds > num_candies:
            return num_candies
        else:
            return num_kinds;
