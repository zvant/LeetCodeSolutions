# https://leetcode.com/problems/longest-string-chain/
# 2020/05
# 96 ms

class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda w: len(w))
        words_idx = {w: i for i, w in enumerate(words)}
        
        # dp
        length_chain = [1] * (len(words))
        for i in range(1, len(words)):
            w = words[i]
            if len(w) > len(words[0]):
                for j in range(len(w)):
                    pre_w = w[: j] + w[j + 1 :]
                    if pre_w in words_idx:
                        length_chain[i] = max(length_chain[i], length_chain[words_idx[pre_w]] + 1)
        
        return max(length_chain)
