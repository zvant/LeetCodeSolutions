'''
https://leetcode.com/problems/integer-to-roman/description/
2015/08
132 ms
'''

class Solution:
    # @param {integer} num
    # @return {string}
    def intToRoman(self, num):
        if num < 1 or num > 3999:
            return None
        
        segs = [['', 'M', 'MM', 'MMM'], ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'], ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'], ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']]
        
        result_segs = []
        for power in range(0, 4)[::-1]:
            result_segs.append(segs[3 - power][num / (10 ** power)])
            num = num % (10 ** power)
        return ''.join(result_segs)
