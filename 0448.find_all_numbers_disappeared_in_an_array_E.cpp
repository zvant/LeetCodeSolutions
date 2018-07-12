/**
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 * 2017/01
 * 146 ms
 */

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> & nums)
    {
        vector<int> disappeared;
        int size = nums.size();
        for(int idx = 0; idx < nums.size(); idx ++)
        {
            int n = abs(nums[idx]) - 1;
            nums[n] = -abs(nums[n]);
        }
        for(int idx = 0; idx < size; idx ++)
        {
            if(nums[idx] > 0)
            {
                disappeared.push_back(idx + 1);
            }
        }
        return disappeared;
    }
};
