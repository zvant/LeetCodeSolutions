# https://leetcode.com/problems/k-closest-points-to-origin/
# 2020/10
# 640 ms

# quick selection
# average time: O(n) worst time: O(n^2)
class Solution:
    def qpartition(self, dists, low, high):
        curr = low - 1
        pivot = dists[high][0]
        for i in range(low, high):
            if dists[i][0] <= pivot:
                curr += 1
                dists[i], dists[curr] = dists[curr], dists[i]
        
        dists[high], dists[curr + 1] = dists[curr + 1], dists[high]
        return curr + 1
        
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        if len(points) == K:
            return points

        def dist_origin(pt):
            return [pt[0] ** 2 + pt[1] ** 2, pt]
        dists = list(map(dist_origin, points))
        
        low, high = 0, len(dists) - 1
        while True:
            mid = self.qpartition(dists, low, high)
            if mid == K:
                break
            elif mid > K:
                high = mid - 1
            else:
                low = mid + 1
        return list(map(lambda d: d[1], dists[: K]))
