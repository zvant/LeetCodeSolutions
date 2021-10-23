'''
https://leetcode.com/problems/random-pick-with-weight/
2021/10
382 ms
'''

import random
class Solution:
    def __init__(self, w: List[int]):
        for i in range(1, len(w)):
            w[i] += w[i - 1]
        self.w = w
    def pickIndex(self) -> int:
        R = random.randint(1, self.w[-1])
        low, high = 0, len(self.w) - 1
        while low < high:
            if R <= self.w[low]:
                return low
            if R <= self.w[high] and R > self.w[high - 1]:
                return high
            mid = (low + high) // 2
            if R <= self.w[mid]:
                high = mid
            else:
                low = mid
        return low

# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()