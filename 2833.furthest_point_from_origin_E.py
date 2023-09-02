# https://leetcode.com/problems/furthest-point-from-origin/
# 2023/09
# 41 ms

class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        L, R, U = 0, 0, 0
        for c in moves:
            if c == 'L':
                L += 1
            elif c == 'R':
                R += 1
            else:
                U += 1
        return ((R - L) if R > L else (L - R)) + U
