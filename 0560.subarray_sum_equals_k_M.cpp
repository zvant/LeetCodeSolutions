/**
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 * 2017/05
 * 443 ms
 */

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int count = 0;
        int size = nums.size();
        for(int idx1 = 0; idx1 < size; idx1 ++)
        {
            int sum = 0;
            for(int idx2 = idx1; idx2 < size; idx2 ++)
            {
                sum += nums[idx2];
                if(sum == k)
                {
                    count ++;
                }
            }
        }
        return count;
    }
};
