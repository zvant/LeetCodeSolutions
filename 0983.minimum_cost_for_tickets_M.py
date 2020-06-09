# https://leetcode.com/problems/minimum-cost-for-tickets/
# 2020/05
# 28 ms

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        # init
        N = days[-1] + 1
        year_costs = [0] * N
        for d in days:
            year_costs[d] = 1

        # dp
        for d in range(1, N):
            if year_costs[d] == 0:
                year_costs[d] = year_costs[d - 1]
            else:
                year_costs[d] = min(
                    year_costs[d - 1] + costs[0],
                    year_costs[max(0, d - 7)] + costs[1],
                    year_costs[max(0, d - 30)] + costs[2]
                )
        
        return year_costs[-1]
