'''
https://leetcode.com/problems/combination-sum/
2020/06
84 ms
'''

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.combos = []
        
        def dfs(current, remainder, index):
            if remainder == 0:
                self.combos.append(current)
                return

            if remainder < 0:
                return

            for i in range(index, len(candidates)):
                dfs(current + [candidates[i]], remainder - candidates[i], i)
                
        current = []                
        dfs(current, target, 0)

        return self.combos
