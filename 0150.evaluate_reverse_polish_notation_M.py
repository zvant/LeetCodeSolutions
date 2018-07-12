'''
https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
2015/08
248 ms
'''

class Solution:
    # @param {string[]} tokens
    # @return {integer}
    def evalRPN(self, tokens):
        ops = []
        nums = []
        for token in tokens:
            if token in '+-*/':
                n2 = nums.pop()
                n1 = nums.pop()
                result = eval(' '.join([n1, token, n2]))
                nums.append(str(int(float(result))) + '.0')
            else:
                nums.append(token + '.0')
        if len(nums) <= 0:
            return None
        else:
            return int(float(nums.pop()))
