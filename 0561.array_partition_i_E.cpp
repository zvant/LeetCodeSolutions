/**
 * https://leetcode.com/problems/array-partition-i/description/
 * 2017/05
 * 82 ms
 */

class Solution
{
public:
    int arrayPairSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int result = 0;
        for(int idx = 0; idx < size; idx += 2)
        {
            result += nums[idx];
        }
        return result;
    }
};
