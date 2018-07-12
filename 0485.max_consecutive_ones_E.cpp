/**
 * https://leetcode.com/problems/max-consecutive-ones/description/
 * 2017/02
 * 32 ms
 */

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> & nums)
    {
        int size = nums.size();
        int max = 0;
        int count = 0;
        for(int idx = 0; idx < size; idx ++)
        {
            if(nums[idx] == 1)
            {
                count ++;
            }
            else
            {
                count = 0;
            }
            if(count > max)
            {
                max = count;
            }
        }
        return max;
    }
};
