/**
 * https://leetcode.com/problems/valid-triangle-number/description/
 * 2017/07
 * 738 ms
 */

class Solution
{
public:
    int triangleNumber(vector<int> & nums)
    {
        int size = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        int none_zero_idx = 0;
        while(none_zero_idx < size && 0 == nums[none_zero_idx])
        {
            none_zero_idx ++;
        }
        if(size - none_zero_idx < 3)
        {
            return 0;
        }
        for(int idx1 = none_zero_idx; idx1 < size; idx1 ++)
        {
            for(int idx2 = idx1 + 1; idx2 < size; idx2 ++)
            {
                int min = nums[idx2] - nums[idx1];
                int max = nums[idx1] + nums[idx2];
                int left = 0;
                while(nums[left] <= min)
                {
                    left ++;
                }
                int right = size - 1;
                while(nums[right] >= max)
                {
                    right --;
                }
                count += right - left + 1;
                if(left <= idx1)
                {
                    count --;
                }
                if(right >= idx2)
                {
                    count --;
                }
            }
        }
        return count / 3;
    }
};
