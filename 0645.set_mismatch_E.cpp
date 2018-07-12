/**
 * https://leetcode.com/problems/set-mismatch/description/
 * 2017/08
 * 36 ms
 */

class Solution
{
public:
    vector<int> findErrorNums(vector<int> & nums)
    {
        vector<int> result(2, -1);
        int n = nums.size();
        for(int idx = 0; idx < n; idx ++)
        {
            int hash_idx = abs(nums[idx]) - 1;
            if(nums[hash_idx] < 0)
            {
                result[0] = hash_idx + 1;
            }
            nums[hash_idx] *= -1;
        }
        for(int idx = 0; idx < n; idx ++)
        {
            if(nums[idx] > 0 && (idx + 1) != result[0])
            {
                result[1] = idx + 1;
                break;
            }
        }
        return result;
    }
};
