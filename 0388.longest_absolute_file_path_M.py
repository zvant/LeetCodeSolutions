'''
https://leetcode.com/problems/longest-absolute-file-path/description/
2016/09
52 ms
'''

class Solution(object):
    def lengthLongestPath(self, input):
        tree = input.split('\n')
        length = []
        max_len = 0
        for file in tree:
            level = file.count('\t')
            file_len = len(file) - level
            length = length[0:level]
            length.append(file_len)
            if file.count('.') > 0:
                max_len = max(sum(length) + len(length) - 1, max_len)
        return max_len
