'''
https://leetcode.com/problems/substring-with-concatenation-of-all-words/
2021/11
1884 ms
'''

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        N, L = len(words), len(words[0])
        if len(s) < N * L:
            return []
        word_hashes, word_counts = {}, {}
        for i in range(0, len(words)):
            w = words[i]
            key = sum(map(ord, w))
            if not key in word_hashes:
                word_hashes[key] = set()
            word_hashes[key].add(w)
            if w not in word_counts:
                word_counts[w] = 0
            word_counts[w] += 1
        
        asciis = list(map(ord, s))
        segment_hashes = [sum(asciis[: L])]
        for i in range(1, len(s) - L + 1):
            key = segment_hashes[-1] - asciis[i - 1] + asciis[i + L - 1]
            segment_hashes.append(key)
        
        def word_hit(matches, key, w):
            if not key in word_hashes:
                return False
            hit = False
            if w in word_hashes[key]:
                matches[w] -= 1
                hit = True
                if matches[w] < 0:
                    return False
            return hit

        indices = []
        for i in range(0, len(s) - N * L + 1):
            matches, all_match = copy.deepcopy(word_counts), True
            for j in range(0, N):
                if not all_match:
                    break
                idx = i + j * L
                key = segment_hashes[idx]
                w = s[idx : idx + L]
                if not word_hit(matches, key, w):
                    all_match = False
                    break
            if all_match:
                indices.append(i)
        return indices
