'''
https://leetcode.com/problems/container-with-most-water/
2021/11
608 ms
'''

class Solution:
    def maxArea(self, height: List[int]) -> int:
        i, j = 0, len(height) - 1
        min_height = min(height[i], height[j])
        max_vol = (j - i) * min_height
        while i < j:
            if height[i] < height[j]:
                while i < j and height[i] <= min_height:
                    i += 1
            else:
                while i < j and height[j] <= min_height:
                    j -= 1
            min_height = min(height[i], height[j])
            max_vol = max(max_vol, (j - i) * min_height)
        return max_vol
