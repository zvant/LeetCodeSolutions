# https://leetcode.com/problems/sliding-window-maximum/
# 2021/10
# 2149 ms

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k <= 1:
            return nums
        from collections import deque
        results, Q = [], deque([0], maxlen=k)
        for i in range(1, len(nums)):
            if Q[-1] + k <= i:
                Q.pop()
            while len(Q) > 0 and nums[Q[0]] <= nums[i]:
                Q.popleft()
            Q.appendleft(i)
            if i >= k - 1:
                results.append(nums[Q[-1]])
        return results
