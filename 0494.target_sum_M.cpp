/**
 * https://leetcode.com/problems/target-sum/
 * 2018/12
 * 752 ms
 */

class Solution
{
private:
    void checkSum(vector<int> & nums, int sum, int index, int target, int & count)
    {
        if(index >= nums.size())
        {
            if(target == sum)
            {
                count ++;
            }
        }
        else
        {
            checkSum(nums, sum - nums[index], index + 1, target, count);
            checkSum(nums, sum + nums[index], index + 1, target, count);
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int count = 0;
        checkSum(nums, 0, 0, S, count);
        return count;
    }
};
