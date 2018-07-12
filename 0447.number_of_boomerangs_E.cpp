/**
 * https://leetcode.com/problems/number-of-boomerangs/description/
 * 2017/01
 * 1016 ms
 */

class Solution
{
public:
    int numberOfBoomerangs(vector<pair<int, int> > & points)
    {
        size_t n = points.size();
        int * distances = new int[n * n];
        for(int idx1 = 0; idx1 < n - 1; idx1 ++)
        {
            distances[idx1 * n + idx1] = 0;
            for(int idx2 = idx1 + 1; idx2 < n; idx2 ++)
            {
                int x = points[idx1].first - points[idx2].first;
                int y = points[idx1].second - points[idx2].second;
                distances[idx1 * n + idx2] = distances[idx1 + idx2 * n] = x * x + y * y;
            }
        }
        distances[n * n - 1] = 0;
        int count = 0;
        unordered_map<int, int> freq;
        for(int idx1 = 0; idx1 < n; idx1 ++)
        {
            freq.clear();
            for(int idx2 = 0; idx2 < n; idx2 ++)
            {
                int dist = distances[idx1 * n + idx2];
                if(freq.count(dist) > 0)
                {
                    freq[dist] ++;
                }
                else
                {
                    freq[dist] = 1;
                }
            }
            for(auto it = freq.begin(); it != freq.end(); it ++)
            {
                int k = it -> second;
                count += (k - 1) * k;
            }
        }
        delete[] distances;
        return count;
    }
};
