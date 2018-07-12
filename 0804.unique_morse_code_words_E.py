'''
https://leetcode.com/problems/unique-morse-code-words/description/
2018/07
24 ms
'''

class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        morse = [".-","-...","-.-.","-..",".","..-.","--.",
         "....","..",".---","-.-",".-..","--","-.",
         "---",".--.","--.-",".-.","...","-","..-",
         "...-",".--","-..-","-.--","--.."]
        freqs = {}
        for w in words:
            codes = []
            for c in w:
                codes.append(morse[ord(c) - ord('a')])
            m = ''.join(codes)
            freqs[m] = 1
        return len(freqs)
