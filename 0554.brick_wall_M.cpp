/**
 * https://leetcode.com/problems/brick-wall/description/
 * 2017/04
 * 43 ms
 */

class Solution
{
public:
    int leastBricks(vector<vector<int>>& wall)
    {
        // int width = accumulate(wall[0].begin(), wall[0].end(), 0);
        // vector<int> num_gaps(width, 0);
        unordered_map<int, int> num_gaps;
        for(auto it = wall.begin(); it != wall.end(); it ++)
        {
            int idx = 0;
            for(auto b_it = it -> begin(); b_it < it -> end() - 1; b_it ++)
            {
                idx += * b_it;
                if(num_gaps.count(idx) < 1)
                {
                    num_gaps[idx] = 0;
                }
                num_gaps[idx] ++;
            }
        }
        int max_gap = 0;
        for(auto it = num_gaps.begin(); it != num_gaps.end(); it ++)
        {
            if(it -> second > max_gap)
            {
                max_gap = it -> second;
            }
        }
        return wall.size() - max_gap;
    }
};
