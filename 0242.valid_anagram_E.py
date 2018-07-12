'''
https://leetcode.com/problems/valid-anagram/description/
2015/08
112 ms
'''

class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        list_s = []
        list_t = []
        for c in s:
            list_s.append(c)
        for c in t:
            list_t.append(c)
        return ''.join(sorted(list_s)) == ''.join(sorted(list_t))
