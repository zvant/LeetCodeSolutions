# https://leetcode.com/problems/angle-between-hands-of-a-clock/
# 2021/10
# 28 ms

class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        ang_m = minutes * 6
        ang_hour = ((hour % 12) + minutes / 60) * 30
        diff = max(ang_hour, ang_m) - min(ang_hour, ang_m)
        if diff > 180:
            diff = 360 - diff
        return diff
