/**
 * https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
 * 2018/07
 * 4 ms
 */

class Solution
{
public:
    int dominantIndex(vector<int> & nums)
    {
        int size = nums.size();
        if(size < 2)
        {
            return 0;
        }
        int max_n = -2;
        int max2_n = -1;
        int max_idx;
        for(int idx = 0; idx < size; idx ++)
        {
            const int & n = nums[idx];
            if(n > max_n)
            {
                max2_n = max_n;
                max_n = n;
                max_idx = idx;
            }
            else
            {
                if(n > max2_n)
                {
                    max2_n = n;
                }
            }
        }
        if(max2_n * 2 <= max_n)
        {
            return max_idx;
        }
        else
        {
            return -1;
        }
    }
};
