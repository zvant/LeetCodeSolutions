# https://leetcode.com/problems/maximum-performance-of-a-team/
# 2021/09
# 372 ms

import heapq

class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        engs = list(zip(efficiency, speed))
        engs.sort(reverse=True)
        H, total, speed_sum = [], 0, 0
        for e, s in engs:
            speed_sum += s
            heapq.heappush(H, s)
            if len(H) > k:
                speed_sum -= heapq.heappop(H)
            total = max(total, speed_sum * e)
        return total % (10 ** 9 + 7)
