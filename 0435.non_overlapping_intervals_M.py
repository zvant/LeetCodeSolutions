'''
https://leetcode.com/problems/non-overlapping-intervals/
2021/10
1308 ms
'''

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda i: i[0])
        count, end = 0, intervals[0][0] - 1
        for i in range(0, len(intervals)):
            if intervals[i][0] >= end:
                end = max(end, intervals[i][1])
            else:
                count += 1
                end = min(end, intervals[i][1])
        return count
