# https://leetcode.com/problems/longest-common-subsequence/
# 2021/10
# 638 ms

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        L1, L2 = len(text1), len(text2)
        dp = [[0] * (L1 + 1) for _ in range(0, L2 + 1)]
        for j in range(0, L2):
            for i in range(0, L1):
                dp[j + 1][i + 1] = max(dp[j][i] + (1 if text1[i] == text2[j] else 0), dp[j][i + 1], dp[j + 1][i])
        return dp[L2][L1]
