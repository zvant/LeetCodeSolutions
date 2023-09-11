# https://leetcode.com/problems/buy-two-chocolates/
# 2023/09
# 64 ms

import heapq

class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        heapq.heapify(prices)
        p = heapq.heappop(prices) + heapq.heappop(prices)
        if p <= money:
            return money - p
        else:
            return money
