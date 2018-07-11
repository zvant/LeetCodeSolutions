'''
https://leetcode.com/problems/generate-parentheses/description/
2016/08
60 ms
'''

class Solution(object):
    def addParenthesis(self, countleft, countright, combine, countunmatch):
        if countleft < 0 or countright < 0 or countunmatch < 0:
            return None
        if 0 == countleft and 0 == countright and 0 == countunmatch:
            self.parentheses.append(''.join(combine))
            return None
        self.addParenthesis(countleft - 1, countright, combine + ['('], countunmatch + 1)
        self.addParenthesis(countleft, countright - 1, combine + [')'], countunmatch - 1)
        
    def generateParenthesis(self, n):
        self.parentheses = []
        self.addParenthesis(n, n, [], 0)
        return self.parentheses
