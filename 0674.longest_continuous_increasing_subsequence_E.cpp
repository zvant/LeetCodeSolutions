/**
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
 * 2018/07
 * 8 ms
 */

class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int size = nums.size();
        if(size < 2)
        {
            return size;
        }
        
        int max_len = 1;
        int idx = 0;
        while(idx + max_len < size)
        {
            int start = idx;
            while(idx + 1 < size && nums[idx] < nums[idx + 1])
            {
                idx ++;
            }
            max_len = max(max_len, idx - start + 1);
            idx ++;
        }
        return max_len;
    }
};
