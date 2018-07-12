'''
https://leetcode.com/problems/h-index-ii/description/
2015/09
64 ms
'''

class Solution(object):
    def hIndex(self, citations):
        citations = citations[::-1]
        if len(citations) <= 0 or citations[0] <= 0:
            return 0
        
        h = 1
        while h < len(citations):
            if citations[h] < h:
                break
            else:
                h += 1
        
        if citations[h - 1] < h:
            return h - 1
        else:
            return h
