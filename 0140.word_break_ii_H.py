'''
https://leetcode.com/problems/word-break-ii/
2020/06
40 ms
'''

from collections import Counter

# DP
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        if set(Counter(s).keys()) > set(Counter("".join(wordDict)).keys()):
            return []

        n = len(s)
        wordDict = set(wordDict)
        
        dp = {x: [] for x in range(n+1)}
        dp[0].append([''])
        
        for i in range(1, n+1):
            for j in range(i):
                if len(dp[j]) > 0 and s[j:i] in wordDict:
                    for l in dp[j]:
                        dp[i].append(l + [s[j:i]])
                    # break
        
        results = []
        for l in dp[n]:
            results.append(' '.join(l[1:]))
        return results

# DFS
class Solution:
    def breakMore(self, broken, idx):
        if idx >= len(self.s):
            self.sentences.append(broken[1:])
        else:
            for shift in range(idx + 1, len(self.s) + 1):
                w = self.s[idx : shift]
                # print(w)
                if w in self.words:
                    self.breakMore(broken + ' ' + w, shift)

    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        if set(Counter(s).keys()) > set(Counter("".join(wordDict)).keys()):
            return []
        
        self.s, self.words = s, set(wordDict)
        self.sentences = []
        self.breakMore('', 0)
        return self.sentences
