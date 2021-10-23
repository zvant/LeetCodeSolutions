# https://leetcode.com/problems/interval-list-intersections/
# 2021/10
# 180 ms

class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        L1, L2, i, j, intersecs = firstList, secondList, 0, 0, []
        while i < len(L1) and j < len(L2):
            low, high = max(L1[i][0], L2[j][0]), min(L1[i][1], L2[j][1])
            if low <= high:
                intersecs.append([low, high])
            if L1[i][1] > L2[j][1]:
                j += 1
            elif L1[i][1] < L2[j][1]:
                i += 1
            else:
                i += 1
                j += 1
        return intersecs
