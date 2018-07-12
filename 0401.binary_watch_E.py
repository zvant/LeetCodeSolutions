'''
https://leetcode.com/problems/binary-watch/description/
2016/10
58 ms
'''

class Solution(object):
    def __init__(self):
        self.hour_bits = [1, 2, 4, 8]
        self.minute_bits = [1, 2, 4, 8, 16, 32]
        
    def readBinaryWatch(self, num):
        result = []
        for hr_count in range(0, num + 1):
            if hr_count > len(self.hour_bits) or num - hr_count > len(self.minute_bits):
                continue
            if hr_count < 1:
                hours = [0]
            else:
                hours = map(sum, itertools.combinations(self.hour_bits, hr_count))
            if num - hr_count < 1:
                minutes = [0]
            else:
                minutes = map(sum, itertools.combinations(self.minute_bits, num - hr_count))
            for hr in hours:
                if hr < 12:
                    for mnt in minutes:
                        if mnt < 60:
                            result.append('%d:%02d' % (hr, mnt))
        return result
