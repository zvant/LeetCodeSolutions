'''
https://leetcode.com/problems/different-ways-to-add-parentheses/description/
2015/10
100 ms
'''

import re

class Solution(object):
    def computeSubExpr(self, begin, end):
        values = []
        expr = self.expr[begin:end]
        if expr in self.computed:
            values = self.computed[expr]
        else:
            if len(re.split('[\+\-\*]', expr)) <= 2:
                values.append(eval(expr))
            else:
                for split_idx in range(begin, end):
                    if self.expr[split_idx] in '+-*':
                        opnd1s = self.computeSubExpr(begin, split_idx)
                        opnd2s = self.computeSubExpr(split_idx + 1, end)
                        for opnd1 in opnd1s:
                            for opnd2 in opnd2s:
                                values.append(eval(str(opnd1) + self.expr[split_idx] + str(opnd2)))
            self.computed[expr] = values
        
        if begin == 0 and end == len(self.expr):
            self.results = values
        return values
        
    def diffWaysToCompute(self, input):
        self.expr = input
        self.results = []
        self.computed = {}
        self.computeSubExpr(0, len(self.expr))
        return self.results
