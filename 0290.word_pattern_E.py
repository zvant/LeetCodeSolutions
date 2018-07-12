'''
https://leetcode.com/problems/word-pattern/description/
2015/10
52 ms
'''

class Solution(object):
    def wordPattern(self, pattern, str):
        corres = []
        words = str.split(' ')
        if len(pattern) != len(words):
            return False
        
        for idx in range(0, len(pattern)):
            corres.append([pattern[idx], words[idx]])
        corres.sort()
        
        for idx in range(0, len(corres) - 1):
            if corres[idx][0] == corres[idx + 1][0]:
                if corres[idx][1] != corres[idx + 1][1]:
                    return False
            else:
                if corres[idx][1] == corres[idx + 1][1]:
                    return False
        return True
