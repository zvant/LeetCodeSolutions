# https://leetcode.com/problems/kth-missing-positive-number/
# 2021/10
# 52 ms

class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        arr.insert(0, 0)
        count = 0
        for i in range(0, len(arr) - 1):
            count += arr[i + 1] - arr[i] - 1
            if count >= k:
                return arr[i + 1] - (count - k + 1)
        return arr[-1] + k - count
