'''
https://leetcode.com/problems/combination-sum-ii/
2021/11
84 ms
'''

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        results = []
        def combine_1more(i, nums, remainder):
            if remainder < 0:
                return
            if remainder == 0:
                results.append(nums[:])
                return
            checked = set()
            for j in range(i, len(candidates)):
                if candidates[j] in checked:
                    continue
                nums.append(candidates[j])
                combine_1more(j + 1, nums, remainder - candidates[j])
                nums.pop()
                checked.add(candidates[j])
        combine_1more(0, [], target)
        return results
