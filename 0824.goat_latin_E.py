'''
https://leetcode.com/problems/goat-latin/description/
2018/07
20 ms
'''

class Solution(object):
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        goat_words = []
        word_idx = 0
        orig_words = S.split(' ')
        for w in orig_words:
            word_idx += 1
            if not w[0] in 'aeiouAEIOU':
                w = w[1:len(w)] + w[0]
            w += 'ma' + 'a' * word_idx
            goat_words.append(w)
        return ' '.join(goat_words)
