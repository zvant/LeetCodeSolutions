# https://leetcode.com/problems/sum-of-matrix-after-queries/
# 2023/09
# 1745 ms

class Solution:
    def matrixSumQueries(self, n: int, queries: List[List[int]]) -> int:
        row_ops, col_ops = {}, {}
        for i, q in enumerate(queries):
            if q[0] == 0:
                row_ops[q[1]] = i
            else:
                col_ops[q[1]] = i
        ops_i = list(row_ops.values())
        ops_i.extend(list(col_ops.values()))
        # foward sequence causes TLE
        # ops_i.sort()
        # row_ops, col_ops = {}, {}
        # for i in ops_i:
        #     t, idx, v = queries[i]
        #     if t == 0:
        #         row_ops[idx] = [n * v, v]
        #         for col in col_ops:
        #             col_ops[col][0] -= col_ops[col][1]
        #     else:
        #         col_ops[idx] = [n * v, v]
        #         for row in row_ops:
        #             row_ops[row][0] -= row_ops[row][1]
        # return sum([row_ops[row][0] for row in row_ops]) + sum([col_ops[col][0] for col in col_ops])
        ops_i.sort(reverse=True)
        row_ops, col_ops, all_sum = 0, 0, 0
        for i in ops_i:
            t, idx, v = queries[i]
            if t == 0:
                all_sum += (n - col_ops) * v
                row_ops += 1
            else:
                all_sum += (n - row_ops) * v
                col_ops += 1
        return all_sum
