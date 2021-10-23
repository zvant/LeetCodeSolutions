# https://leetcode.com/problems/maximum-performance-of-a-team/
# 2020/10
# 128 ms

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack, unpaired = [], 0
        for c in s:
            if c == '(':
                unpaired += 1
                stack.append(c)
            elif c == ')':
                if unpaired > 0:
                    unpaired -= 1
                    stack.append(c)
            else:
                stack.append(c)
        if unpaired == 0:
            return ''.join(stack)
        
        stack_reserve = stack[::-1]
        stack, unpaired = [], 0
        for c in stack_reserve:
            if c == ')':
                unpaired += 1
                stack.append(c)
            elif c == '(':
                if unpaired > 0:
                    unpaired -= 1
                    stack.append(c)
            else:
                stack.append(c)
        return ''.join(stack[::-1])
