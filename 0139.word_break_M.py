'''
https://leetcode.com/problems/word-break/
2020/06
44 ms
'''

from collections import Counter

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        """
        idea:
        dp[i] = whether first i elements of s is valid
        = OR(s[0:(j+1)] is True and s[j+1 : ] is True, for all j from 0 to i)
        = dp[j] and s[j:i] is True, for all j from 0 to i
        """
        if set(Counter(s).keys()) > set(Counter("".join(wordDict)).keys()):
            return False

        n = len(s)
        wordDict = {w: 0 for w in wordDict}
        
        dp = [False for x in range(n+1)]
        dp[0] = True
        
        for i in range(1, n+1):
            for j in range(i):
                # print(i, j, s[j:i])
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True
                    # print(dp)
                    break
                    
        return dp[n]
