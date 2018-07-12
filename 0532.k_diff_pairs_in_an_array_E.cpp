/**
 * https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
 * 2017/03
 * 32 ms
 */

class Solution
{
public:
    int findPairs(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        int size = nums.size();
        int idx = 0;
        if(0 == k)
        {
            while(idx < size - 1)
            {
                int idx2 = idx;
                while(idx2 < size && nums[idx] == nums[idx2])
                {
                    idx2 ++;
                }
                if(idx2 > idx + 1)
                {
                    count ++;
                }
                idx = idx2;
            }
            return count;
        }
        
        while(idx < size)
        {
            int target = nums[idx] + k;
            idx ++;
            while(nums[idx] == nums[idx - 1])
            {
                idx ++;
            }
            int idx2 = idx;
            while(idx < size)
            {
                if(nums[idx] < target)
                {
                    idx ++;
                }
                else
                {
                    if(nums[idx] == target)
                    {
                        count ++;
                    }
                    break;
                }
            }
            idx = idx2;
        }
        return count;
    }
};
