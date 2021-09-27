# https://leetcode.com/problems/knight-dialer/
# 2021/09
# 1004 ms

class Solution:
    def knightDialer(self, N: int) -> int:
        import numpy as np
        adj = np.array([([0] * 10) for _ in range(0, 10)], dtype=np.int64) # connectivity matrix
        for (n1, n2) in [(0, 4), (0, 6), (1, 6), (1, 8), (2, 7), (2, 9), (3, 4), (3, 8), (4, 9), (6, 7)]:
            adj[n1][n2] = adj[n2][n1] = 1
        M = np.identity(10, dtype=np.int64)
        for _ in range(0, N - 1):
            M = np.matmul(M, adj) % (10 ** 9 + 7)
        return np.matmul(M, np.ones(shape=(10, 1), dtype=np.int64)).sum() % (10 ** 9 + 7)

    # def knightDialer(self, N: int) -> int:
    #     adj = [([False] * 10) for _ in range(0, 10)] # connectivity matrix
    #     for (n1, n2) in [(0, 4), (0, 6), (1, 6), (1, 8), (2, 7), (2, 9), (3, 4), (3, 8), (4, 9), (6, 7)]:
    #         adj[n1][n2] = adj[n2][n1] = True
    #     dp = [([0, 1] + [0] * (N - 1)) for _ in range(0, 10)] # dp arrays
    #     for i in range(2, N + 1):
    #         for k in range(0, 10):
    #             for k2 in range(0, 10):
    #                 if adj[k][k2]:
    #                     dp[k][i] += dp[k2][i - 1] % (10 ** 9 + 7)
    #     return sum([dp[k][N] for k in range(0, 10)]) % (10 ** 9 + 7)
