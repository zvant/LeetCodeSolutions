/**
 * https://leetcode.com/problems/next-greater-element-i/description/
 * 2017/02
 * 16 ms
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> & findNums, vector<int>& nums)
    {
        int size1 = findNums.size();
        int size2 = nums.size();
        vector<int> result;
        result.resize(size1);
        for(int idx = 0; idx < size1; idx ++)
        {
            int n = findNums[idx];
            int idx2;
            for(idx2 = 0; idx2 < size2; idx2 ++)
            {
                if(n == nums[idx2])
                {
                    break;
                }
            }
            idx2 ++;
            for(; idx2 < size2; idx2 ++)
            {
                if(nums[idx2] > n)
                {
                    break;
                }
            }
            if(idx2 < size2)
            {
                result[idx] = nums[idx2];
            }
            else
            {
                result[idx] = -1;
            }
        }
        return result;
    }
};
