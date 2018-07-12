/**
 * https://leetcode.com/problems/non-decreasing-array/description/
 * 2017/09
 * 39 ms
 */

class Solution
{
public:
    bool checkPossibility(vector<int>& nums)
    {
        int N = nums.size();
        if(N < 3)
        {
            return true;
        }
        
        int dec_idx, back_idx;
        for(dec_idx = 0; dec_idx < N - 1; dec_idx ++)
        {
            if(nums[dec_idx] > nums[dec_idx + 1])
            {
                break;
            }
        }
        if(dec_idx >= N - 2)
        {
            return true;
        }
        
        for(back_idx = N - 1; back_idx > 0; back_idx --)
        {
            if(nums[back_idx - 1] > nums[back_idx])
            {
                break;
            }
        }
        if(back_idx <= 1)
        {
            return true;
        }
        
        if(dec_idx + 1 != back_idx)
        {
            return false;
        }
        
        if(nums[dec_idx] <= nums[dec_idx + 2] || nums[dec_idx + 1] >= nums[dec_idx - 1])
        {
            return true;
        }
        return false;
    }
};
