/**
 * https://leetcode.com/problems/third-maximum-number/description/
 * 2017/01
 * 6 ms
 */

class Solution
{
public:
    int thirdMax(vector<int> & nums)
    {
        int n = nums.size();
        int count = 1;
        int idx1;
        swap(* (nums.end() - 1), * max_element(nums.begin(), nums.end()));
        for(idx1 = 1; idx1 < n && count < 3; idx1 ++)
        {
            for(int idx2 = 0; idx2 < n - idx1 - 1; idx2 ++)
            {
                if(nums[idx2] > nums[idx2 + 1])
                {
                    swap(nums[idx2], nums[idx2 + 1]);
                }
            }
            if(nums[n - idx1 - 1] != nums[n - idx1])
            {
                count ++;
            }
        }
        return (count >= 3) ? nums[n - idx1] : nums[n - 1];
    }
};
