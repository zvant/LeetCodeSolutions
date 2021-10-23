# https://leetcode.com/problems/verifying-an-alien-dictionary/
# 2020/10
# 32 ms

class Solution:
    def compare(self, w1, w2, order):
        for i in range(0, min(len(w1), len(w2))):
            diff = order.find(w1[i]) - order.find(w2[i])
            if diff != 0:
                return diff
        return len(w1) - len(w2)

    def isAlienSorted(self, words: List[str], order: str) -> bool:
        for i in range(0, len(words) - 1):
            if self.compare(words[i], words[i + 1], order) > 0:
                return False
        return True
