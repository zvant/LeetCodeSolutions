'''
https://leetcode.com/problems/count-and-say/description/
2015/10
48 ms
'''

class Solution(object):
    def countAndSay(self, n):
        result = '1'
        count = 1
        while count < n:
            segs = []
            begin = 0
            while begin < len(result):
                end = begin + 1
                while end < len(result) and result[end] == result[begin]:
                    end += 1
                segs.append(str(end - begin))
                segs.append(result[begin])
                begin = end
            
            result = ''.join(segs)
            count += 1
        
        return result
