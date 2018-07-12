/**
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 * 2017/02
 * 129 ms
 */

class Solution
{
public:
    vector<int> findDuplicates(vector<int> & nums)
    {
        int n = nums.size();
        vector<int> dups;
        for(int idx = 0; idx < n; idx ++)
        {
            int counter = abs(nums[idx]) - 1;
            if(nums[counter] < 0)
            {
                dups.push_back(counter + 1);
            }
            else
            {
                nums[counter] *= -1;
            }
        }
        return dups;
    }
};
