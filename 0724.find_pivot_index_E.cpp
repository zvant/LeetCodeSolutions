/**
 * https://leetcode.com/problems/find-pivot-index/description/
 * 2018/07
 * 24 ms
 */

class Solution
{
public:
    int pivotIndex(vector<int> & nums)
    {
        int size = nums.size();
        if(size < 1)
        {
            return -1;
        }
        if(size < 2)
        {
            return 0;
        }

        int sum_all = 0;
        for(int idx = 0; idx < size; idx ++)
        {
            sum_all += nums[idx];
        }
        int sum_left = 0;
        for(int idx = 0; idx < size; idx ++)
        {
            if((sum_all - sum_left - nums[idx]) == sum_left)
            {
                return idx;
            }
            sum_left += nums[idx];
        }
        return -1;
    }
};
