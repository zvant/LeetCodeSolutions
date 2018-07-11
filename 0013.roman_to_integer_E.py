'''
https://leetcode.com/problems/roman-to-integer/description/
2015/08
228 ms
'''

import re

class Solution:
    def romanToInt(self, s):
        segs = [['', 'M', 'MM', 'MMM'], ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'], ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'], ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']]
        
        result = 0
        exp = 3
        begin = 0
        for power in segs:
            for idx in range(1, len(power))[::-1]:
                if s[begin:].startswith(power[idx]):
                    #print power[idx], idx
                    result += (10 ** exp) * idx
                    begin += len(power[idx])
                    break
            exp -= 1
        return result
