# https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/
# 2023/09
# 182 ms

import copy

class Solution:
    @staticmethod
    def add_count(x, counts):
        if not x in counts:
            counts[x] = 1
        else:
            counts[x] += 1

    @staticmethod
    def minus_count(x, counts):
        if counts[x] <= 1:
            del counts[x]
        else:
            counts[x] -= 1

    def differenceOfDistinctValues(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        answer = copy.deepcopy(grid)
        for row in range(0, m):
            counts_BR, counts_TL = {}, {}
            for i in range(0, min(m - row, n)):
                self.add_count(grid[row + i][i], counts_BR)
            for i in range(0, min(m - row, n)):
                self.minus_count(grid[row + i][i], counts_BR)
                answer[row + i][i] = abs(len(counts_BR) - len(counts_TL))
                self.add_count(grid[row + i][i], counts_TL)
        for col in range(1, n):
            counts_BR, counts_TL = {}, {}
            for i in range(0, min(n - col, m)):
                self.add_count(grid[i][col + i], counts_BR)
            for i in range(0, min(n - col, m)):
                self.minus_count(grid[i][col + i], counts_BR)
                answer[i][col + i] = abs(len(counts_BR) - len(counts_TL))
                self.add_count(grid[i][col + i], counts_TL)
        return answer
