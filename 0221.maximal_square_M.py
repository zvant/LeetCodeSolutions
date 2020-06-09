# https://leetcode.com/problems/maximal-square/
# 2020/05
# 188 ms

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        # check null
        R = len(matrix)
        if R < 1: return 0
        C = len(matrix[0])
        
        # init
        for i in range(0, R):
            matrix[i][0] = int(matrix[i][0])
        for j in range(0, C):
            matrix[0][j] = int(matrix[0][j])
        
        # dp
        for i in range(1, R):
            for j in range(1, C):
                if matrix[i][j] == '0':
                    matrix[i][j] = 0
                else:
                    matrix[i][j] = 1 + min(
                        matrix[i][j - 1], matrix[i - 1][j - 1], # X overlap
                        matrix[i - 1][j]  # Y overlap
                    )
        
        return max(map(lambda l: max(l), matrix)) ** 2
